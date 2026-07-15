"""Data processor module for handling data transformations."""


def process_data(data):
    """
    Process input data by applying transformations.
    
    Args:
        data: List of dictionaries to process
        
    Returns:
        List of processed dictionaries
    """
    results = []
    for item in data:
        processed = {
            'id': item.get('id'),
            'value': item.get('value', 0) * 2,
            'name': item.get('name', '').upper(),
            'status': 'processed'
        }
        results.append(processed)
    return results


def filter_data(data, filter_key, filter_value):
    """Filter data based on a key-value pair."""
    return [item for item in data if item.get(filter_key) == filter_value]


def aggregate_data(data, key):
    """Aggregate data by summing values for a given key."""
    return sum(item.get(key, 0) for item in data)
