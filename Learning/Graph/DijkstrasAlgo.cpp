#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> dist;

void addEdge(int u,int v, int w)
{
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
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

int main()
{
    int V = 7;
    graph = vector<vector<pair<int, int>>>(V);
    dist = vector<int>(V, INT_MAX);
    // making above shown graph
    addEdge(0, 1, 2);
    addEdge(0, 2, 6);
    addEdge(1, 3, 5);
    addEdge(2, 3, 8);
    addEdge(3, 4, 10);
    addEdge(3, 5, 15);
    addEdge(4, 6, 2);
    addEdge(5, 6, 6);
    dist[0] = 0;

    Dijkstras(0);
    for(auto it : dist)
    {
        std::cout<<it<<" ";
    }
    std::cout<<std::endl;
    return 0;
}