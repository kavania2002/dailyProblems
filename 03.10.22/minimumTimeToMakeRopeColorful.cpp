// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = colors.size();
        int st = 0;

        int count = 0;
        while (st + 1 < n)
        {
            char first = colors[st], second = colors[st + 1];
            if (first == second)
            {
                count += min(neededTime[st], neededTime[st + 1]);
                if (neededTime[st + 1] < neededTime[st])
                    swap(neededTime[st + 1], neededTime[st]);
            }
            st++;
        }

        return count;
    }
};