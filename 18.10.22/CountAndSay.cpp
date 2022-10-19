// write in template; int main code already given by leetcode.
class Solution {
public:
    string countAndSay(int n) {
        string previous_str="1";
        for(int i=1;i<n;i++){
            int cnt=0;
            char c=previous_str[0];
            string temp="";
            for(int j=0;j<previous_str.size();j++){
                if(previous_str[j]==c){
                    cnt++;
                }
                else{
                    temp+=('0'+cnt);
                    temp+=c;
                    cnt=1;
                    c=previous_str[j];

                }
            }
            
            if(cnt>0){
                temp+=('0'+cnt);
                temp+=c;
            }
            previous_str=temp;
            // cout<<previous_str<<" ";
        }
        
        return previous_str;
    }
};
