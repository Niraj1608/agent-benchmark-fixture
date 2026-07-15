#include <bits/stdc++.h>
using namespace std;

struct Triple {
    int u, v, w;
};

struct DSU {
    vector<int> parent, sz, parity;
    int contradictions;
    vector<pair<int, pair<int, int>>> history;

    DSU(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1);
        parity.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            sz[i] = 1;
            parity[i] = 0;
        }
        contradictions = 0;
    }

    pair<int, int> find(int x) {
        if (parent[x] == x) return {x, 0};
        auto [root, p] = find(parent[x]);
        return {root, parity[x] ^ p};
    }

    void unite(int u, int v, int w) {
        auto [ru, pu] = find(u);
        auto [rv, pv] = find(v);

        if (ru == rv) {
            if ((pu ^ pv) != w) {
                contradictions++;
            }
            return;
        }

        if (sz[ru] < sz[rv]) {
            swap(ru, rv);
            swap(pu, pv);
        }

        history.push_back({rv, {parent[rv], sz[rv]}});
        history.push_back({ru, {parent[ru], sz[ru]}});

        parent[rv] = ru;
        sz[ru] += sz[rv];
        parity[rv] = pu ^ pv ^ w;
    }

    void snapshot() {
        history.push_back({-1, {0, contradictions}});
    }

    void rollback() {
        while (!history.empty()) {
            auto [node, state] = history.back();
            history.pop_back();

            if (node == -1) {
                contradictions = state.second;
                return;
            }

            if (state.first != node) {
                parent[node] = state.first;
            }
            sz[node] = state.second;
        }
    }
};

struct SegTree {
    int n;
    vector<vector<Triple>> ops;
    vector<int> answers;
    DSU &dsu;

    SegTree(int n, DSU &dsu) : n(n), dsu(dsu) {
        ops.resize(4 * n);
        answers.resize(n + 1);
    }

    void add(int id, int l, int r, int ql, int qr, int u, int v, int w) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            ops[id].push_back({u, v, w});
            return;
        }
        int mid = (l + r) / 2;
        add(id * 2, l, mid, ql, qr, u, v, w);
        add(id * 2 + 1, mid + 1, r, ql, qr, u, v, w);
    }

    void add_constraint(int l, int r, int u, int v, int w) {
        add(1, 1, n, l, r, u, v, w);
    }

    void query(int id, int l, int r, int qi) {
        dsu.snapshot();

        for (auto &t : ops[id]) {
            dsu.unite(t.u, t.v, t.w);
        }

        if (l == r) {
            answers[l] = dsu.contradictions == 0 ? 1 : 0;
        } else {
            int mid = (l + r) / 2;
            if (qi <= mid) {
                query(id * 2, l, mid, qi);
            } else {
                query(id * 2 + 1, mid + 1, r, qi);
            }
        }

        dsu.rollback();
    }
};

struct Constraint {
    int u, v, w;
    int l, r;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    DSU dsu(n);
    SegTree seg(q, dsu);

    vector<Constraint> constraints;
    constraints.push_back({0, 0, 0, 0, 0});

    vector<int> op_type(q + 1);
    int constraint_id = 0;

    for (int i = 1; i <= q; i++) {
        char type;
        cin >> type;

        if (type == '+') {
            int u, v, w;
            cin >> u >> v >> w;
            constraint_id++;
            constraints.push_back({u, v, w, i, -1});
            op_type[i] = 1;
        } else if (type == '-') {
            int id;
            cin >> id;
            constraints[id].r = i - 1;
            op_type[i] = 2;
        } else if (type == '?') {
            op_type[i] = 3;
        }
    }

    for (int i = 1; i <= constraint_id; i++) {
        if (constraints[i].r == -1) {
            constraints[i].r = q;
        }
        if (constraints[i].l <= constraints[i].r) {
            seg.add_constraint(constraints[i].l, constraints[i].r,
                             constraints[i].u, constraints[i].v, constraints[i].w);
        }
    }

    for (int i = 1; i <= q; i++) {
        if (op_type[i] == 3) {
            seg.query(1, 1, q, i);
        }
    }

    for (int i = 1; i <= q; i++) {
        if (op_type[i] == 3) {
            cout << (seg.answers[i] ? "YES" : "NO") << "\n";
        }
    }

    return 0;
}
