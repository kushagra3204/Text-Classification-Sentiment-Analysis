#include "import_libraries.h"
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    auto sentiment_train_data = pipeline("./dataset/sentiment labelled sentences/combined_sentiment_data.csv");
    auto emotion_train_data = pipeline("./dataset/combined_emotion.csv");

    unordered_map<string,int> stopwords = load_stopwords();
    
    string test = "good movie";
    auto test_data = test_single(test,stopwords,sentiment_train_data);
    cout<<test<<": "<<test_data.first<<" - "<<test_data.second<<endl;

    test_data = test_single(test,stopwords,emotion_train_data);
    cout<<test<<": "<<test_data.first<<" - "<<test_data.second<<endl;

    vector<pair<string,string>> test_list_data = test_dataset("./dataset/combined_sentiment.csv",stopwords,sentiment_train_data);
    calculate_performance_metrics(test_list_data,sentiment_train_data.class_);

    // vector<pair<string,string>> emotion_test_data = test_dataset("./dataset/sampled_emotion_test_dataset.csv",stopwords,emotion_train_data);
    // calculate_performance_metrics(emotion_test_data,emotion_train_data.class_);

    return 0;
}