#ifndef CALCULATE_LIKELIHOOD_H
#define CALCULATE_LIKELIHOOD_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string,unordered_map<string,double>> likelihood_data;
Result temp_result;

unordered_map<string,unordered_map<string,double>> calculate_likelihood(Result result) {
    // unordered_map<string,unordered_map<string,double>> likelihood_data;
    temp_result = result;
    for(auto sd: result.class_words) {
        unordered_map<string,double> likelihood_class_data;
        for(auto bow: result.bag_of_words) {
            double ans = 0;
            ans = ((double)result.class_words[sd.first][bow.first]+1)/((double)result.class_words.size()+result.bag_of_words.size());
            likelihood_class_data[bow.first] = ans;
        }
        likelihood_data[sd.first] = likelihood_class_data;
    }
    return likelihood_data;
}

double get_likelihood_data(string _class,string word) {
    if(likelihood_data[_class].find(word)==likelihood_data[_class].end()) {
        likelihood_data[_class][word] = (double)1/((double)temp_result.class_words.size()+temp_result.bag_of_words.size());
    }
    return likelihood_data[_class][word];
}

#endif