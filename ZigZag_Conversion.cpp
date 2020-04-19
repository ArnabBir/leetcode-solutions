class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1)    return s;
        string x = "";
        int l = 2*(numRows-1); 
        int n = s.size();
        for(int i = 0; i < numRows; ++i) {
            int j = i;
            int distance = l - i*2;
            while(j < n) {
                x += s[j];
                if(i != 0 && i != (numRows-1))  {
                    j += distance;
                    distance = l - distance;
                }
                else {
                    j += l;
                }
            }
        }
        return x;
    }
};
