#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>
using namespace std;

void preprocess_stop_words(string path, unordered_map<string,int> &stop_words) {
    ifstream input;
    input.open(path,ios::in);

    while(!input.eof()) {
        string word;
        input>>word;
        string temp_word = "";
        for(auto sc: word) {
            if(!ispunct(sc)) {
                temp_word += sc;
            }
        }
        word = temp_word;
        stop_words[word]++;
    }
    input.close();
}

int main() {
    unordered_map<string,int> stopwords;

    string stopwords_dir_path[] = {"../dataset/stopwords/stopwords1.txt","../dataset/stopwords/stopwords2.txt"};
    for(auto dirpath: stopwords_dir_path) {
        preprocess_stop_words(dirpath, stopwords);
    }

    for(auto sc: stopwords) {
        cout<<sc.first<<" "<<sc.second<<endl;
    }
    cout<<stopwords.size()<<endl;

    ofstream output;
    output.open("../dataset/stopwords/stopwords.txt",ios::out);
    for(auto sc: stopwords) {
        output<<sc.first<<"\n";
    }
    output.close();
    return 0;
}