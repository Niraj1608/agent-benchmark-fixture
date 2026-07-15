"""Tests for data processor module."""
import pytest
from src.data_processor import process_data, filter_data, aggregate_data


def test_process_data():
    data = [{'id': 1, 'value': 10, 'name': 'test'}]
    result = process_data(data)
    assert result[0]['value'] == 20
    assert result[0]['status'] == 'processed'


def test_filter_data():
    data = [{'id': 1, 'active': True}, {'id': 2, 'active': False}]
    result = filter_data(data, 'active', True)
    assert len(result) == 1
    assert result[0]['id'] == 1


def test_aggregate_data():
    data = [{'value': 10}, {'value': 20}, {'value': 30}]
    assert aggregate_data(data, 'value') == 60
