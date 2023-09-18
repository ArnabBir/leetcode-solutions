// Link: https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/


// Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> children;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//     }

//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };


class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (root == nullptr) {
            return "";
        }

        string ans = "[";
        ans += to_string(root->val);
        for (Node* node : root->children) {
            ans += serialize(node);
        }
        ans += "]";
        return ans;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.size() == 0) {
            return nullptr;
        }
        string val = "";
        int curr = 1;
        while (data[curr] != '[' && data[curr] != ']') {
            val += data[curr++];
        }
        Node* node = new Node(stoi(val), vector<Node*>());
        int braces = 0;
        string next = "";
        if (data[curr] == ']') {
            return node;
        }
        while (curr < data.size()) {
            if (data[curr] == ']') {
                next += data[curr];
                --braces;
            }
            else if (data[curr] == '[') {
                next += data[curr];
                ++braces;
            } else {
                if (data[curr] != ',') {
                    next += data[curr];
                } else {
                    next += data[curr];
                }
            }
            if (braces == 0) {
                node->children.push_back(deserialize(next));
                next = "";
            }
            ++curr;
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));