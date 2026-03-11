#include "nearestSearch.h"

int NearestSearch::accuracy(const std::vector<std::vector<int>>& data, std::vector<int>& labels, int current_set, int features_to_add`)
{
    int correct = 0;
    for (int i = 0; i < data.size(); i++)
    {
        if (labels[i] == labels[features_to_add])
        {
            correct++;
        }
    }
    return correct/data.size();
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

void NearestSearch::crossValidation(const std::vector<std::vector<int>>& data, int features_to_add)
{

}

void NearestSearch::forwardSelection(const std::vector<std::vector<int>>& data)
{
    for(int i = 0; i < data.size(); i++)
    {
        for(int j = 1; j < data[i].size(); j++)
        {
            search(data, i, j);

        }
    }
    
}

void NearestSearch::backwardElimination(const std::vector<std::vector<int>>& data)
{
    
}