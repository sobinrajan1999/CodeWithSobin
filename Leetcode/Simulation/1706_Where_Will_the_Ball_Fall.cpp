//question : https://leetcode.com/problems/where-will-the-ball-fall/description/

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();      // Number of rows in the grid
        int m = grid[0].size();    // Number of columns in the grid
        vector<int> result(m);     // Result vector to store the final position of each ball

        // Loop through each column, where each column represents a starting position for a ball
        for(int i = 0; i < m; i++)
        {
            int index = 0;       // Start at the top row
            int dir = i;         // Start position in the current column (ball's initial position)
            int tempresult = -1; // Temporary variable to store the result for the current ball

            // Simulate the path of the ball until it either gets stuck or reaches the bottom
            while(true)
            {
                // If the ball has reached the last row, set tempresult to the current column and exit
                if(index == n)
                {
                    tempresult = dir;
                    break;
                }

                // Case 1: Ball is moving right (grid[index][dir] == 1)
                if(grid[index][dir] == 1)
                {
                    // Check if ball is at the right edge, where it would get stuck
                    if(dir == m - 1)
                    {
                        tempresult = -1; // Ball gets stuck
                        break;
                    }
                    // Check if the next cell to the right also has 1 (forming a V-shape)
                    else if(grid[index][dir + 1] == 1)
                    {
                        index++; // Move the ball down
                        dir++;   // Move the ball right
                    }
                    // If the next cell to the right has -1, ball gets stuck in an L-shape
                    else if(grid[index][dir + 1] == -1)
                    {
                        tempresult = -1; // Ball gets stuck
                        break;
                    }
                }
                // Case 2: Ball is moving left (grid[index][dir] == -1)
                else if(grid[index][dir] == -1)
                {
                    // Check if ball is at the left edge, where it would get stuck
                    if(dir == 0)
                    {
                        tempresult = -1; // Ball gets stuck
                        break;
                    }
                    // Check if the next cell to the left also has -1 (forming a V-shape)
                    else if(grid[index][dir - 1] == -1)
                    {
                        index++; // Move the ball down
                        dir--;   // Move the ball left
                    }
                    // If the next cell to the left has 1, ball gets stuck in an inverted L-shape
                    else if(grid[index][dir - 1] == 1)
                    {
                        tempresult = -1; // Ball gets stuck
                        break;
                    }
                }
            }
            // Store the result for the current ball in the result array
            result[i] = tempresult;
        }
        return result; // Return the result vector with the final positions of all balls
    }
};
