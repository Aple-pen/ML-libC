#include <iostream>
#include <KNeighbors/Classifier.h>

int main(){

    KNeighbors::Classifier classifier;
    classifier.ReadCSV("perch_full.csv");
    
    return 0;
}