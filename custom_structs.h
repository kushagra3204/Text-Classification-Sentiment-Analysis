#pragma once

#include "import_libraries.h"
using namespace std;

struct TrainResults {
    unordered_map<string,unordered_map<string,double>> likelihoods_data;
    unordered_map<string,double> pp;
};

struct BOWResuls {
    // Words in each class and count of it
    unordered_map<string,unordered_map<string,int>> class_words;
    
    // Total Words in bag (Overall Classes)
    unordered_map<string,int> bag_of_words;
};