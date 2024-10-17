//Question : https://leetcode.com/problems/remove-methods-from-project/submissions/1422909999/

class Solution {
public:

    vector<bool> infected;
    vector<vector<int>> graph;
    //mark all the infected nodes using DFS
    void findInfected(int src)
    {
        if(infected[src])
        {
            return;
        }
        infected[src] = true;
        for(auto it : graph[src])
        {
            if(src == it)
            {
                continue;
            }
            findInfected(it);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        infected = vector<bool>(n, false);
        graph = vector<vector<int>>(n);
        for(auto it : invocations)
        {
            graph[it[0]].push_back(it[1]);
        }

        findInfected(k);
        // for(auto it : infected)
        // {
        //     std::cout<<it<<" ";
        // }
        // std::cout<<std::endl;
        //if any of the uinfected node is adjacent to the infected node then the whole infected graph becomes uninfected
        for(int i = 0; i< n; i++)
        {
            if(!infected[i])
            {
                for(auto it : graph[i])
                {
                    if(infected[it])
                    {
                        infected = vector<bool>(n, false);
                        break;
                    }
                }
            }
        }
        //collect all the uninfected nodes from the boolean array
        vector<int> result;
        for(int i = 0; i< infected.size(); i++)
        {
            if(!infected[i])
            {
                result.push_back(i);
            }
            
        }
        return result;
    }
};