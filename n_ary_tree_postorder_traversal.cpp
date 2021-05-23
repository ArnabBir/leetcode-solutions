/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    vector<int> ans;
public:
    vector<int> postorder(Node* root) {
        if(!root)   return ans;
        vector<Node*> children = root->children;
        for(vector<Node*>::iterator it = children.begin(); it != children.end(); ++it) {
            postorder(*it);
        }
        ans.push_back(root->val);
        return ans;
    }
};
