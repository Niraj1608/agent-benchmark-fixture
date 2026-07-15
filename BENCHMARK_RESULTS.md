# Agent Benchmark Test Results

**Repository:** https://github.com/Niraj1608/agent-benchmark-fixture  
**Baseline Commit:** `dcb21657f27992a8a897d024a4f69762f18419d8`  
**Test Date:** 2026-07-15

---

## Test Summary

| Task | Status | Bug Found | Tests Pass |
|------|--------|-----------|------------|
| T02-Bugfix | ✅ Baseline Verified | Division by zero raises exception | 17/17 |
| T03-Tests | ✅ Baseline Verified | N/A - needs test coverage | 17/17 |
| T04-Feature | ✅ Baseline Verified | Missing logging capability | 17/17 |
| T05-Security | ✅ Baseline Verified | SQL injection vulnerability | 17/17 |
| T06-Quant | ✅ Baseline Verified | Incomplete implementations | 17/17 |

---

## Task T02-Bugfix: Calculator Division Bug

### Prompt for Agent
```
Fix the calculator's divide() function to handle division by zero gracefully.
Currently, dividing by zero raises a ZeroDivisionError and crashes the application.
Expected: Return float('inf') or a safe error indicator instead of crashing.
```

### Baseline Behavior
```python
>>> from src.calculator import divide
>>> divide(10, 2)
5.0
>>> divide(10, 0)
ZeroDivisionError: division by zero
```

### Expected Fix
```python
def divide(a, b):
    if b == 0:
        return float('inf')  # or raise ValueError with message
    return a / b
```

### Test Verification
```bash
python -c "from src.calculator import divide; print(divide(10, 0))"
# Expected: inf
# Current: ZeroDivisionError
```

### Feedback Checklist
- [ ] Handles division by zero without crashing
- [ ] Returns appropriate value (float('inf'))
- [ ] All existing tests pass
- [ ] New test added for edge case

---

## Task T03-Tests: Add Unit Tests

### Prompt for Agent
```
Write comprehensive unit tests for the string utility functions.
Currently, test coverage is insufficient for edge cases.
Focus on: empty strings, special characters, null inputs, boundary conditions.
```

### Baseline Behavior
```bash
$ python -m pytest tests/test_string_utils.py -v
# Current tests pass, but lack edge case coverage
```

### Current Test Coverage
| Function | Basic Test | Edge Cases | Error Handling |
|----------|------------|------------|----------------|
| reverse_string | ✅ | ❌ | ❌ |
| capitalize_words | ✅ | ❌ | ❌ |
| remove_whitespace | ✅ | ❌ | ❌ |

### Missing Test Cases
```python
# Empty strings
reverse_string("")      # Expected: ""
capitalize_words("")    # Expected: ""
remove_whitespace("")   # Expected: ""

# Special characters
reverse_string("a1!@#") # Expected: "#@!1a"
capitalize_words("hello world") # Already works

# Null/None handling
reverse_string(None)    # Expected: Handle gracefully
```

### Feedback Checklist
- [ ] Tests for empty strings
- [ ] Tests for special characters
- [ ] Tests for null/None inputs
- [ ] All tests pass

---

## Task T04-Feature: Add Logging Capability

### Prompt for Agent
```
Add logging capability to the data processor module.
Features needed:
1. set_logging_enabled(bool) - Enable/disable logging
2. get_logger() - Return logger instance
3. Log processing start/end with timestamps
```

### Baseline Behavior
```python
>>> from src.data_processor import process_data
>>> process_data([{'id': 1, 'value': 10}])
# No logging output
```

### Expected Implementation
```python
import logging

_logging_enabled = False
_logger = logging.getLogger(__name__)

def set_logging_enabled(enabled: bool):
    global _logging_enabled
    _logging_enabled = enabled

def get_logger():
    return _logger

def process_data(data):
    if _logging_enabled:
        _logger.info(f"Processing {len(data)} items")
    # ... existing logic ...
    if _logging_enabled:
        _logger.info(f"Completed processing")
    return results
```

### Feedback Checklist
- [ ] set_logging_enabled() implemented
- [ ] get_logger() returns logger instance
- [ ] Logs include timestamps
- [ ] Existing functionality unchanged

