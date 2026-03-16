#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include "nearestSearch.h"

using namespace std;


void forwardSelection(const std::vector<int>& labels, const std::vector<std::vector<double>>& features)
{//seaches for the best set of features by combining one feature at a time
    NearestSearch searcher;
    vector<int> currentSet; //stores the current set of features
    vector<int> bestSet; //stores the best set of features found
    int numFeatures = features[0].size();
    double overallAccuracy = 0.0;

    for (int level = 0; level < numFeatures; level++) //for each level of feature combination
    {
        int bestFeature = -1;
        double bestAccuracy = 0.0;
        for (int feature = 0; feature < numFeatures; feature++)
        {
            if (find(currentSet.begin(), currentSet.end(), feature) == currentSet.end()) //if feature is not already in the set
            {

                vector<int> tempSet = currentSet;
                tempSet.push_back(feature);
                double accuracy = searcher.crossValidation(features, labels, tempSet); //tests accuracy of the set
                cout << "Using feature(s) {";

                for (int f : tempSet) {
                    cout << f + 1 << " "; //print features in 1-based index
                }
                cout << "} accuracy is " << accuracy * 100 << "%" << endl;

                if (accuracy > bestAccuracy) {
                    bestAccuracy = accuracy;
                    bestFeature = feature;
                }
            }
        }
        if (bestFeature != -1) {
            currentSet.push_back(bestFeature);
        }

        if(bestAccuracy > overallAccuracy) {
            overallAccuracy = bestAccuracy;
            bestSet = currentSet;
        }
    }

    cout << endl << "Best feature subset: {";
    for (int f : bestSet) {
        cout << f + 1 << " "; //print features in 1-based index
    }
    cout << "}" << endl;
    cout << "With an accuracy of: " << overallAccuracy * 100 << "%" << endl;

}

void backwardElimination(const std::vector<int>& labels, const std::vector<std::vector<double>>& features)
{//seaches for the best set of features by combining one feature at a time
    NearestSearch searcher;
    vector<int> currentSet;//stores the current set of features
    for(int i = 0; i < features[0].size(); i++)
    {
        currentSet.push_back(i);//start with all features in the set
    }

    vector<int> bestSet;//stores the best set of features found
    int numFeatures = features[0].size();
    double overallAccuracy = 0.0;

    for (int level = numFeatures - 1; level >= 0; level--)//for each level of feature combination
    {
        int removeFeature = -1;
        double bestAccuracy = 0.0;
        for (int feature : currentSet)
        {

            vector<int> tempSet = currentSet;
            tempSet.erase(remove(tempSet.begin(), tempSet.end(), feature), tempSet.end()); //removes one feature from the set
            double accuracy = searcher.crossValidation(features, labels, tempSet);//tests accuracy of the set 
            
            cout << "Using feature(s) {";

            for (int f : tempSet) {
                cout << f + 1 << " "; //print features in 1-based index
            }
            cout << "} accuracy is " << accuracy * 100 << "%" << endl;

            if (accuracy > bestAccuracy) {
                bestAccuracy = accuracy;
                removeFeature = feature;
            }
        }
        if (removeFeature != -1) {
            currentSet.erase(remove(currentSet.begin(), currentSet.end(), removeFeature), currentSet.end());
        }

        if(bestAccuracy > overallAccuracy) {
            overallAccuracy = bestAccuracy;
            bestSet = currentSet;
        }
    }

    cout << endl << "Best feature subset: {";
    for (int f : bestSet) {
        cout << f + 1 << " "; //print features in 1-based index
    }
    cout << "}" << endl;
    cout << "With an accuracy of: " << overallAccuracy * 100 << "%" << endl;
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
        forwardSelection(labels, features);
    }
    else if(choice == 2)
    {
        backwardElimination(labels, features);
    }

    cout << "Search completed." << endl;
}