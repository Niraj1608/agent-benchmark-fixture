#include "csv_parser.h"
#include <cassert>
#include <iostream>
#include <string>

void test_simple_csv() {
    auto result = CSVParser::parse_line("a,b,c");
    assert(result.size() == 3);
    assert(result[0] == "a");
    assert(result[1] == "b");
    assert(result[2] == "c");
    std::cout << "test_simple_csv PASSED\n";
}

void test_quoted_fields() {
    auto result = CSVParser::parse_line("\"hello\",\"world\"");
    assert(result.size() == 2);
    assert(result[0] == "hello");
    assert(result[1] == "world");
    std::cout << "test_quoted_fields PASSED\n";
}

void test_comma_in_quoted_field() {
    // This is the key bug - commas inside quoted fields should not split
    auto result = CSVParser::parse_line("\"John, Smith\",\"New York\"");
    assert(result.size() == 2);
    assert(result[0] == "John, Smith");
    assert(result[1] == "New York");
    std::cout << "test_comma_in_quoted_field PASSED\n";
}

void test_escaped_quotes() {
    // Handle escaped double quotes inside quoted fields
    auto result = CSVParser::parse_line("\"He said \"\"Hello\"\"\",\"greeting\"");
    assert(result.size() == 2);
    assert(result[0] == "He said \"Hello\"");
    assert(result[1] == "greeting");
    std::cout << "test_escaped_quotes PASSED\n";
}

void test_mixed_fields() {
    auto result = CSVParser::parse_line("plain,\"has comma, here\",normal");
    assert(result.size() == 3);
    assert(result[0] == "plain");
    assert(result[1] == "has comma, here");
    assert(result[2] == "normal");
    std::cout << "test_mixed_fields PASSED\n";
}

void test_empty_fields() {
    auto result = CSVParser::parse_line(",,\"value\"");
    assert(result.size() == 3);
    assert(result[0] == "");
    assert(result[1] == "");
    assert(result[2] == "value");
    std::cout << "test_empty_fields PASSED\n";
}

int main() {
    test_simple_csv();
    test_quoted_fields();
    test_comma_in_quoted_field();
    test_escaped_quotes();
    test_mixed_fields();
    test_empty_fields();
    
    std::cout << "\nAll tests PASSED!\n";
    return 0;
}
