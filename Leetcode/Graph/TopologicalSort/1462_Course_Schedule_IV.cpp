//Questions : https://leetcode.com/problems/course-schedule-iv/

class Solution {
public:
    //using kahn method of topological sorting.
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int> > graph(numCourses);
        for(auto it : prerequisites)
        {
            graph[it[0]].push_back(it[1]);
        }
        //taking the indegree of the graph
        for(int i = 0; i< numCourses; i++)
        {
            for(auto it : graph[i])
            {
                // std::cout<<it<<" ";
                indegree[it]++;
            }
        }
        // std::cout<<std::endl;
        queue<int> q;
        //pushing the nodes that has zero indegree.
        for(int i = 0; i< indegree.size(); i++)
        {
            if(indegree[i] == 0)
            {
                // std::cout<<i<<std::endl;
                q.push(i);
            }
        }
        //this 2D vector will tell if it reachable from i to j;
        vector<vector<int>> table(numCourses, vector<int>(numCourses, false));
        int index = 0;
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            for(auto it : graph[temp])
            {
                //marking it as reachable
                table[temp][it] = true;
                //if 'temp' to 'it' is reachable then all the nodes that are reachable to 'temp' should also be reachable to 'it'
                for(int i = 0; i< numCourses; i++)
                {
                    if(table[i][temp] == true)
                    {
                        table[i][it] = true;
                    }
                }
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }

        }
        vector<bool> result;
        for(auto it : queries)
        {
            result.push_back(table[it[0]][it[1]]);
        }
        return result;
    }
};