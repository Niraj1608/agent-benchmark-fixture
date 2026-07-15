"""Tests for string utilities module."""
import pytest
from src.string_utils import (
    reverse_string, capitalize_words, remove_whitespace,
    count_vowels, is_palindrome
)


def test_reverse_string():
    assert reverse_string("hello") == "olleh"
    assert reverse_string("") == ""
    assert reverse_string("a") == "a"


def test_capitalize_words():
    assert capitalize_words("hello world") == "Hello World"
    assert capitalize_words("") == ""
    assert capitalize_words("python") == "Python"


def test_remove_whitespace():
    assert remove_whitespace("hello world") == "helloworld"
    assert remove_whitespace("  spaced  ") == "spaced"
    assert remove_whitespace("") == ""


# Additional tests to be added by agent
