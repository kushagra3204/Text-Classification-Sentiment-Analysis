#include "import_libraries.h"
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    auto sentiment_train_data = pipeline("./dataset/sentiment labelled sentences/combined_sentiment_data.csv");
    auto emotion_train_data = pipeline("./dataset/combined_emotion.csv");

    unordered_map<string,int> stopwords = load_stopwords();
    
    string test = "!";
    auto test_data = test_single(test,stopwords,sentiment_train_data);
    cout<<test<<": "<<test_data.first<<" - "<<test_data.second<<endl;

    test_data = test_single(test,stopwords,emotion_train_data);
    cout<<test<<": "<<test_data.first<<" - "<<test_data.second<<endl;


    return 0;
}