#ifndef TEST_H
#define TEST_H

#include "import_libraries.h"
using namespace std;

pair<string,double> test_single(string test,unordered_map<string, int> stopwords, TrainResults train_res) {
    vector<string> test_words = process_text(test,stopwords);

    unordered_map<string,double> probs = calculate_probability(test_words,train_res.likelihoods_data,train_res.pp);

    return predict(probs);
}

vector<pair<string,string>> test_list(vector<pair<string,string>> test_list_data,unordered_map<string, int> stopwords, TrainResults train_res) {
    vector<pair<string,string>> test_res;
    for(auto tld: test_list_data) {
        test_res.push_back({tld.second,test_single(tld.first,stopwords,train_res).first});
    }
    return test_res;
}

vector<pair<string,string>> test_dataset(string path,unordered_map<string, int> stopwords, TrainResults train_res) {
    vector<pair<string,string>> data_list;
    unordered_map<string,vector<string>> data = dataset_splitter<string>(path);
    for(auto d: data) {
        for(auto dl: d.second) {
            data_list.push_back({dl,d.first});
        }
    }
    return test_list(data_list,stopwords,train_res);
}

#endif