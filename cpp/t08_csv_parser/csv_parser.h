#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <vector>
#include <string>

class CSVParser {
public:
    // Parse a single line of CSV, returning vector of fields
    static std::vector<std::string> parse_line(const std::string& line);
    
    // Parse multiple lines
    static std::vector<std::vector<std::string>> parse(const std::string& csv_text);
    
private:
    static std::string trim_quotes(const std::string& field);
};

#endif // CSV_PARSER_H
