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
class Solution {
public:
    
    int x;
    int ptr;
    
    void kthSmallestUtil(TreeNode* root) {
        if(root == NULL)   return;
        kthSmallestUtil(root->left);
        --ptr;
        if(ptr == 0)  {
            x = root->val;
            return;
        }
        kthSmallestUtil(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        ptr = k;
        kthSmallestUtil(root);
        return x;
    }
};
