#include <iostream>
#include <vector>

#using namespace std;

int accuracy(const std::vector<std::vector<int>>& data, int current_set, int features_to_add)
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

void search(const std::vector<std::vector<int>>& data, int current_set, int features_to_add)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i][current_set] == data[i][features_to_add])
        {
            std::cout << "Match found at index: " << i << std::endl;
        }
    }
}



int main()
{
    // Example usage
    std::vector<std::vector<int>> data = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 1, 1},
        {0, 0, 0}
    };
    
    int current_set = 0; // Index of the current set
    int features_to_add = 2; // Index of the features to add
    
    int result = accuracy(data, current_set, features_to_add);
    std::cout << "Accuracy: " << result << std::endl;
    
    return 0;
}