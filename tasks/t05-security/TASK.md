# Task T05-Security: Fix SQL Injection Vulnerability

## Problem Description

The user lookup function is vulnerable to SQL injection attacks. User input is directly concatenated into SQL queries without proper sanitization.

## Expected Behavior

- User input should be properly sanitized/parameterized
- SQL injection attempts should be blocked
- Function should return None for invalid input

## Current Vulnerable Code

```python
# In src/user_lookup.py
def get_user_by_id(user_id):
    query = f"SELECT * FROM users WHERE id = {user_id}"
    # Vulnerable to SQL injection!
```

## Acceptance Criteria

1. Use parameterized queries instead of string formatting
2. Validate user_id input format
3. Reject malicious input patterns
4. Existing functionality preserved
5. Add security tests

## Priority
Critical

## Labels
security, sql-injection, vulnerability
