// https://leetcode.com/problems/largest-perimeter-triangle/description/

class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        int n = nums.size();

        if (n < 3)
            return 0;

        sort(nums.rbegin(), nums.rend());

        int i = 0;
        while (i + 2 < n)
        {
            if (nums[i] < nums[i + 1] + nums[i + 2])
                return (nums[i] + nums[i + 1] + nums[i + 2]);
            i++;
        }

        return 0;
    }
};

// 6 3 3 2