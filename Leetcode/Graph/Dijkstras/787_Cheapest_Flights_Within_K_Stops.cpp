//Question : https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Solution {
public:
    vector<int> dist;
    vector<vector<pair<int, int>>> graph;
    //using dijkstras algorithm to find the shortest path
    void Dijkstras(int src,int dst, int k)
    {
        dist[src] = 0;
        //using priority queue we will heapify based on the number of stops.
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        //pushing the source.
        pq.push({0, {0, src}});
        while(!pq.empty())
        {
            int u = pq.top().second.second;
            int d = pq.top().second.first;
            int stop = pq.top().first;
            pq.pop();
            //if the stop > threadhold i.e. k
            if(stop > k)
            {
                continue;
            }
            for(auto it : graph[u])
            {
                // std::cout<<it.first<<" "<<it.second<<std::endl;
                int v = it.first;
                int w = it.second;
                //compare based on the distance from the priority queue i.e. 'd' and not from the distance array.
                if((dist[u] != INT_MAX) and (dist[v] > d + w))
                {
                    dist[v] = d + w;
                    pq.push({stop+1, {dist[v], v}});
                }
            }
        }
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        dist = vector<int>(n, INT_MAX);
        graph = vector<vector<pair<int, int>>>(n);
        for(auto it : flights)
        {
            graph[it[0]].push_back({it[1], it[2]});
        }
        Dijkstras(src,dst, k);
        // for(auto it : dist)
        // {
        //     std::cout<<it<<" ";
        // }
        // std::cout<<std::endl;
        if(dist[dst] == INT_MAX)
        {
            return -1;
        }
        return dist[dst];
    }
};