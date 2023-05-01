#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // Function to find the indices of the two numbers that add up to target.
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // Create an unordered map to store the complements and their indices.
        unordered_map<int, int> m;
        // Loop through each element of the nums vector.
        for (int i = 0; i < nums.size(); i++)
        {
            // Calculate the complement of the current element.
            int complement = target - nums[i];
            // Check if the complement is already in the map.
            if (m.find(complement) != m.end())
            {
                // If it is, return the indices of the complement and the current element.
                return {m[complement], i};
            }
            // If the complement is not in the map, add the current element and its index to the map.
            m[nums[i]] = i;
        }
        // If no pair of elements add up to the target, return an empty vector.
        return {};
    }
};

int main()
{
    // Create a vector of integers.
    vector<int> nums = {2, 7, 11, 15};
    // Set the target value.
    int target = 9;
    // Create a Solution object.
    Solution s;
    // Call the twoSum function and store the result.
    vector<int> result = s.twoSum(nums, target);
    // Print the result.
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    // Expected output: [0, 1]
    return 0;
}
