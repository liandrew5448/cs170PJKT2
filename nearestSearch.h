#ifndef NEAREST_SEARCH_H
#define NEAREST_SEARCH_H

#include <vector>

class NearestSearch {
public:
    int search(const std::vector<std::vector<double>>& features, const std::vector<int>& labels, int targetLabel, const std::vector<int>& featureSubset);
    double distance(const std::vector<double>& instance1, const std::vector<double>& instance2, const std::vector<int>& featureSubset);
    double accuracy(const std::vector<std::vector<double>>& features, const std::vector<int>& labels, const std::vector<int>& currentSet, int featureToAdd);
};

#endif 