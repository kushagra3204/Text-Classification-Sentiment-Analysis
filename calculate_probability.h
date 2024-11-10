#ifndef CALCULATE_PROBABILITY_H
#define CALCULATE_PROBABILITY_H

#include "import_libraries.h"
using namespace std;

unordered_map<string,double> calculate_probability(vector<string> test_words, unordered_map<string,unordered_map<string,double>> likelihood_data, unordered_map<string,double> data_pp) {
    unordered_map<string,double> probs;
    double probs_sum = 0;
    for(auto sc: likelihood_data) {
        probs[sc.first] = data_pp[sc.first];
        for(int i=0;i<test_words.size();i++) {
            probs[sc.first] = probs[sc.first]*get_likelihood_data(sc.first,test_words[i]);
        }
        // cout<<sc.first<<": "<<probs[sc.first]<<endl;
        probs_sum += probs[sc.first];
    }
    
    for(auto pb: probs) {
        probs[pb.first] = (pb.second/probs_sum);
        // cout<<pb.first<<": "<<pb.second<<endl;
    }

    return probs;
}

#endif