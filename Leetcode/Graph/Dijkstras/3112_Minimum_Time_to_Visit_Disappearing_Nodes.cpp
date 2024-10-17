//Question : https://leetcode.com/problems/minimum-time-to-visit-disappearing-nodes/

class Solution {
public:

    vector<int> dist;
    vector<vector<pair<int, int>>> graph;
    vector<bool> visited;
    //using dijkstras to calculate minimum distance to 0 to all other nodes
    void Dijkstras(vector<int>& disappear)
    {
        //min heap will store three values 1. distance to reach the node 2. time taken to reach the node from 0 and 3. node.
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        dist[0] = 0;
        while(!pq.empty())
        {
            auto [wt, temp] = pq.top();
            auto [time, u] = temp;
            pq.pop();
            if(wt > dist[u])
            {
                continue;
            }
            for(auto it : graph[u])
            {
                auto [v, wt] = it;
                //if adjacent node disappears after the given time then we will not visit the node.
                if(time+wt < disappear[v] and dist[u] != INT_MAX and dist[v] > dist[u] + wt)
                {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], {time+wt, v}});
                }
            }
        }
    }

    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        visited = vector<bool>(n, false);
        graph = vector<vector<pair<int, int>>>(n);
        dist = vector<int>(n, INT_MAX);
        for(auto it : edges)
        {
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }
        Dijkstras(disappear);
        //if the distance is unreachable then then mark it as -1.
        for(auto& it : dist)
        {
            if(it == INT_MAX)
            {
                it = -1;
            }
        }
        return dist;
    }
};