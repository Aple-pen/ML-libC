#pragma once
#include "IKNeighbors.h"
#include "ReadCsv.h"

enum WeightType
{
    uniform,
    distance
};
enum AlgorithmType
{
    ball_tree,
    kd_tree,
    brute,
    automatic
};


namespace KNeighbors
{
    class Classifier : public IKNeighbors<Classifier>
    {
    private:
        int n_neighbors;
        WeightType weights;
        AlgorithmType algorithm;

    public:
        Classifier();
        void fit();
        void score();
        void predict();

        void ReadCSV(std::string filename);
        
    };
}
