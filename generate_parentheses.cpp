class Solution {
private:
    vector<string> combos;
public:
    void generateParenthesisUtil(string& x, int o, int c, int n) {
        if(o == n && c == n) {
            combos.push_back(x);
        }
        if(o < n) {
            x.push_back('(');
            generateParenthesisUtil(x, o+1, c, n);
            x.pop_back();
        }
        if(c < n && c < o) {
            x.push_back(')');
            generateParenthesisUtil(x, o, c+1, n);
            x.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string s = "";
        generateParenthesisUtil(s,0,0,n);
        return combos;
    }
};
