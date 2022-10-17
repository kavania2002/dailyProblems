//https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

class Solution
{
      public:

    void flatten(Node *root)

    {
        Node* hef = root;
        

        while(hef){

            if(hef->left == NULL){
                hef = hef->right;
            }

            else{

                Node* pre = hef->left;

                while(pre->right != NULL){
                    pre = pre->right;
                }
                pre->right = hef->right;
                hef->right = hef->left;
                hef->left = NULL;
                hef = hef->right;
            }

        }

    }
};