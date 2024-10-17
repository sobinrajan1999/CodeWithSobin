//Question : https://leetcode.com/problems/critical-connections-in-a-network/

class Solution {
public:

    vector<vector<int>> graph;
    vector<int> tin;
    vector<int> low;
    vector<int> visited;
    int timer = 0;

    void tarjanAlgorithm(int parent, int node, vector<vector<int>>& bridges)
    {
        tin[node] = timer;
        low[node] = timer;
        timer++;
        visited[node] = true;
        for(auto it : graph[node])
        {
            if(it == parent)
            {
                continue;
            }
            if(!visited[it])
            {
                tarjanAlgorithm(node, it, bridges);
                low[node] = std::min(low[node], low[it]);
                if(low[it] > tin[node])
                {
                    bridges.push_back({node, it});
                }
            }
            else{
                low[node] = std::min(low[node], low[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> bridges;
        graph = vector<vector<int>>(n) ;
        tin = vector<int>(n);
        low = vector<int>(n);
        visited = vector<int>(n);
        for(auto it : connections)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        tarjanAlgorithm(0, 0, bridges);
        return bridges;
    }
};