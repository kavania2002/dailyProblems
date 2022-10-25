//https://practice.geeksforgeeks.org/problems/earthquake-and-the-paint-shop4518/1


struct alphanumeric {
    string name;
    int count;
};
class Solution {
  public:
    vector<alphanumeric> sortedStrings(int N, vector<string> A) {
        vector<alphanumeric>ans;
        map<string,int>mp;
        for(int i=0;i<N;i++){
            mp[A[i]]++;
        }
        for(auto i:mp){
            ans.push_back({i.first,i.second});
        }
        return ans;
    }
};