#ifndef PIPELINE_H
#define PIPELINE_H

#include "import_libraries.h"
using namespace std;

TrainResults pipeline(string dataset_path) {
    TrainResults train_res;

    // Loading dataset
    unordered_map<string,vector<string>> data = dataset_splitter<string>(dataset_path);
    
    for(auto sc: data) {
        cout<<"Total data in "<<sc.first<<": "<<sc.second.size()<<endl;
    }
    cout<<endl;

    // Load Class Names
    train_res.class_ = load_classes(data);
    
    // Loading all stopwords from dataset
    unordered_map<string,int> stopwords = load_stopwords();

    // Prior Probability of each classes
    train_res.pp = calculate_prior_probability(data);
    
    // Loading Bag of Words and Words & its frequency in each class
    auto result = load_bow_and_class_words(data,stopwords);
    unordered_map<string,unordered_map<string,int>> class_words = result.class_words;
    unordered_map<string,int> bag_of_words = result.bag_of_words;

    train_res.likelihoods_data = calculate_likelihood(result);

    return train_res;
}

#endif