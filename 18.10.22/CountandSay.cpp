// Question Link: https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        vector<pair<char,int>> v;
        string s="1";
        if(n==1){
              return s;
        }
        for(int i=1;i<n;i++){
            v=solve(s);
            s=ans(v);
        }
        return s;
    }
    vector<pair<char,int>> solve(string s){
        vector<pair<char,int>> v;
        int cnt=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                cnt++;
            }
            else{
                v.push_back({s[i-1],cnt});
                cnt=1;
            }
        }
        v.push_back({s[s.size()-1],cnt});
        return v;
    }
    string ans(vector<pair<char,int>> v){
        string s="";
        for(int i=0;i<v.size();i++){
            s+=to_string(v[i].second);
            s+=v[i].first;
        }
        return s;
    }
};