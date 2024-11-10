#ifndef BAG_OF_WORDS_H
#define BAG_OF_WORDS_H

#include "import_libraries.h"
using namespace std;

// Splits into lowercase & punctuation-free words
vector<string> tokenize_and_clean(const string& sentence) {
    vector<string> words;
    stringstream ss(sentence);
    string word;

    while (getline(ss, word, ' ')) {
        string clean_word = "";
        for (auto ch : word) {
            if (!ispunct(ch)) {
                clean_word += tolower(ch);
            } else {
                string temp = "";
                temp += ch;
                words.push_back(temp);
            }
        }
        words.push_back(clean_word);
    }
    return words;
}

//  Removes stopwords and stems the words using Porter Stemmer
vector<string> filter_and_stem(const vector<string>& words, const unordered_map<string, int>& stopwords) {
    vector<string> filtered_words;
    PorterStemmer stemmer;

    for (auto& word : words) {
        // if (stopwords.find(word) == stopwords.end()) {
            filtered_words.push_back(stemmer.stem(word));
        // }
    }
    return filtered_words;
}

// Updates the class_words and bag_of_words in the Result struct
void update_bag_of_words(BOWResuls& result, const string& class_label, const vector<string>& words) {
    for (const auto& word : words) {
        result.class_words[class_label][word]++;
        result.bag_of_words[word]++;
    }
}

// Loads Bag of word and calculate frequency of words in each class
BOWResuls load_bow_and_class_words(const unordered_map<string, vector<string>>& data, const unordered_map<string, int>& stopwords) {
    BOWResuls result;

    for (const auto& [class_label, sentences] : data) {
        unordered_map<string, int> class_word;
        for (const auto& sentence : sentences) {
            vector<string> words = tokenize_and_clean(sentence);
            words = filter_and_stem(words, stopwords);
            update_bag_of_words(result, class_label, words);
        }
    }

    return result;
}

// For processing individual test sentences to get a cleaned and stemmed word vector
vector<string> process_text(const string& text, const unordered_map<string, int>& stopwords) {
    vector<string> words = tokenize_and_clean(text);
    return filter_and_stem(words, stopwords);
}

#endif