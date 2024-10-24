#ifndef DATASET_SPLITTER_H
#define DATASET_SPLITTER_H

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <type_traits>

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
vector<vector<T>> dataset_splitter(T dataset_path) {
    vector<vector<T>> main_data;
    ifstream input;
    input.open(dataset_path,ios::in);

    if (!input.is_open()) {
        throw runtime_error("Error: Could not open file");
    }

    string line;
    int i=0;
    while (getline(input, line)) {
        stringstream s(line);
        string field;
        vector<T> row_data;

        while (getline(s, field, ',')) {
            row_data.push_back(convert<T>(field));
        }
        main_data.push_back(row_data);
        i++;
    }
    input.close();
    return main_data;
}

#endif