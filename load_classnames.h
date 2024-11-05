#ifndef LOAD_CLASSNAMES_H
#define LOAD_CLASSNAMES_H

#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

vector<string> load_classes(unordered_map<string,vector<string>> data) {
    vector<string> classes;
    for(auto sd: data) {
        classes.push_back(sd.first);
    }
    return classes; 
}

#endif