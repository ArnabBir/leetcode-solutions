/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {

public:

    void serializeUtil(TreeNode* root, string data) {
        if(!root) {
            if(data.size()) {
                data += "-";
            } 
            data += "null";
        }
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        serializeUtil(root,data);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
