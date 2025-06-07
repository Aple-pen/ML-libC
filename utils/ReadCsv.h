#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <stdexcept>

std::map<std::string, std::vector<double>> read_csv_columnwise(const std::string& filename);