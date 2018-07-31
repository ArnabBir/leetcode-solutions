class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        
        int count0;
        
        for(int i = 0; i < A.size(); ++i)   {
            if(A[i][0] == 0)    {
                for(int j = 0; j < A[i].size(); ++j)    {
                    A[i][j] = abs(A[i][j] -1);
                }
            }
        }
        
        for(int j = 1; j < A[0].size(); ++j)   {
            count0 = 0;
            for(int i = 0; i < A.size(); ++i)    {
                if(A[i][j] == 0)    ++count0;    
            }
            if(count0 > A.size() / 2)   {
                for(int i = 0; i < A.size(); ++i)    {
                    A[i][j] = abs(A[i][j] -1);
                }
            }
        }
                
        int sum = 0, factor = 1, colSum;
        for(int j = A[0].size() -1; j >= 0; --j)   {
            colSum = 0;
            for(int i = 0; i < A.size(); ++i)    {
                colSum += A[i][j];
            }
            sum += factor * colSum;
            factor = factor<<1;
        }
        return sum;
    }
};
