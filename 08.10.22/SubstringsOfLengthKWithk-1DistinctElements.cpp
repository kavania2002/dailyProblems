//https://practice.geeksforgeeks.org/problems/substrings-of-length-k-with-k-1-distinct-elements/1

class Solution {
  public:
    int countOfSubstrings(string S, int k) {
        // code here
        map<char,int>mp;
        int ct=0;
        for(int i=0;i<S.size();i++){
            if(i<k){
                mp[S[i]]++;
                if(i==k-1){
                    if (mp.size() == k-1){
                        ct++;
                    }
                }
            }
            else {
              
                    mp[S[i-k]]--;
                    if(mp[S[i-k]]==0)
                        mp.erase(S[i-k]);
                    mp[S[i]]++;
                    if(mp.size() == k-1){
                        ct++;
                    }
                
            }
        }
        return ct;
    }
};