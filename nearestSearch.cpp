#include <iostream>
#include <cmath>
#include <limits>
#include "nearestSearch.h"

int NearestSearch::search(const std::vector<std::vector<double>>& features, const std::vector<int>& labels, int targetLabel, const std::vector<int>& targetFeatures)
{//searches for the nearest neighbor of the current set using the first features features
    int closestIndex = -1;
    double closest_distance = std::numeric_limits<double>::infinity();

    for(size_t i = 0; i < features.size(); i++)
    {
        if(i == targetLabel) continue; //only consider instances with a different label
        {
            double dist = distance(features[targetLabel], features[i], targetFeatures); //calculate distance using the current set of features
            if (dist < closest_distance) //update closest neighbor
            {
                closest_distance = dist;
                closestIndex = i;
            }
        }
    }
    return closestIndex;
}

double NearestSearch::distance(const std::vector<double>& instance1, const std::vector<double>& instance2, const std::vector<int>& targetFeatures)
{
    double sum = 0.0;
    for (size_t i = 0; i < targetFeatures.size() ; i++)
    {
        sum += (instance1[targetFeatures[i]] - instance2[targetFeatures[i]]) * (instance1[targetFeatures[i]] - instance2[targetFeatures[i]]);
    }
    return sqrt(sum);
}

double NearestSearch::accuracy(const std::vector<std::vector<double>>& features, const std::vector<int>& labels, const std::vector<int>& currentSet, int featureToAdd)
{
    int correct = 0;
    std::vector<int> featureSubset = currentSet;
    featureSubset.push_back(featureToAdd); //create a new feature subset with the added feature

    for (size_t i = 0; i < features.size(); i++)
    {
        int nearestIndex = search(features, labels, i, featureSubset); //predict the label using the new feature subset
        if (labels[nearestIndex] == labels[i]) //check if the prediction is correct
        {
            correct++;
        }
    }

    return static_cast<double>(correct) / features.size();
}