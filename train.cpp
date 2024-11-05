#include <bits/stdc++.h>
#include "dataset_splitter.h"
#include "load_stopwords.h"
#include "prior_probability.h"
#include "porter_stemmer.h"
#include "load_classnames.h"
#include "bag_of_words.h"
#include "calculate_likelihood.h"
#include "predict.h"

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    // Loading dataset
    // unordered_map<string,vector<string>> sentiment_data = dataset_splitter<string>("./dataset/combined_sentiment.csv");
    unordered_map<string,vector<string>> sentiment_data = dataset_splitter<string>("./dataset/sentiment labelled sentences/combined_sentiment_data.csv");
    unordered_map<string,vector<string>> emotion_data = dataset_splitter<string>("./dataset/combined_emotion.csv");
    
    cout<<sentiment_data["positive"].size()<<endl;
    cout<<sentiment_data["negative"].size()<<endl;

    // Load Class Names
    vector<string> sentiment_class = load_classes(sentiment_data);
    vector<string> emotion_class = load_classes(emotion_data);

    // Loading all stopwords from dataset
    unordered_map<string,int> stopwords = load_stopwords();

    // Prior Probability of each classes
    unordered_map<string,double> sentiment_pp = calculate_prior_probability(sentiment_data);
    unordered_map<string,double> emotion_pp = calculate_prior_probability(emotion_data);
    
    // Loading Bag of Words and Words & its frequency in each class
    auto result = load_bow_and_class_words(sentiment_data,stopwords);
    unordered_map<string,unordered_map<string,int>> class_words = result.class_words;
    unordered_map<string,int> bag_of_words = result.bag_of_words;

    unordered_map<string,unordered_map<string,double>> likelihoods_sentiment_data = calculate_likelihood(result);

    string test = "are you doing well";
    vector<string> test_words = process_text(test,stopwords);

    unordered_map<string,double> probs = predict(test_words,likelihoods_sentiment_data,sentiment_pp);

    for(auto pb: probs) {
        cout<<pb.first<<": "<<pb.second<<endl;
    }

    return 0;
}