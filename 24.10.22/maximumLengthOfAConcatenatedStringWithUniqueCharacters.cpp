//https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

class Solution {
public:
    
    int rec(vector<string> &arr,string s,int idx){
        set<char> st(s.begin(),s.end());
        int ans = s.size();
        if(st.size() != s.size()) return 0;
        
        for(int i=idx;i<arr.size();i++){
            ans = max(rec(arr,s+arr[i],i+1),ans);
        }
        
        return ans;
    }
    
    int maxLength(vector<string>& arr) {
        string s = "";
        int idx=0;
        return rec(arr,s,idx);
    }
};