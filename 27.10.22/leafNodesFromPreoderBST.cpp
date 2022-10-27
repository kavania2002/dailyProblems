//{ Driver Code Starts
// Initial Template for C++

// https://practice.geeksforgeeks.org/problems/print-leaf-nodes-from-preorder-traversal-of-bst2657/1

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    vector<int> res;
    int N;

    void solve(vector<int> &bst, int first, int second)
    {
        if (first >= N || first >= second)
            return;
        // cout << first << ' ' << second << endl;
        if (second == first + 1)
        {
            res.push_back(bst[first]);
            return;
        }

        int st = bst[first];
        int i = first + 1;
        while (i < second)
        {
            if (bst[i] > st)
                break;
            i++;
        }

        solve(bst, first + 1, i);
        solve(bst, i, second);
    }

    vector<int> leafNodes(int arr[], int N)
    {
        // code here
        this->N = N;
        vector<int> bst;
        for (int i = 0; i < N; i++)
            bst.push_back(arr[i]);

        solve(bst, 0, N);

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
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> ans = ob.leafNodes(arr, N);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends