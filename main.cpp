#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "nearestSearch.h"

using namespace std;

int main() {
    ifstream file("CS170_Small_dataSet_1.csv");
    string line;

    vector<vector<double>> dataset;

    while (getline(file, line)) {
        vector<double> row;
        string value;
        stringstream ss(line);

        while (getline(ss, value, ',')) {
            row.push_back(stod(value));
        }

        dataset.push_back(row);
    }

    cout << "Loaded " << dataset.size() << " instances." << endl;

    NearestSearch nearestNeightbor;
    nearestNeightbor.search(dataset, 0, 1);
}