class Solution {
        string d1[4] = {"I", "X", "C", "M"};
    string d2[3] = {"V", "L", "D"};
    
public:
    string intToRoman(int num) {
        string result = "";
        int dec = 1;
        while(num) {
                int x = num % 10;
                if(x <= 3) {
                    for(int i = 0; i < x; ++i) {
                        result = d1[dec-1] + result;
                    }
                }
                else if(x == 4) {
                    result = d1[dec-1] + d2[dec-1] + result;
                }
                else if(x < 9){
                    for(int i = 5; i < x; ++i) {
                        result = d1[dec-1] + result;
                    }
                    result = d2[dec-1] + result;
                }
                else {
                    result = d1[dec-1] + d1[dec] + result;
                }    
            ++dec;
            num /= 10;
        }
        return result;
    }
};
