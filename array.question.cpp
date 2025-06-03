#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
/*🧠 1. Find the First Non-Repeating Element
Level: Easy–Medium
Problem:
Given an array of integers, find the first element that does not repeat. If all elements repeat,
return -1.

Example:

cpp
Copy
Edit
Input: [1, 2, 2, 3, 1, 4]
Output: 3
🔍 Focus: Use a hash map to count frequency and then loop again to find the first with frequency 1.

*/

int non_repeating_element(vector<int>& v)
{
    map<int, int> mp;
    for (int i = 0; i < v.size(); i++)
    {
        mp[v[i]]++;  // store element and its frequency
    }
    for (const auto& pair : mp)
    {
        if (pair.second == 1)
        {
            return pair.first;
        }
    }
    return -1;
}

/*

🔄 2. Rotate Array by K Positions
Level: Medium
Problem:
Rotate the array to the right by k steps. You must do this in-place with O(1) extra space.

Example:

cpp
Copy
Edit
Input: [1,2,3,4,5,6,7], k = 3   [7,6,5,4,3,2,1]
Output: [5,6,7,1,2,3,4]
🔍 Focus: Use reverse technique. First reverse the whole array, then reverse first k elements, then
the remaining.
*/

void rotate_array_by_kth(vector<int>& v, int k)
{
    int n = v.size();
    if (n == 0) return;
    k = k % n;  // handle k > n
    reverse(v.begin(), v.end());
    reverse(v.begin(), v.begin() + k);
    reverse(v.begin() + k, v.end());
}

/*
🧩 3. Maximum Subarray Sum (Kadane’s Algorithm)
Level: Medium
Problem:
Find the contiguous subarray within a 1D array which has the largest sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4]
Output: 6 // Subarray: [4,-1,2,1]
🔍 Focus: Understand dynamic programming approach using Kadane’s Algorithm.
*/

int max_sub_sum(vector<int>& v)
{
    int max_sum = v.empty() ? 0 : v[0];
    int curr_sum = v.empty() ? 0 : v[0];
    for (size_t i = 1; i < v.size(); ++i)
    {
        curr_sum = max(v[i], curr_sum + v[i]);
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}

// 2  3  4    6  8  10

int binary_search(vector<int>& v, int target)
{
    int start = 0;
    int end = v.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (v[mid] == target)
        {
            return mid;
        }
        if (v[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> v = {100, 100, 200, 300, 450, 100};
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};
    cout << non_repeating_element(v);
    cout << endl;
    rotate_array_by_kth(v1, 3);
    for (auto& ele : v1)
    {
        cout << ele << " ";
    }
    cout << endl;
    int ans = binary_search(v, 2000);
    (ans != -1) ? cout << "found at index " << ans << endl : cout << "not found" << endl;
    return 0;
}