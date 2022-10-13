// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    int rec(int ind,int buy,int k,vector<int> &prices,vector<vector<vector<int>>> &dp){
        int n = prices.size();
        if( k == 0 || ind == n) return 0;
        if(dp[ind][buy][k] != -1) return dp[ind][buy][k];
        
        if(buy) {
            return dp[ind][buy][k] = max(-prices[ind]+rec(ind+1,0,k,prices,dp),rec(ind+1,1,k,prices,dp));
        }
        else{
            return dp[ind][buy][k] = max(prices[ind]+rec(ind+1,1,k-1,prices,dp),rec(ind+1,0,k,prices,dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(k+1,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int x=1;x<=k;x++){
                    if(j==1) {
             dp[i][j][x] = max(-prices[i] + dp[i+1][0][x],dp[i+1][1][x]);
        }
        else{
             dp[i][j][x] = max(prices[i]+dp[i+1][1][x-1],dp[i+1][0][x]);
        }
                }
            }
        }
        return dp[0][1][k];
    }
};