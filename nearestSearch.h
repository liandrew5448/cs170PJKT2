#ifndef NEAREST_SEARCH_H
#define NEAREST_SEARCH_H

#include <vector>

class NearestSearch {
public:
    int search(const vector<vector<double>>& features, const vector<int>& labels, int targetLabel, const vector<int>& featureSubset);
    double distance(const vector<double>& instance1, const vector<double>& instance2, const vector<int>& featureSubset);
    double crossValidation(const vector<vector<double>>& features, const vector<int>& labels, const vector<int>& currentSet);
};

#endif 