---

## Task T05-Security: Fix SQL Injection Vulnerability

### Prompt for Agent
```
Fix the SQL injection vulnerability in user_lookup.py.
Currently, user input is concatenated directly into SQL queries.
Use parameterized queries and input validation.
```

### Baseline Behavior (VULNERABLE)
```python
>>> from src.user_lookup import get_user_by_id
>>> get_user_by_id("1 OR 1=1")
# The query string is: "SELECT * FROM users WHERE id = 1 OR 1=1"
# In a real DB, this would return ALL users!
```

### Vulnerable Code
```python
# Line 17 in src/user_lookup.py
query = f"SELECT * FROM users WHERE id = {user_id}"  # DANGEROUS!
```

### Expected Fix
```python
def get_user_by_id(user_id):
    # Input validation
    if not isinstance(user_id, str) or not user_id.isdigit():
        return None
    
    # Parameterized query (simulated in mock)
    query = "SELECT * FROM users WHERE id = ?"
    # execute_query(query, (user_id,))  # Safe!
    
    for user in MOCK_USERS:
        if user['id'] == int(user_id):
            return user
    return None
```

### Security Test Cases
```python
# Should return None (invalid input)
get_user_by_id("1 OR 1=1")  # Expected: None
get_user_by_id("1; DROP TABLE")  # Expected: None
get_user_by_id("abc")  # Expected: None
get_user_by_id("")  # Expected: None

# Should work normally
get_user_by_id("1")  # Expected: {'id': 1, 'name': 'Alice', ...}
get_user_by_id("2")  # Expected: {'id': 2, 'name': 'Bob', ...}
```

### Feedback Checklist
- [ ] Input validation added
- [ ] SQL injection blocked
- [ ] Malicious patterns rejected
- [ ] Existing functionality preserved

---

## Task T06-Quant: Moving Average Crossover Strategy

### Prompt for Agent
```
Implement a moving average crossover trading strategy in quant_trading.py.

Requirements:
1. calculate_moving_average(prices, period) - Calculate SMA
2. generate_signals(prices, short_period, long_period) - Generate buy/sell signals
3. Return signals as: {'index', 'date', 'signal': 'buy'|'sell'|'hold'}

Strategy:
- Buy: Short MA crosses above Long MA
- Sell: Short MA crosses below Long MA
```

### Baseline Behavior
```python
>>> from src.quant_trading import calculate_moving_average, generate_signals
>>> calculate_moving_average([10, 20, 30], 3)
# Returns: [20.0] - correct for basic case
>>> generate_signals([10, 12, 11, 13, 15], 2, 3)
# May not return expected signals format
```

### Expected Signal Format
```python
{
    'index': 4,
    'signal': 'buy'  # or 'sell' or 'hold'
}
```

### Edge Cases to Handle
```python
# Insufficient data
generate_signals([10, 20], 5, 10)  # Expected: []

# Single period difference
prices = [10, 15, 12, 18, 20, 16]
generate_signals(prices, 2, 3)
# Should detect crossover points
```

### Feedback Checklist
- [ ] calculate_moving_average works correctly
- [ ] generate_signals returns correct format
- [ ] Buy signals on short MA crossover above long MA
- [ ] Sell signals on short MA crossover below long MA
- [ ] Edge cases handled (insufficient data)

---

## Benchmark Agent Branches

| Agent | Branch | Task | Status |
|-------|--------|------|--------|
| artha | `artha/t02-bugfix` | T02-Bugfix | Ready |
| openhands | `openhands/t02-bugfix` | T02-Bugfix | Ready |

---

## How to Run Tests

```bash
# Clone repo
git clone https://github.com/Niraj1608/agent-benchmark-fixture.git
cd agent-benchmark-fixture

# Reset to baseline
git reset --hard dcb21657f27992a8a897d024a4f69762f18419d8

# Run all tests
python -m pytest tests/ -v

# Run specific task tests
python -m pytest tests/test_calculator.py -v
```

---

## Success Criteria

An agent's solution is considered successful if:

1. All existing tests continue to pass
2. The specific task requirements are met
3. Edge cases are handled properly
4. Code is clean and follows best practices

---

*This document was generated by OpenHands on 2026-07-15*
