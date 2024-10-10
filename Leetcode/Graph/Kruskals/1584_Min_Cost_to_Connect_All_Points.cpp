class Solution {
public:

    vector<pair<int, pair<int, int>>> graph;
    vector<int> parent;
    vector<int> size;
    //find function for disjoint set
    int find_set(int v)
    {
        if(parent[v] == v)
        {
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }
    //union function for disjoint set
    //union by size
    void union_set(int u, int v)
    {
        int a = find_set(u);
        int b = find_set(v);
        if(a != b)
        {
            if(size[a] < size[b])
            {
                std::swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }

    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        graph = vector<pair<int, pair<int, int>>>();
        parent = vector<int>(n);
        size = vector<int>(n);
        for(int i = 0; i< n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
        //this loop will create graph with cost as the manhattan distance b/w two points.
        for(int i =0; i< n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int cost = std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
                graph.push_back({cost, {i, j}});
            }
        }
        //applying kruskals to create a minimum spanning tree. MST will help in getting the minimum cost.
        sort(graph.begin(), graph.end());

        int cost = 0;
        for(auto it : graph)
        {
            int u = find_set(it.second.first);
            int v = find_set(it.second.second);
            int w = it.first;
            if(u != v)
            {
                union_set(it.second.first, it.second.second);
                cost += w;
            }
        }
        return cost;
    }
};