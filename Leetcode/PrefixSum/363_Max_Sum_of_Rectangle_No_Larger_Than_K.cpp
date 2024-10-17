//Question : https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

#define lli long long int

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        //using prefixsum to calculate the sum of [i,j], [i-1, j], [i,j-1], [i-1, j-1]
        vector<vector<lli>> prefixsum(n, vector<lli>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                prefixsum[i][j] = matrix[i][j];
                if ((i - 1) >= 0)
                {
                    prefixsum[i][j] += prefixsum[i - 1][j];
                }
                if ((j - 1) >= 0)
                {
                    prefixsum[i][j] += prefixsum[i][j - 1];
                }
                //to eliminate the addition [i-1, j-1] index twice
                if (i > 0 && j > 0)
                {
                    prefixsum[i][j] -= prefixsum[i - 1][j - 1];
                }
            }
        }
        lli result = INT_MIN;
        //i and j will define the area of rectangle. if n*m = 2*3 then it goes from 2*3 -> 2*2 -> 2*1 ->1*3 -> 1*2 -> 1*1.
        //  x and y will calculate the area within the rectangle defined by i and j. if area is 2*3 then we will be calulating the sum of 1*1 -> 1*2 -> 1*3 -> 2*1 -> 2*2 ->2*3. same goes for other areas as well. here it is x and y.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int x = i; x < n; x++)
                {
                    for (int y = j; y < m; y++)
                    {
                        lli currarea = prefixsum[x][y];
                        if (i > 0)
                        {
                            currarea -= prefixsum[i - 1][y];
                        }
                        if (j > 0)
                        {
                            currarea -= prefixsum[x][j - 1];
                        }
                        //to eliminate the subtraction [i-1, j-1] index twice
                        if (i > 0 && j > 0)
                        {
                            currarea += prefixsum[i - 1][j - 1];
                        }
                        //if the area is within the range k
                        if (currarea <= k)
                        {
                            result = max(result, currarea);
                        }
                    }
                }
            }
        }
        return result;
    }
};