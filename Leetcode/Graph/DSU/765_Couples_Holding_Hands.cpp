//Question : https://leetcode.com/problems/couples-holding-hands/

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

    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        parent = vector<int>(n);
        size = vector<int>(n);
        for(int i = 0; i< n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
        //pushing the ideal couple positions into a DSU
        for(int i = 0; i< n; i+=2)
        {
            union_set(i, i+1);
        }
        
        int result = 0;
        //here if the adjacent couple's parent are not same then we will make both into same set and increase the swap count.
        for(int i = 0; i< n; i+= 2)
        {
            int u = find_set(row[i]);
            int v = find_set(row[i+1]);
            if(u != v)
            {
                result++;
                union_set(row[i], row[i+1]);
            }
        }
        return result;
    }
};