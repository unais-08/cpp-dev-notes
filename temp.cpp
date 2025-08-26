#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> st;
    vector<int> v = {1, 1, 2};
    for (int i = 0; i < v.size(); ++i)
    {
        st.insert(v[i]);
    }
    for (auto& it : st)
    {
        cout << it << " ";
    }
    // cout << st.size() << endl;
    return 0;
}