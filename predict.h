#ifndef PREDICT_H
#define PREDICT_H

#include "import_libraries.h"
using namespace std;

pair<string,double> predict(unordered_map<string,double> probs) {
    double max_num = INT_MIN;
    string p_class;
    for(auto pb: probs) {
        if(max_num<pb.second) {
            max_num = pb.second;
            p_class = pb.first;
        }
    }
    return {p_class,max_num};
}

#endif