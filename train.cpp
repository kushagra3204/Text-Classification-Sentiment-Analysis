#include <iostream>
#include "dataset_splitter.h"

int main() {
    vector<vector<string>> sentiment_data = dataset_splitter<string>("./dataset/combined_sentiment.csv");
    vector<vector<string>> emotion_data = dataset_splitter<string>("./dataset/combined_emotion.csv");

    for(auto row: emotion_data) {
        for(auto col: row) {
            cout<<col<<" -> ";
        }
        cout<<"END"<<endl;
    }

    return 0;
}
