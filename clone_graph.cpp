/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_set<Node*> visited;
    unordered_map<int, Node*> cloned_visited;
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;
        Node* clone = new Node(node->val);
        visited.insert(node);
        cloned_visited[node->val] = clone;
        for(int i = 0; i < node->neighbors.size(); ++i) {
            Node* child; 
            if(visited.find(node->neighbors[i]) != visited.end()) {
                child = cloned_visited[node->neighbors[i]->val];
            }
            else {
                child = cloneGraph(node->neighbors[i]);
            }
            if(child != nullptr) {
                clone->neighbors.push_back(child);
            }
        }
        return clone;
    }
};
