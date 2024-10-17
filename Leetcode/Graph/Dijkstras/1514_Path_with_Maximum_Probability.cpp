//Question : https://leetcode.com/problems/path-with-maximum-probability/

class Solution {
public:

    vector<double> prob;
    vector<vector<pair<int, double>>> graph;

    void Dijkstras(int src)
    {
        prob[src] = 1.00000;
        //using priority queue to store the weight and src. Here weight is the probability.
        //we are using max heap to get the max value as we are dealing with probability.
        priority_queue<pair<double, int>> pq;
        pq.push({1.00000, src});
        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            for(auto it : graph[u])
            {
                int v = it.first;
                double w = it.second;
                //this time we will be taking max of the probability as we want to maximize the probability to reach the destination
                if(prob[u] != std::numeric_limits<double>::lowest() and prob[v] < prob[u]*w)
                {
                    // std::cout<<prob[u] << " "<< w<<std::endl;
                    // std::cout<<"probability"<<(float)prob[u]*(float)w<<std::endl;
                    prob[v] = (float)prob[u]*(float)w;
                    pq.push({prob[v], v});
                }
                
            }
        }
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        graph = vector<vector<pair<int, double>>>(n);
        prob = vector<double>(n, std::numeric_limits<double>::lowest());
        for(int i = 0; i< edges.size(); i++)
        {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        Dijkstras(start_node);

        //if the node is unreachable
        if(prob[end_node] == std::numeric_limits<double>::lowest())
        {
            return 0.00000;
        }
        return prob[end_node];
    }
};