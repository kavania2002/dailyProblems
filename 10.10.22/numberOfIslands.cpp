// https://practice.geeksforgeeks.org/problems/number-of-islands/1  

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int dp[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
    vector<vector<int>> grid;
    int n, m;
    
    bool possible(int &x, int &y) {
        if (x >= 0 && y >=0 && x<n && y<m) return true;
        return false;;
    }
    
    void dfs(int x, int y, vector<vector<int>> &newgrid) {
        for (int i = 0; i<4; i++) {
            int xi = x + dp[i][0], yi = y + dp[i][1];
            if (possible(xi, yi) && newgrid[xi][yi]) {
                newgrid[xi][yi] = 0;
                dfs(xi, yi, newgrid);
            }
        }
    }
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        this->n = n, this->m = m;
        grid.resize(n, vector<int>(m, 0));
        vector<int> res;
        
        int k = operators.size();
        for (int i = 0; i<k; i++) {
            grid[operators[i][0]][operators[i][1]] = 1;
            
            int cnt = 0;
            vector<vector<int>> newgrid = grid;
            for (int i = 0; i<n; i++) {
                for (int j = 0; j<m; j++) {
                    if (newgrid[i][j]) {
                        newgrid[i][j] = 0;
                        dfs(i, j, newgrid);
                        cnt++;
                    }
                }
            }
            
            res.push_back(cnt);
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends