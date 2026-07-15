#include "csv_parser.h"
#include <sstream>
#include <cctype>

std::vector<std::vector<std::string>> CSVParser::parse(const std::string& csv_text) {
    std::vector<std::vector<std::string>> result;
    std::istringstream stream(csv_text);
    std::string line;
    
    while (std::getline(stream, line)) {
        result.push_back(parse_line(line));
    }
    
    return result;
}

std::vector<std::string> CSVParser::parse_line(const std::string& line) {
    std::vector<std::string> fields;
    std::istringstream stream(line);
    std::string field;
    
    // BUG: Simple comma split doesn't handle quoted fields with commas inside
    while (std::getline(stream, field, ',')) {
        fields.push_back(trim_quotes(field));
    }
    
    return fields;
}

std::string CSVParser::trim_quotes(const std::string& field) {
    std::string result = field;
    
    // BUG: Only trims first and last character if both are quotes
    // Doesn't handle escaped quotes like "He said ""Hello"""
    if (result.length() >= 2 && 
        result.front() == '"' && 
        result.back() == '"') {
        result = result.substr(1, result.length() - 2);
    }
    
    return result;
}
