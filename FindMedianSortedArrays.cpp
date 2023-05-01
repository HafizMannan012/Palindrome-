#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // create a vector to store the merged arrays
        vector<int> mergedvector;
        // initialize two pointers to the beginning of each array
        int i = 0, j = 0;
        // loop through both arrays and add the smaller element to the merged vector
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                mergedvector.push_back(nums1[i]);
                i++;
            }
            else
            {
                mergedvector.push_back(nums2[j]);
                j++;
            }
        }
        // if there are any remaining elements in the first array, add them to the merged vector
        while (i < nums1.size())
        {
            mergedvector.push_back(nums1[i]);
            i++;
        }
        // if there are any remaining elements in the second array, add them to the merged vector
        while (j < nums2.size())
        {
            mergedvector.push_back(nums2[j]);
            j++;
        }
        // calculate the median of the merged vector
        double median = 0;
        if (mergedvector.size() % 2 == 0)
        {
            // if the merged vector has an even number of elements, take the average of the middle two elements
            int result = mergedvector.size() / 2;
            median = (mergedvector[result - 1] + mergedvector[result]) / 2.0;
        }
        else
        {
            // if the merged vector has an odd number of elements, take the middle element
            median = mergedvector[floor(mergedvector.size() / 2)];
        }
        // return the median
        return median;
    }
};

int main()
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 4};
    Solution s;
    double median = s.findMedianSortedArrays(nums1, nums2);
    cout << "The median of the merged sorted arrays is: " << median << endl;
    return 0;
}