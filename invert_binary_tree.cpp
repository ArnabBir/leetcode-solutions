class Solution {
public:
    
    void invertTreeUtil(TreeNode* node) {
        if(!node)   return;
        swap(node->left, node->right);
        invertTreeUtil(node->left);
        invertTreeUtil(node->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        invertTreeUtil(root);
        return root;
    }
};
