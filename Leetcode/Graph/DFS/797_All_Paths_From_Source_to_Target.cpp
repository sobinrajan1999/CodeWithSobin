//question : https://leetcode.com/problems/all-paths-from-source-to-target/description/

class Solution {
public:
    // Vector to store all the resulting paths
    vector<vector<int>> result;

    // Recursive function to find all paths from source to target
    void solve(vector<vector<int>>& graph, vector<int>& ans, int n, int src) {
        // Base Case: If the current node (`src`) is the target node (`n`)
        if (src == n) {
            result.push_back(ans); // Add the current path to the result
            return;               // Terminate this recursive branch
        }

        // Iterate over all adjacent nodes of the current node
        for (auto it : graph[src]) {
            ans.push_back(it);         // Add the current node to the path
            solve(graph, ans, n, it);  // Recursively call for the next node
            ans.pop_back();            // Backtrack: Remove the last node added
        }

        return; // End the current function call
    }

    // Function to find all paths from source (node 0) to target (last node)
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();    // Number of nodes in the graph
        vector<int> temp;        // Temporary vector to store the current path
        temp.push_back(0);       // Start the path with the source node (0)
        solve(graph, temp, n-1, 0); // Start the recursive search from node 0 to node n-1
        return result;           // Return all the paths found
    }
};
