//Questions : https://leetcode.com/problems/clone-graph/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(unordered_map<Node*, Node*>& m, Node* head)
    {
        Node* curr = new Node(head->val);
        vector<Node*> neighbours;
        //map to store key as original Node* and val as the cloned Node*
        m[head] = curr;
        for(auto it : head->neighbors)
        {
            //if the Node* already present in the map i.e. it has already been traversed.
            if(m.find(it) != m.end())
            {
                neighbours.push_back(m[it]);
            }
            //if it is a new node.
            else
            {
                Node* newnode = dfs(m, it);
                neighbours.push_back(newnode);
            }
        }
        curr->neighbors = neighbours;
        return curr;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        if(node == nullptr)
        {
            return nullptr;
        }
        return dfs(m, node);
    }
};