// https://practice.geeksforgeeks.org/problems/decode-the-string2444/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void prntSt(stack<string> st)
    {
        while (!st.empty())
        {
            cout << st.top() << endl;
            st.pop();
        }
    }

    string decodedString(string s)
    {
        // code here
        stack<string> st;
        int n = s.size();

        int i = 0;
        while (i < n)
        {
            char c = s[i];
            if (c >= '0' && c <= '9')
            {
                int num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9')
                    num = num * 10 + (s[i++] - '0');
                // cout << num << endl;
                st.push(to_string(num));
            }
            else
            {
                if (s[i] == ']')
                {
                    string cur = "";
                    while (!st.empty() && st.top() != "[")
                    {
                        cur = st.top() + cur;
                        st.pop();
                    }
                    st.pop();
                    int repeats = stoi(st.top());
                    st.pop();

                    string curRes = "";
                    for (int i = 0; i < repeats; i++)
                    {
                        curRes += cur;
                    }
                    st.push(curRes);
                }
                else
                {
                    st.push(string() + s[i]);
                }
                i++;
            }
        }

        // prntSt(st);
        string res = "";
        while (!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends