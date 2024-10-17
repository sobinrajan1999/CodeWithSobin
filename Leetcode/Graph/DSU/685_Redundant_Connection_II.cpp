//Question : https://leetcode.com/problems/redundant-connection-ii/

class Solution {
public:

    vector<int> parent;
    vector<int> size;

    int find_set(int v)
    {
        if(parent[v] == v)
        {
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int u, int v)
    {
        int a = find_set(u);
        int b = find_set(v);
        if(a != b)
        {
            if(size[a] < size[b])
            {
                swap(a, b);
            }
            size[a] += size[b];
            parent[b] = a;
        }
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = 1001;
        parent = vector<int>(n);
        size = vector<int>(n);
        for(int i = 0; i< n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }

        vector<int> indegree(n, -1);
        int edge1 = -1, edge2 = -1;
        //trying to find the edges that make indegree of 2.
        //instead of count, we will be keeping the index of edge.
        for(int i = 0; i< edges.size(); i++)
        {
            //this means there was already on edge which was point to the node. we will keep the edges index in edge1 and edge2
            if(indegree[edges[i][1]] != -1)
            {
                edge1 = i;
                edge2 = indegree[edges[i][1]];
                break;
            }
            indegree[edges[i][1]] = i;
        }

        vector<int> result;
        for(int i = 0; i < edges.size(); i++)
        {
            //we will ignore edge1 and will run DSU on the all edges
            if(i == edge1)
            {
                continue;
            }
            int u = edges[i][0];
            int v = edges[i][1];
            int a = find_set(u);
            int b = find_set(v);
            if(a != b)
            {
                union_set(u, v);
            }
            //this means there is a cycle in the graph. it can either caused by edge2 or the current edge.
            else
            {
                //if we have found the edges with indegree of 2 then edge2 is the answer.
                if(edge1 != -1)
                {
                    return edges[edge2];
                }
                //if there is not edge with indegree2 then the current edge is the culprit.
                else
                {
                    return edges[i];
                }
            }
        }
        //return edge1 if both the cases didn't satisfied.
        return edges[edge1];
    }
};