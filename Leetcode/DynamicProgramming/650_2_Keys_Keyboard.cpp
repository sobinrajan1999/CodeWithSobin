//question : https://leetcode.com/problems/2-keys-keyboard/description/

class Solution {
public:
    // Helper function to recursively calculate the minimum steps to achieve 'n' characters
    int solve(int n, int content, int paste) {
        // Base case: If the current content is greater than or equal to the target 'n'
        if (n <= content) {
            return 0; // No more steps needed
        }

        // Case 1: If the current content divides the target exactly
        if (n % content == 0) {
            // Two operations: Copy All and Paste
            // After copying, double the content by pasting it
            return 2 + solve(n, content + content, content);
        }

        // Case 2: Perform one paste operation
        return 1 + solve(n, content + paste, paste);
    }

    int minSteps(int n) {
        // Start with 1 character in the editor, and the last "paste" used was 1
        return solve(n, 1, 1);
    }
};
