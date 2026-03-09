#include "nearestSearch.h"

int NearestSearch::accuracy(const std::vector<std::vector<int>>& data, int current_set, int features_to_add)
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

void NearestSearch::search(const std::vector<std::vector<int>>& data, int current_set, int features_to_add)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i][current_set] == data[i][features_to_add])
        {
            std::cout << "Match found at index: " << i << std::endl;
        }
    }
}
