#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include "nearestSearch.h"

using namespace std;


void crossValidation(const std::vector<std::vector<int>>& data, int features_to_add)
{

}

void sforwardSelection(const std::vector<int>& labels, const std::vector<std::vector<double>>& features)
{//seaches for the best set of features by combining one feature at a time
    NearestSearch searcher;
    vector<int> current_set; //stores the current set of features
    int num_features = features[0].size();

    for (int level = 0; level < num_features; level++) //for each level of feature combination
    {
        int best_feature = -1;
        double best_accuracy = 0.0;
        for (int feature = 0; feature < num_features; feature++)
        {
            if (find(current_set.begin(), current_set.end(), feature) == current_set.end()) //if feature is not already in the set
            {
                double accuracy = searcher.accuracy(features, labels, current_set, feature);
                cout << "Using feature(s) {";
                for (int f : current_set) {
                    cout << f + 1 << " "; //print features in 1-based index
                }
                cout << "} accuracy is " << accuracy * 100 << "%" << endl;

                if (accuracy > best_accuracy)
                {
                    best_accuracy = accuracy;
                    best_feature = feature;
                }
            }
        }
        if (best_feature != -1) {
            current_set.push_back(best_feature);
        }
    }

    cout << endl << "Best feature subset: {";
    for (int f : current_set) {
        cout << f + 1 << " "; //print features in 1-based index
    }
    cout << "}" << endl;

}

void backwardElimination(const std::vector<std::vector<int>>& data)
{
    
}

int main() {
    /*cout << "Welcome to the Feature Selection Algorithm." << endl;
    cout << "Type in the name of the file to test: ";
    string filename;
    cin >> filename;
    cout << endl << "Loading in dataset..." << endl;*/
    string filename = "CS170_Small_DataSet__10.txt";

    ifstream file(filename);
    string line;

    if (!file.is_open()) {
    cout << "Error: Could not open file." << endl;
    return 1;
    }

    vector<int> labels;
    vector<vector<double>> features;

    //first column is the true label, the rest are the features
    while (getline(file, line)) {
        stringstream ss(line);
        double value;

        ss >> value;
        labels.push_back((int)value); //store label

        vector<double> row;
        while (ss >> value) {
            row.push_back(value);
        }

        features.push_back(row); //store features at same index as label
    }

    cout << "Dataset loaded." << endl;
    cout << "Type the number of the algorithm you want to run: " << endl;
    cout << "1. Forward Selection" << endl;
    cout << "2. Backward Elimination" << endl;
    int choice;
    cin >> choice;
    cout << endl << "Running algorithm..." << endl << endl;

    if(choice == 1)
    {
        sforwardSelection(labels, features);
    }
    else if(choice == 2)
    {
        //backwardElimination(features);
    }

    cout << "Search completed." << endl;
}