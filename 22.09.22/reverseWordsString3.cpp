// https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution
{
public:
    string reverseWords(string s)
    {
        string res = "";
        int st = 0, n = s.size();
        string cur = "";
        while (st < n)
        {
            if (s[st] == ' ')
            {
                res += (cur + " ");
                cur = "";
            }
            else
            {
                cur = s[st] + cur;
            }
            st++;
        }
        res += cur;
        return res;
    }
};