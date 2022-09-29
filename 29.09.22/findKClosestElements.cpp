// https://leetcode.com/problems/find-k-closest-elements/

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &rr, int k, int x)
    {
        int ind = 0;


        // two pointer method
        int p1, p2;

        int n = rr.size();
        vector<int> res;
        while (ind < n && rr[ind] < x)
            ind++;

        if (ind < n && rr[ind] == x)
        {
            p1 = ind - 1, p2 = ind + 1;
            res.push_back(rr[ind]);
            k--;
        }
        else
        {
            p1 = ind - 1, p2 = ind;
        }

        while (k > 0 && p1 >= 0 && p2 < n)
        {
            if (abs(rr[p1] - x) > abs(rr[p2] - x))
                res.push_back(rr[p2++]);
            else if (abs(rr[p1] - x) <= abs(rr[p2] - x))
                res.push_back(rr[p1--]);
            k--;
        }

        while (k && p1 >= 0)
        {
            res.push_back(rr[p1--]);
            k--;
        }

        while (k && p2 < n)
        {
            res.push_back(rr[p2++]);
            k--;
        }

        sort(res.begin(), res.end());

        return res;
    }
};