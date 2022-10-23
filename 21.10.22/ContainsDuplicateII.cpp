#include<bits/stdc++.h>
using namespace std;

// Question Link :: https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& v, int k) {
        map<int, int> mp;
        int n = v.size();
        for (int i=0;i<n;i++){
            if (mp.count(v[i]) && i-mp[v[i]]<=k){
                return true;
            }
            mp[v[i]] = i;
        }
        return false;
    }
};

int main(){
    return 0;
}