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
vector<vector<int>> dist;

void addEdge(int u, int v, int w)
{
    edges e(u,v,w);
    graph.push_back(e);
    dist[u][v] = w;
    // dist[v][u] = w;
}

void FloydWarshall(int n, int e)
{
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0;j < n; j++)
            {
                if(dist[i][k] != INT_MAX and dist[k][j] != INT_MAX and dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
                
            }
        }
    }
}

int main()
{
    int n = 4; 
    int e = 8;
    graph = vector<edges>();
    dist = vector<vector<int>>(n, vector<int>(n, INT_MAX));
    addEdge(0,0,0);
    addEdge(0,1,5);
    addEdge(0,3,10);
    addEdge(1,1,0);
    addEdge(1,2,3);
    addEdge(2,2,0);
    addEdge(2,3,1);
    addEdge(3,3,0);
    FloydWarshall(n, e);
    for(auto it : dist)
    {
        for(auto i : it)
        {
            if(i == INT_MAX)
            {
                std::cout<<"INF ";
                continue;
            }
            std::cout<<i<<"   ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}