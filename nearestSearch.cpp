#include <iostream>
#include <cmath>
#include "nearestSearch.h"

double NearestSearch::search(const std::vector<std::vector<double>>& features, const std::vector<int>& labels, const std::vector<int>& feature_subset)
{//searches for the nearest neighbor of the current set using the first features features
    double min_distance = std::numeric_limits<double>::max();
    int closest_index = -1;

    for (size_t i = 0; i < features.size(); i++) {
        double dist = distance(features[i], features[feature_subset[0]], feature_subset.size());
        if (dist < min_distance) {
            min_distance = dist;
            closest_index = i;
        }
    }

    return closest_index;
}

double NearestSearch::distance(const std::vector<double>& instance1, const std::vector<double>& instance2, int num_features)
{
    double sum = 0.0;
    for (size_t i = 0; i < num_features ; i++)
    {
        sum += (instance1[i] - instance2[i]) * (instance1[i] - instance2[i]);
    }
    return sqrt(sum);
}

double NearestSearch::accuracy(const std::vector<std::vector<double>>& features, const std::vector<int>& labels, const std::vector<int>& current_set, int feature_to_add)
{
    //sudocode
    for i = 1 : size(data, 1)
        object_to_classify = data(i,2:end);
        label_object_to_classify = data(i,1);

        nearest_neighbor_distance = inf;
        nearest_neighbor_location = inf;
        for k = 1 : size(data, 1)
            disp([Ask if, int2str(i), ' is nearest neighbour with ', int2str(k)]);

            if k ~= i
                distance = sqrt(sum((object_to_classify - data(k,2:end)).^2));
                if distance < nearest_neighbor_distance
                    nearest_neighbor_distance = distance;
                    nearest_neighbor_location = k;
                end
            end
        end
    end
end

}