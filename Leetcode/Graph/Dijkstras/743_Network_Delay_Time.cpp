//Question: https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    vector<vector<pair<int, int>>> graph;
    vector<int> dist;

    void addEdges(int u, int v, int w)
    {
        graph[u].push_back({v, w});
    }

    void Dijkstras(int src)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while(!pq.empty())
        {
            auto u = pq.top().second;
            pq.pop();
            for(auto it : graph[u])
            {
                int v = it.first;
                int w = it.second;
                if(dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        graph = vector<vector<pair<int, int>>>(n+1);
        dist = vector<int>(n+1, INT_MAX);
        dist[k] = 0;
        for(auto it : times)
        {
            addEdges(it[0], it[1], it[2]);
        }
        Dijkstras(k);
        int result = 0;
        bool changed = false;
        for(int i = 1; i< dist.size(); i++)
        {
            if(dist[i] == INT_MAX)
            {
                return -1;
            }
            result = std::max(result, dist[i]);
            
        }
        return result;

    }
};