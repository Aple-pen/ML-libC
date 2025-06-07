#include "Classifier.h"

namespace KNeighbors
{

    Classifier::Classifier()
        : n_neighbors(5), weights(WeightType::uniform), algorithm(AlgorithmType::automatic)
    {
        // constructor body (can be empty)
    }

    void Classifier::ReadCSV(std::string filename){
        csvData = read_csv_columnwise(filename);
    }
}
