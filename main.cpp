#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int accuracy(const std::vector<std::vector<int>>& data, int current_set, int features_to_add)
{
    int accuracy = 0;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i][current_set] == data[i][features_to_add])
        {
            accuracy++;
        }
    }
    return accuracy;
}

void search(const std::vector<std::vector<int>>& data, int current_set, int features_to_add)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i][current_set] == data[i][features_to_add])
        {
            std::cout << "Match found at index: " << i << std::endl;
        }
    }
}

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

    cout << "Loaded " << features.size() << " instances." << endl;
}