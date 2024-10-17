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

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 1001;
        parent = vector<int>(n);
        size = vector<int>(n);
        for(int i = 0; i< n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
        vector<int> result;
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int a = find_set(u);
            int b = find_set(v);
            //if the parents are not same then we will add it in the union
            if(a != b)
            {
                union_set(u, v);
            }
            //if the parents are same then there is a cycle in the graph. we will add it our result and we will break from the loop and return the result array
            else
            {
                result.push_back(u);
                result.push_back(v);
                break;
            }
        }
        return result;
    }
};