#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
// function to take Integer Vector input
vector<int> take_input()
{
    size_t n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter elements: ";
    for (auto& it : v)
    {
        cin >> it;
    }
    return v;
}

void printvector(const vector<int>& v)
{
    for (const auto& it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}

// Q1. Write a program to read N integers and print them in sorted order.
void Q1()
{
    size_t size;
    cout << "Enter the number of Integer you want to read: ";
    cin >> size;
    vector<int> integer_vector(size);
    cout << endl;
    cout << "Enter the Integers: ";
    for (int i = 0; i < size; i++)
    {
        cin >> integer_vector[i];
    }
    sort(integer_vector.begin(), integer_vector.end());
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << integer_vector[i] << " ";
    }
    cout << endl;
}

// Q2. Given a list of integers with possible duplicates, print only the unique elements in
// increasing order.
void Q2()
{
    size_t size = 5;
    vector<int> v(size);
    cout << "Enter the elements: ";
    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }
    set<int> st;
    for (int i = 0; i < v.size(); i++)
    {
        st.insert(v[i]);
    }
    for (auto& it : st)
    {
        cout << it << " ";
    }
    cout << endl;
}

// Q3. Implement a frequency counter: Given N integers, print each unique integer with its
// frequency.
void Q3()
{
    vector<int> array_of_interger = take_input();
    map<int, int> frequency_counter;
    for (auto& it : array_of_interger)
    {
        frequency_counter[it]++;
    }
    for (auto& it : frequency_counter)
    {
        cout << it.first << ":" << it.second << " ";
    }
    cout << endl;
}
int main()
{
    // Q1();
    // Q2();
    // Q3();
    map<int, string> mp;
    map<int, int> mpp;
    for (int i = 0; i < 5; i++)
    {
        mpp.insert({i, i++});
    }
    for (auto& it : mpp)
    {
        cout << it.first << ":" << it.second << " ";
    }
    cout << endl;
    // mp.insert({100, "Hundred"});
    // cout << mp[100] << endl;

    return 0;
}