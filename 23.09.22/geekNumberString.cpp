// https://practice.geeksforgeeks.org/problems/904237fa926d79126d42c437802b04287ea9d1c8/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // read the question properly
    // only few conditions need to be statisfied
    // the max among the consecutive need to be even and other one odd
    // consider the edge case of 0 and 9
    bool checkIf(int &x, int &y)
    {
        if (x == y)
            return false;

        int mx = max(x, y);
        int mn = min(x, y);

        if (mx == 9 && mn == 0)
            return true;

        if (mx % 2 || mn % 2 == 0)
            return false;
        if (mx == mn + 1)
            return true;

        return false;
    }

    int minLength(string s, int n)
    {
        // code here

        // create a stack and check at every instance
        // if geeky then remove otherwise push
        // return size of stack
        stack<int> st;
        st.push(s[0] - '0');

        int i = 1;
        while (i < n)
        {
            int cur = (s[i] - '0');
            if (!st.empty())
            {
                int top = st.top();

                // if consecutive elements found, remove otherwise
                if (checkIf(top, cur))
                    st.pop();
                else
                    st.push(cur);
            }
            else
            {
                st.push(cur);
            }
            i++;
        }

        return st.size();
    }
};

//{ Driver Code Starts.

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        Solution obj;
        cout << obj.minLength(s, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends