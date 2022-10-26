// https://leetcode.com/problems/continuous-subarray-sum/description/

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> remain = {{0, 0}};

        int curSum = 0;
        for (int i = 0; i < n; i++)
        {
            curSum += nums[i];

            if (!remain.count(curSum % k))
                remain[curSum % k] = i + 1;
            else if (remain[curSum % k] < i)
                return true;
        }

        return false;
    }
};