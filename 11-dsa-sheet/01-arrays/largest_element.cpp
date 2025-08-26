#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
   public:
    int largestElement(vector<int>& nums)
    {
        int largestElement = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            if (largestElement < nums[i]) largestElement = nums[i];
        }
        return largestElement;
    }

   public:
    int secondLargestElementBrute(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int largest = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] != largest) return nums[i];
        }
        return -1;
    }

    int secondLargestElementBetter(vector<int>& nums)
    {
        int largest = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > largest)
            {
                largest = nums[i];
            }
        }

        int second_largest = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != largest && nums[i] > second_largest)
            {
                second_largest = nums[i];
            }
        }

        // If second_largest was never updated, return -1
        return (second_largest == INT_MIN) ? -1 : second_largest;
    }

    int secondLargestElementOptimal(vector<int>& nums)
    {
        int largest = nums[0];
        int second_largest = INT_MIN;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > largest)
            {
                second_largest = largest;
                largest = nums[i];
            }
            if (nums[i] < largest && nums[i] > second_largest)
            {
                second_largest = nums[i];
            }
        }

        return (second_largest == INT_MIN ? -1 : second_largest);
    }

    // Leetcode 26
   public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() == 0) return 0;

        int i = 0;  // pointer for position of last unique element
        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[j] != nums[i])
            {
                i++;
                nums[i] = nums[j];  // shift unique value forward
            }
        }
        return i + 1;  // i is index, so +1 is the count
    }
};

int main()
{
    Solution sol;
    vector<int> v = {1, 2, 3, 4, 5};

    cout << sol.largestElement(v) << endl;
    cout << sol.secondLargestElementBrute(v) << endl;
    cout << sol.secondLargestElementBetter(v) << endl;
    cout << sol.secondLargestElementOptimal(v) << endl;
    cout << sol.removeDuplicates(v) << endl;

    return 0;
}