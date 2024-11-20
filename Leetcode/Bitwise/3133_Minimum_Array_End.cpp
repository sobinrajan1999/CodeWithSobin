//question : https://leetcode.com/problems/minimum-array-end/description

class Solution {
public:
    long minEnd(int n, int x) {
        // Initialize the result to the given number x
        long result = x;
        
        // Calculate the remaining bits we need to process, starting with (n - 1)
        long remaining = n - 1;
        
        // Initialize position to 1 (which is 2^0) for checking each bit from right to left
        long position = 1;
        
        // Loop until there are no more bits left in "remaining"
        while (remaining) {
            // Check if the current position bit in x is 0
            if (!(x & position)) {
                // If the bit at 'position' is 0 in x, set the bit in result
                // if the corresponding bit in 'remaining' is also 1.
                // This helps in making result as small as possible while still satisfying the conditions.
                result |= (remaining & 1) * position;
                
                // Shift 'remaining' right by 1 to process the next bit
                remaining >>= 1;
            }
            // Shift position left by 1 (move to the next higher bit)
            position <<= 1;
        }
        
        // Return the result after processing all bits
        return result;
    }
};
