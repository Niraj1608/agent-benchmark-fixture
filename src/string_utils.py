"""String utility functions for text manipulation."""


def reverse_string(s):
    """Reverse a given string."""
    return s[::-1]


def capitalize_words(s):
    """Capitalize the first letter of each word in a string."""
    return s.title()


def remove_whitespace(s):
    """Remove all whitespace from a string."""
    return ''.join(s.split())


def count_vowels(s):
    """Count the number of vowels in a string."""
    vowels = 'aeiouAEIOU'
    return sum(1 for char in s if char in vowels)


def is_palindrome(s):
    """Check if a string is a palindrome."""
    cleaned = ''.join(c.lower() for c in s if c.isalnum())
    return cleaned == cleaned[::-1]
