#ifndef NEAREST_SEARCH_H
#define NEAREST_SEARCH_H

#include <vector>

class NearestSearch {
public:
    int accuracy(const std::vector<std::vector<int>>& data, int current_set, int features_to_add);
    void search(const std::vector<std::vector<int>>& data, int current_set, int features_to_add);
    double distance(const std::vector<int>& instance1, const std::vector<int>& instance2);
    void crossValidation(const std::vector<std::vector<int>>& data, int features_to_add);
    void forwardSelection(const std::vector<std::vector<int>>& data);
    void backwardElimination(const std::vector<std::vector<int>>& data);
};