class Solution {
public:
    
    void mergeTreesUtil(TreeNode* root1, TreeNode* root2, TreeNode* root, TreeNode* parent, bool child) {
        if(!root1 && !root2) {
            if(parent == root) {
                root = NULL;
            }
            else {
                if(child) {
                parent->right = NULL;
                }
                else {
                    parent->left = NULL;
                }
            }    
        }   
        else if(!root1) {
            root->val = root2->val;
            root->left = new TreeNode();
            root->right = new TreeNode();
            mergeTreesUtil(NULL, root2->left, root->left, root, false);
            mergeTreesUtil(NULL, root2->right, root->right, root, true);
        }
        else if(!root2) {
            root->val = root1->val;
            root->left = new TreeNode();
            root->right = new TreeNode();
            mergeTreesUtil(root1->left, NULL, root->left, root, false);
            mergeTreesUtil(root1->right, NULL, root->right, root, true);
        }
        else {
            root->val = root1->val + root2->val;
            root->left = new TreeNode();
            root->right = new TreeNode();
            mergeTreesUtil(root1->left, root2->left, root->left, root, false);
            mergeTreesUtil(root1->right, root2->right, root->right, root, true);
        }
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)    return NULL;
        TreeNode* root = new TreeNode();
        mergeTreesUtil(root1, root2, root, root, false);
        return root;
    }
};
