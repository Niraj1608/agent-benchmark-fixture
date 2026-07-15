"""Quantitative trading strategy module."""


def calculate_moving_average(prices, period):
    """
    Calculate simple moving average for a list of prices.
    
    Args:
        prices: List of price values
        period: Number of periods for the moving average
        
    Returns:
        List of moving average values
    """
    if len(prices) < period:
        return []
    
    result = []
    for i in range(len(prices) - period + 1):
        avg = sum(prices[i:i + period]) / period
        result.append(avg)
    return result


def generate_signals(prices, short_period=5, long_period=20):
    """
    Generate trading signals based on moving average crossover.
    
    Args:
        prices: List of price values
        short_period: Period for short-term moving average
        long_period: Period for long-term moving average
        
    Returns:
        List of signal dictionaries with date/index and signal type
    """
    if len(prices) < long_period:
        return []
    
    short_ma = calculate_moving_average(prices, short_period)
    long_ma = calculate_moving_average(prices, long_period)
    
    # Adjust for different MA lengths
    offset = long_period - short_period
    
    signals = []
    prev_signal = None
    
    for i in range(len(long_ma)):
        short_idx = i + offset
        if short_idx < len(short_ma):
            if short_ma[short_idx] > long_ma[i] and (prev_signal is None or prev_signal != 'buy'):
                signals.append({'index': i + offset, 'signal': 'buy'})
                prev_signal = 'buy'
            elif short_ma[short_idx] < long_ma[i] and (prev_signal is None or prev_signal != 'sell'):
                signals.append({'index': i + offset, 'signal': 'sell'})
                prev_signal = 'sell'
    
    return signals


def calculate_returns(prices):
    """Calculate returns from price series."""
    if len(prices) < 2:
        return []
    return [(prices[i] - prices[i-1]) / prices[i-1] for i in range(1, len(prices))]


def calculate_sharpe_ratio(returns, risk_free_rate=0.0):
    """Calculate Sharpe ratio from returns."""
    if not returns:
        return 0.0
    excess_returns = [r - risk_free_rate for r in returns]
    import statistics
    mean_return = statistics.mean(excess_returns)
    std_return = statistics.stdev(excess_returns) if len(excess_returns) > 1 else 0
    return mean_return / std_return if std_return != 0 else 0.0
