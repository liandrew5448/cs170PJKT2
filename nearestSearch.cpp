#include <iostream>
#include <cmath>
#include <limits>
#include "nearestSearch.h"

using namespace std;

int NearestSearch::search(const vector<std::vector<double>>& features, const vector<int>& labels, int targetLabel, const vector<int>& targetFeatures)
{//searches for the nearest neighbor of the current set using the first features features
    int closestIndex = -1;
    double closest_distance = numeric_limits<double>::infinity();

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

double NearestSearch::distance(const vector<double>& instance1, const vector<double>& instance2, const vector<int>& targetFeatures)
{
    double sum = 0.0;
    for (size_t i = 0; i < targetFeatures.size() ; i++)
    {
        sum += (instance1[targetFeatures[i]] - instance2[targetFeatures[i]]) * (instance1[targetFeatures[i]] - instance2[targetFeatures[i]]);
    }
    return sqrt(sum);
}

double NearestSearch::crossValidation(const vector<vector<double>>& features, const vector<int>& labels, const vector<int>& currentSet)
{
    int correct = 0;
    
    for (size_t i = 0; i < features.size(); i++)
    {
        int nearestIndex = search(features, labels, i, currentSet); //predict the label using the new feature subset
        if (labels[nearestIndex] == labels[i]) //check if the prediction is correct
        {
            correct++;
        }
    }

    return static_cast<double>(correct) / features.size();
}