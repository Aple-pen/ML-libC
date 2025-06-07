#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <stdexcept>

#include "type.h"


DataTable read_csv_columnwise(const std::string& filename);