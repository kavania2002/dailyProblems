//https://practice.geeksforgeeks.org/problems/mila-and-strings0435/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string lexicographicallySmallest(string S, int k) {
        // code here
        stack<char>st;
        if((S.length() & (S.length()-1)) == 0){
            k/=2;
        }
        else {
            k*=2;
        }
        if(k>=S.length()){
            return "-1";
        }
        
        for(int i=0;i<S.length();i++){
            if(st.empty()){
                st.push(S[i]);
            }
            else if(k>0){
                if(S[i]>=st.top()){
                    st.push(S[i]);
                }
                else {
                    st.pop();
                    i--;
                    k--;
                }
            }
            else {
                st.push(S[i]);
            }
        }
        while(k>0){
            st.pop();
            k--;
        }
        string s="";
        while(!st.empty()){
            s.push_back(st.top());
            // cout<<st.top()<<" ";
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int k;
        cin >> S >> k;
        Solution ob;
        cout << ob.lexicographicallySmallest(S, k) << endl;
    }
    return 0;
}
