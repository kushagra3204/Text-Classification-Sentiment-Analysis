#ifndef LOAD_STOPWORDS_H
#define LOAD_STOPWORDS_H

#include <fstream>
#include <unordered_map>
using namespace std;

unordered_map<string,int> load_stopwords() {
    unordered_map<string,int> stopwords;
    ifstream file("./dataset/stopwords/stopwords.txt");

    if (!file.is_open()) {
        throw std::runtime_error("Could not open stopwords file.");
    }

    string word;
    while (file >> word) {
        stopwords[word] = 1;
    }
    return stopwords;
}

#endif