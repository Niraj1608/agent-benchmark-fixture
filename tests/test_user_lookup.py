"""Tests for user lookup module."""
import pytest
from src.user_lookup import get_user_by_id, get_user_by_email, search_users


def test_get_user_by_id():
    user = get_user_by_id("1")
    assert user is not None
    assert user['name'] == 'Alice'


def test_get_user_by_email():
    user = get_user_by_email("bob@example.com")
    assert user is not None
    assert user['name'] == 'Bob'


def test_search_users():
    results = search_users("alice")
    assert len(results) >= 1


# Security tests to be added by agent
