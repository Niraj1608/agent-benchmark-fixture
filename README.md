# Agent Benchmark Fixture

This repository contains benchmark tasks for comparing AI coding agents.

## Structure

- `tasks/` - Benchmark task definitions
- `src/` - Sample codebase with intentional issues
- `baseline/` - Baseline commit for task reset

## Tasks

1. **Bug Fix** - T02-bugfix (see tasks/t02-bugfix/)
2. **Tests** - Writing unit tests
3. **Small Feature** - Simple feature implementation
4. **Security Issue** - Security vulnerability fix
5. **Quant Strategy** - Quantitative trading strategy implementation

## Setup

Each agent should:
1. Clone the repository
2. Reset to baseline commit: `git reset --hard <baseline-commit>`
3. Create a feature branch: `artha/t02-bugfix` or `openhands/t02-bugfix`
4. Solve the assigned task
5. Create a PR when complete
