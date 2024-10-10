//Questions : https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights/problem
//solved using floyd warshall algorithm

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dist;

void floydWarshall(int n)
{
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i<= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(dist[i][k] != INT_MAX and dist[k][j] != INT_MAX and dist[i][j] >  dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main()
{
    int n, m;
    std::cin>>n>>m;
    dist = vector<vector<int>>(n+1, vector<int>(n+1, INT_MAX));
    for(int i = 0; i< m; i++)
    {
        int u, v, w;
        std::cin>>u>>v>>w;
        dist[u][v] = w;
    }
    for(int i = 1; i<= n; i++)
    {
        dist[i][i] = 0;
    }
    floydWarshall(n);
    // for(auto it : dist)
    // {
    //     for(auto i : it)
    //     {
    //         if(i == INT_MAX)
    //         {
    //             std::cout<<"INF ";
    //             continue;
    //         }
    //         std::cout<<i<<"   ";
    //     }
    //     std::cout<<std::endl;
    // }
    // std::cout<<std::endl;
    int queryCount;
    std::cin>>queryCount;
    for(int i = 0; i< queryCount; i++)
    {
        int u,v;
        std::cin>>u>>v;
        if(dist[u][v] == INT_MAX)
        {
            std::cout<<-1<<std::endl;
            continue;
        }
        std::cout<<dist[u][v]<<std::endl;
    }
    
    
}