// https://leetcode.com/problems/break-a-palindrome/description/

class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        int n = palindrome.size();

        if (n == 0 || n == 1)
            return "";

        int count_a = 0;
        for (char &c : palindrome)
            if (c == 'a')
                count_a++;

        if (count_a == n || count_a == n - 1)
            palindrome[n - 1] = 'b';
        else
        {
            int st = 0;
            while (st < n)
            {
                if (palindrome[st] != 'a')
                {
                    palindrome[st] = 'a';
                    break;
                }
                st++;
            }
        }

        return palindrome;
    }
};