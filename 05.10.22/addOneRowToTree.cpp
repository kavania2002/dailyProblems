// https://leetcode.com/problems/add-one-row-to-tree/description/

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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        // if depth == 1 so the new node needs to 
        // inserted at the top and it's left
        // should have root
        if (depth == 1)
        {
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }

        // perform a level order traversal till depth becomes 1
        // coz we want the parents of the new node to be inserted
        queue<TreeNode *> q;
        q.push(root);

        depth--;

        while (!q.empty())
        {
            if (depth == 1)
                break;

            int l = q.size();

            for (int i = 0; i < l; i++)
            {
                TreeNode *front = q.front();
                q.pop();

                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }

            depth--;
        }

        // insert the new node with value val 
        // to each parent in the queue
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            TreeNode *tempLeft = new TreeNode(val);
            TreeNode *tempRight = new TreeNode(val);
            tempLeft->left = node->left, tempRight->right = node->right;
            node->left = tempLeft, node->right = tempRight;
        }

        return root;
    }
};