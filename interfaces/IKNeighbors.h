#pragma once

#include <vector>
#include <map>
#include <string>

#include "type.h"

template<typename KNN>
class IKNeighbors{
    protected : 
        DataTable csvData;
    public : 

        void fit() {static_cast<KNN *>(this)->fit();}
        void score() { static_cast<KNN *>(this)->score();}
        void predict() {static_cast<KNN *>(this)->predict();}
        void ReadCSV(std::string filename) {static_cast<KNN *>(this)->ReadCsv(filename);}
};