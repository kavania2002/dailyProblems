// https://leetcode.com/problems/decode-ways/

class Solution
{
public:
    string s;
    int n;

    vector<int> dp;

    int solve(int index)
    {
        int count = 0;

        // when index is greater than string size
        // we have reached the end so that way
        // is possible
        if (index >= n)
            return 1;

        // dp approach
        if (dp[index] != -1)
            return dp[index];

        // check if the cur index is 0 or not
        // if 0 then this way not possible
        // otherwise check for next index
        char first = s[index];
        if (first == '0')
        {
            return 0;
        }
        else
        {
            count += solve(index + 1);
        }

        // here we combine two characters of string s
        // at position ind and ind+1
        if (index + 1 < n)
        {
            char second = s[index + 1];

            // form string from characters
            int number = stoi(string() + first + second);

            // if the combined characters of number
            // is possible then we check for next index
            // i.e. at index+2
            if (number >= 1 && number <= 26)
                count += solve(index + 2);
        }
        return dp[index] = count;
    }

    int numDecodings(string s)
    {
        this->n = s.size();
        dp.resize(n, -1);
        this->s = s;
        return solve(0);
    }
};