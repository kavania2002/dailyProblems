// https://leetcode.com/problems/path-sum-ii/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:

    // making global variables which will
    // store the final answer
    vector<vector<int>> res;
    int target;

    void solve(TreeNode *root, int &cur, vector<int> &rr)
    {
        if (root == NULL)
        {
            return;
        }

        // if the we have reached the target and it's a leaf
        if (cur + root->val == target && !root->left && !root->right)
        {
            rr.push_back(root->val);
            res.push_back(rr);
            rr.pop_back();
            return;
        }

        cur += root->val;
        rr.push_back(root->val);
        solve(root->left, cur, rr);
        solve(root->right, cur, rr);

        // backtracking because we have used pass by reference variables
        // to optimize space instead of occupying new memory
        cur -= root->val;
        rr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        int cur = 0;
        this->target = targetSum;
        vector<int> rr;

        solve(root, cur, rr);
        return res;
    }
};