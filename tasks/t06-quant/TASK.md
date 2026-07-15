# Task T06-Quant: Implement Moving Average Crossover Strategy

## Problem Description

Implement a simple moving average crossover trading strategy for the quantitative finance module.

## Expected Behavior

- Calculate short-term and long-term moving averages
- Generate buy/sell signals based on crossover points
- Support configurable lookback periods

## Strategy Logic

- **Buy Signal**: Short MA crosses above Long MA
- **Sell Signal**: Short MA crosses below Long MA

## Acceptance Criteria

1. Implement `calculate_moving_average(prices, period)` function
2. Implement `generate_signals(prices, short_period, long_period)` function
3. Return list of signals: {'date', 'signal': 'buy'|'sell'|'hold'}
4. Handle edge cases (insufficient data)
5. Add unit tests for the strategy

## Priority
Medium

## Labels
quant, trading, strategy
