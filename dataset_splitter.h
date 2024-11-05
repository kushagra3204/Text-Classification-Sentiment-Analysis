#ifndef DATASET_SPLITTER_H
#define DATASET_SPLITTER_H

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <type_traits>
#include <unordered_map>

using namespace std;

template <typename T>
T convert(const string& str) {
    T value;
    stringstream ss(str);
    ss >> value;
    if (ss.fail()) {
        throw runtime_error("Conversion failed");
    }
    return value;
}

template <>
inline string convert(const string& str) {
    return str;
}

template <typename T>
unordered_map<T,vector<T>> dataset_splitter(T dataset_path) {
    unordered_map<T,vector<T>> main_data;
    ifstream input;
    input.open(dataset_path,ios::in);

    if (!input.is_open()) {
        throw runtime_error("Error: Could not open file");
    }

    string line;

    // ignore header or first line
    getline(input, line);
    
    while (getline(input, line)) {
        stringstream s(line);
        string field;
        vector<T> row_data;

        while (getline(s, field, ',')) {
            row_data.push_back(convert<T>(field));
        }

        string sentence = "";
        for(int i=0;i<row_data.size()-1;i++) {
            sentence += row_data[i];
        }
        main_data[row_data[row_data.size()-1]].push_back(sentence);
        // i++;
    }
    input.close();
    return main_data;
}

#endif