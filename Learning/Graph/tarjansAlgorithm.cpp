#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>>bridges;
vector<vector<int>> graph;
vector<int> tin;
vector<int> low;
vector<int> visited;
int timer = 0;

void tarjanAlgorithm(int parent, int node)
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
            tarjanAlgorithm(node, it);
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

int main()
{
    int n = 4;
    bridges = vector<pair<int, int>>();
    graph = vector<vector<int>>(n) ;
    tin = vector<int>(n);
    low = vector<int>(n);
    visited = vector<int>(n);

    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[0].push_back(2);
    graph[2].push_back(0);

    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[1].push_back(3);
    graph[3].push_back(1);

    tarjanAlgorithm(0, 0);
    for(auto it : bridges)
    {
        std::cout<<it.first<<" "<<it.second<<std::endl;
    }
}