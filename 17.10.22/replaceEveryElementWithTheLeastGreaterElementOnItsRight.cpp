//https://practice.geeksforgeeks.org/problems/replace-every-element-with-the-least-greater-element-on-its-right/1

class Solution{
    public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        set<int> s;
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            // int x = arr[i];
            auto upper1 = s.upper_bound(arr[i]);
            if(upper1==s.end())
            ans.push_back(-1);
            else ans.push_back(*upper1);
            s.insert(arr[i]);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};