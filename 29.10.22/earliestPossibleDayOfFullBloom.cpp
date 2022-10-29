// https://leetcode.com/problems/earliest-possible-day-of-full-bloom/description/

class Solution
{
public:
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
    {
        int cur = 0;
        int result = 0;
        int n = plantTime.size();
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
            vp.push_back({growTime[i], plantTime[i]});

        sort(vp.rbegin(), vp.rend());
        for (int i = 0; i < n; i++)
        {
            cur += vp[i].second;
            result = max(cur + vp[i].first, result);
        }
        return result;
    }
};