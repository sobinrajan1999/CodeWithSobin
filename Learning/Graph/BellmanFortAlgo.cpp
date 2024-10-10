#include <bits/stdc++.h>
using namespace std;

struct edges
{
    int u,v,w;
    edges(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }
};

vector<edges> graph;
vector<int> dist;

void addEdge(int u, int v, int w)
{
    edges e(u,v,w);
    graph.push_back(e);
}

void bellmanFord(int src, int n, int e)
{
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j < e; j++)
        {
            dist[graph[j].v] = std::min(dist[graph[j].u] + graph[j].w, dist[graph[j].v]);
        }
    }
}

int main()
{
    int n = 5;
    int e = 8;
    graph = vector<edges>();
    dist = vector<int>(n, INT_MAX);
    addEdge(0,1,-1);
    addEdge(1,3,2);
    addEdge(0,2,4);
    addEdge(1,2,3);
    addEdge(1,4,2);
    addEdge(3,2,5);
    addEdge(3,1,1);
    addEdge(4,3,-3);
    dist[0] = 0;
    
    bellmanFord(0, n,e);

    for(auto it : dist)
    {
        std::cout<<it<<" ";
    }
    std::cout<<std::endl;
}