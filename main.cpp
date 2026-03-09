#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "nearestSearch.h"

using namespace std;

int main() {
   ifstream file("CS170_Small_dataSet_1.txt");
    string line;

    vector<int> labels;
    vector<vector<double>> features;

    while (getline(file, line)) {
        stringstream ss(line);
        double value;

        ss >> value;
        labels.push_back((int)value);

        vector<double> row;
        while (ss >> value) {
            row.push_back(value);
        }

        features.push_back(row);
    }

    NearestSearch nearSearch;
    vector<double> query = {5.1, 3.5, 1.4, 0.2}; // Example query instance

}