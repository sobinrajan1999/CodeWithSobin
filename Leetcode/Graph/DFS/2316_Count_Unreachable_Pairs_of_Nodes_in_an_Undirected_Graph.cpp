//Questions : https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

class Solution {
public:

    vector<bool> visited;
    vector<vector<int>> graph;

    void connectedComponents(int src, long long& count)
    {
        if(visited[src])
        {
            return;
        }
        visited[src] = true;
        count++;
        for(auto it : graph[src])
        {
            connectedComponents(it, count);
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        if(edges.size() == 0)
        {
            return (long long)(n*(long long)(n-1))/2;
        }
        visited = vector<bool>(n, false);
        graph = vector<vector<int>>(n);
        for(auto it : edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<long long> cccount;
        for(int i = 0; i< n; i++)
        {
            if(!visited[i])
            {
                long long count = 0;
                connectedComponents(i, count);
                cccount.push_back(count);
            }
        }
        long long result = 0;
        for(long long i = 0; i< cccount.size()-1; i++)
        {
            for(long long j = i+1; j < cccount.size(); j++)
            {
                result += (cccount[i] * cccount[j]);
            }
        }
        // std::cout<<std::endl;
        return result;
    }
};