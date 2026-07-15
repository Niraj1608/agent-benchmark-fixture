# Task T02-Bugfix: Fix Calculator Division Bug

## Problem Description

The calculator application has a division function that crashes when dividing by zero. Instead of returning an appropriate error message, it throws an unhandled exception.

## Expected Behavior

- Division by zero should return a safe result (Infinity or a specific error indicator)
- The function should not crash the application
- Division should work correctly for all valid inputs

## Sample Code

```python
# In src/calculator.py
def divide(a, b):
    return a / b  # Crashes on b=0
```

## Acceptance Criteria

1. Function handles division by zero gracefully
2. Returns appropriate value (float('inf') or custom error)
3. All existing tests pass
4. New test added for this edge case

## Priority
Medium

## Labels
bug, division, error-handling
