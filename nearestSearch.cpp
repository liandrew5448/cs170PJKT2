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
    int closest_index = -1;
    for (int i = 0; i < data.size(); i++)
    {
        if (i != current_set)
        {
            double dist = distance(data[current_set], data[i]);
            if (closest_index == -1 || dist < distance(data[current_set], data[closest_index]))
            {
                closest_index = i;
            }
        }
    }
    std::cout << "Closest instance found at index: " << closest_index << std::endl;
}

double NearestSearch::distance(const std::vector<int>& instance1, const std::vector<int>& instance2)
{
    double sum = 0.0;
    for (size_t i = 0; i < instance1.size(); i++)
    {
        sum += (instance1[i] - instance2[i]) * (instance1[i] - instance2[i]);
    }
    return sqrt(sum);
}
