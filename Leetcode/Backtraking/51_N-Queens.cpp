//question : https://leetcode.com/problems/n-queens/description/

class Solution {
public:

vector<int> queens;
    //to construct the constructed n queen solution string
    vector<std::string> constructQueen(int n)
    {
        std::string temp;
        for(int i = 0; i<n; i++ )
        {
            temp += ".";
        }
        vector<std::string> res(n, temp);
        for(int i = 0; i<n ;i++)
        {
            res[i][queens[i]] = 'Q';
        }
        return res;
    }
    //to check if the coordinate is feasible to put queen.
    bool isPossible(int row, int col)
    {
        for(int i = 0; i < row; i++)
        {
            int qrow = i;
            int qcol = queens[i];
            //first condition is for the horizontal columns and second condition is for the diagonals. if the there is a queen in any diagonal coordinates then the row and col difference will be same.
            if((qcol == col) or (abs(col - qcol) == abs(row - qrow)))
            {
                return false;
            }
        }
        return true;
    }

    bool nQueen(vector<vector<string>>& arr, int row, int n)
    {
        //if the row is equal to the size of chessboard then we have found one solution
        if(row == n)
        {
            return true;
        }
        //we will interate through the columns of the current row.
        for(int col= 0; col < n; col++)
        {
            //checking the feasibility
            if(isPossible(row, col))
            {
                queens[row] = col;
                //if the solution the solution return true then we will construct the string of the solution in the nxn chess form.
                if(nQueen(arr, row+1, n))
                {
                    arr.push_back(constructQueen(n));
                }
                //initializing the solution back to normal as we are going to find another way.
                queens[row] = -1;
            }
        }
        return false;
    }

    vector<vector<string>> solveNQueens(int n) {
        queens = vector<int>(20, -1);
        vector<vector<string>> result;
        nQueen(result, 0, n);
        return result;
    }
};