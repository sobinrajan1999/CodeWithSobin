//Question : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int connectedComponent = 0;
    int find_set(int v)
    {
        if(parent[v] == 0)
        {
            parent[v] = v;
            connectedComponent++;
        }
        return parent[v] == v? v : (parent[v] = find_set(parent[v]));
    }

    void union_set(int u, int v)
    {
        int a = find_set(u);
        int b = find_set(v);
        if( a!= b)
        {
            connectedComponent--;
            if(size[a] < size[b])
            {
                swap(a, b);
            }
            size[a] += size[b];
            parent[b] = a;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        parent = vector<int>(20003, 0);
        size = vector<int>(20003);
        for(int i = 0; i< 20003; i++)
        {
            size[i] = 1;
        }
        for(auto it :stones)
        {
            union_set(it[0]+1, it[1] + 10002);
        }
        return stones.size() - connectedComponent;
    }
};