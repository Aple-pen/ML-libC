#pragma once
#include <map>
#include <vector>
#include <string>

using DataTable = std::map<std::string, std::vector<double>>;

template<typename T>
using Matrix = std::vector<std::vector<T>>;