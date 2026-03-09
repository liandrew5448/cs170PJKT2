#ifndef NEAREST_SEARCH_H
#define NEAREST_SEARCH_H

#include <vector>

class NearestSearch {
public:
    int accuracy(const std::vector<std::vector<int>>& data, int current_set, int features_to_add);
    void search(const std::vector<std::vector<int>>& data, int current_set, int features_to_add);
};