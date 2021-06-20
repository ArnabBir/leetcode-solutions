class Solution {
    
public:
    
    void preorderUtil(Node* node, vector<int>& ans) {
        if(node == nullptr)     return;
        ans.push_back(node->val);
        for(int i = 0; i < node->children.size(); ++i) {
            preorderUtil(node->children[i],ans);
        }
    }
    
    vector<int> preorder(Node* root) {
        vector<int> ans;
        preorderUtil(root,ans);
        return ans;
        
    }
};
