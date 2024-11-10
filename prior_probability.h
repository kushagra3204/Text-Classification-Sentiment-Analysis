#ifndef PRIOR_PROBABILITY_H
#define PRIOR_PROBABILITY_H

#include "import_libraries.h"
using namespace std;

unordered_map<string,double> calculate_prior_probability(unordered_map<string,vector<string>> data) {
    unordered_map<string,double> prior_probability;
    double data_size = 0;
    for(auto sd: data) {
        data_size += sd.second.size();
    }

    for(auto sd: data) {
        prior_probability[sd.first] = (double)sd.second.size()/data_size;
    }
    return prior_probability;
}

#endif