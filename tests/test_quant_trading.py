"""Tests for quantitative trading module."""
import pytest
from src.quant_trading import (
    calculate_moving_average, generate_signals, 
    calculate_returns, calculate_sharpe_ratio
)


def test_calculate_moving_average():
    prices = [10, 20, 30, 40, 50]
    result = calculate_moving_average(prices, 3)
    assert len(result) == 3
    assert result[0] == 20.0  # (10+20+30)/3


def test_generate_signals():
    # Simple test case
    prices = [10, 12, 11, 15, 14, 18, 17, 20, 19, 22]
    signals = generate_signals(prices, short_period=2, long_period=4)
    # Basic validation - signals should be generated
    assert isinstance(signals, list)


def test_calculate_returns():
    prices = [100, 105, 102, 110]
    returns = calculate_returns(prices)
    assert len(returns) == 3
    assert abs(returns[0] - 0.05) < 0.001


# Strategy tests to be added by agent
