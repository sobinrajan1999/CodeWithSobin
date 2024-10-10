//Question : https://leetcode.com/problems/count-the-number-of-complete-components/

class Solution {
public:
    //grpah adjacency list
    vector<vector<int>> graph;
    //visited array
    vector<bool> visited;
    //bfs function. it will return {nodes traversed, number of edges in undirected graph}
    pair<int, int> bfs(int src)
    {
        int edges = 0;
        deque<int> q;
        int totalEdges = 0;
        q.push_front(src);
        while(!q.empty())
        {
            totalEdges++;
            int temp = q.front();
            q.pop_front();
            if(!visited[temp])
            {
                visited[temp] = true;
                edges++;
                for(auto it : graph[temp])
                {
                    q.push_front(it);
                }
            }
        }
        return {edges, totalEdges};
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //finalResult will keep the number of complete graph
        int finalResult = 0;
        graph = vector<vector<int>>(n);
        visited = vector<bool>(n);
        //creating the adjacency list
        for(auto it : edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        //checking every nodes for connected components
        for(int i = 0; i< n; i++)
        {
            if(!visited[i])
            {
                auto temp = bfs(i);
                // std::cout<<" n: "<<i<<" nodes: "<<temp.first<<" edges: "<<temp.second<<std::endl;
                //formula to get the number of edges for complete graph of component. i.e. (n*(n-1))/2.
                int completeGraph = (temp.first * (temp.first - 1))/2;
                //if the formula and the edges returned by bfs function is same, then we will add it to the result.
                if(completeGraph == temp.second/2)
                {
                    finalResult++;
                }
            }
        }
        return finalResult;
    }
};