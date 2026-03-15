#ifndef NEAREST_SEARCH_H
#define NEAREST_SEARCH_H

#include <vector>

class NearestSearch {
public:
    double search(const std::vector<std::vector<double>>& features, const std::vector<int>& labels, const std::vector<int>& feature_subset);
    double distance(const std::vector<double>& instance1, const std::vector<double>& instance2, int num_features);
    double accuracy(const std::vector<std::vector<double>>& features, const std::vector<int>& labels, const std::vector<int>& current_set, int feature_to_add);
};

#endif 