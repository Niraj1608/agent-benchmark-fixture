"""User lookup module with database query functions."""


# Mock database for demonstration
MOCK_USERS = [
    {'id': 1, 'name': 'Alice', 'email': 'alice@example.com'},
    {'id': 2, 'name': 'Bob', 'email': 'bob@example.com'},
    {'id': 3, 'name': 'Charlie', 'email': 'charlie@example.com'},
]


def get_user_by_id(user_id):
    """
    Get user by ID from the database.
    NOTE: This implementation is vulnerable to SQL injection!
    """
    query = f"SELECT * FROM users WHERE id = {user_id}"
    
    # Simulate database query
    for user in MOCK_USERS:
        if user['id'] == int(user_id):
            return user
    return None


def get_user_by_email(email):
    """
    Get user by email address.
    """
    for user in MOCK_USERS:
        if user['email'] == email:
            return user
    return None


def search_users(query):
    """
    Search users by name or email.
    """
    results = []
    query_lower = query.lower()
    for user in MOCK_USERS:
        if query_lower in user['name'].lower() or query_lower in user['email'].lower():
            results.append(user)
    return results
