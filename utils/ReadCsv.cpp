#include "ReadCsv.h"

DataTable read_csv_columnwise(const std::string& filename) {
    std::map<std::string, std::vector<double>> data;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    std::vector<std::string> headers;

    // 1. Read header line
    if (!std::getline(file, line)) {
        throw std::runtime_error("Missing header row in CSV file.");
    }

    {
        std::stringstream ss(line);
        std::string col;
        while (std::getline(ss, col, ',')) {
            if (col.empty()) {
                throw std::runtime_error("Empty column name found in header.");
            }
            headers.push_back(col);
            data[col] = {};
        }
    }

    size_t expected_columns = headers.size();
    size_t line_num = 2;

    // 2. Read each data line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        size_t i = 0;

        while (std::getline(ss, cell, ',')) {
            if (i >= expected_columns) {
                throw std::runtime_error("Too many columns at line " + std::to_string(line_num) + ".");
            }

            try {
                double value = std::stod(cell);
                data[headers[i]].push_back(value);
            } catch (...) {
                throw std::runtime_error("Failed to convert to number at line " + std::to_string(line_num) + ": " + cell);
            }

            ++i;
        }

        if (i < expected_columns) {
            throw std::runtime_error("Too few columns at line " + std::to_string(line_num) + ".");
        }

        ++line_num;
    }

    return data;
}