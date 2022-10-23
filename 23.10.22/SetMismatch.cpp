#include<bit/stdc++.h>
using namespace std;

// Question Link: https://leetcode.com/problems/set-mismatch/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& v) {
        int n = v.size();
        int i = 0;
        while(i<n){
            if(v[i]!=v[v[i]-1]){
                swap(v[i],v[v[i]-1]);
            }else{
                i++;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(v[i]!=i+1){
                ans.push_back(v[i]);
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};

void main(){
    
}