#pragma once

#include "import_libraries.h"
using namespace std;

double accuracy(const PerformanceMetrics& metrics, const vector<string>& classes) {
    int total = 0;
    int correct = 0;
    for (const string& cls : classes) {
        total += metrics.TP.at(cls) + metrics.FP.at(cls) + metrics.FN.at(cls) + metrics.TN.at(cls);
        correct += metrics.TP.at(cls) + metrics.TN.at(cls);
    }
    return (double)correct / total;
}

double precision(const PerformanceMetrics& metrics, const string& cls) {
    if (metrics.TP.at(cls) + metrics.FP.at(cls) == 0) return 0.0;
    return (double)metrics.TP.at(cls) / (metrics.TP.at(cls) + metrics.FP.at(cls));
}

double recall(const PerformanceMetrics& metrics, const string& cls) {
    if (metrics.TP.at(cls) + metrics.FN.at(cls) == 0) return 0.0;
    return (double)metrics.TP.at(cls) / (metrics.TP.at(cls) + metrics.FN.at(cls));
}

void confusion_matrix(const PerformanceMetrics& metrics, const vector<string>& classes) {
    cout << "\nConfusion Matrix:" << endl;
    cout << setw(12) << " ";
    
    for (const string& cls : classes) {
        cout << setw(12+cls.size()) << "Pred " + cls;
    }
    cout << endl;

    for (const string& actual : classes) {
        cout << "Actual " + actual << setw(7);
        
        for (const string& predicted : classes) {
            if (actual == predicted) {
                cout  << metrics.TP.at(actual) << setw(actual.size()+9) << " ";
            } else {
                cout << metrics.FP.at(predicted) << setw(actual.size()+9) << " " ;
            }
        }
        cout << endl;
    }
}



void calculate_performance_metrics(const vector<pair<string, string>>& testlist, const vector<string>& classes) {
    PerformanceMetrics metrics;

    for (const string& cls : classes) {
        metrics.TP[cls] = 0;
        metrics.TN[cls] = 0;
        metrics.FP[cls] = 0;
        metrics.FN[cls] = 0;
    }

    for (const auto& pair : testlist) {
        string actual = pair.first;
        string predicted = pair.second;
        
        for (const string& cls : classes) {
            if (actual == cls && predicted == cls) {
                metrics.TP[cls]++;
            } else if (actual == cls && predicted != cls) {
                metrics.FN[cls]++;
            } else if (actual != cls && predicted == cls) {
                metrics.FP[cls]++;
            } else if (actual != cls && predicted != cls) {
                metrics.TN[cls]++;
            }
        }
    }

    double acc = accuracy(metrics, classes);
    cout << "\n\nAccuracy: " << acc << endl;

    for (const string& cls : classes) {
        double prec = precision(metrics, cls);
        cout << "Precision for class " << cls << ": " << prec << endl;

        double rec = recall(metrics, cls);
        cout << "Recall for class " << cls << ": " << rec << endl;
    }

    confusion_matrix(metrics, classes);
}