#include <bits/stdc++.h>
using namespace std;

vector<int> seg;

int build(int index, int low, int high, vector<int>& arr)
{
    if(low == high)
    {
        seg[index] = arr[low];
        return seg[index];
    }
    int mid = (low + high)/2;
    int l = build(2*index+1, low, mid, arr);
    int h = build(2*index+2, mid+1, high, arr);
    seg[index] = std::min(l, h);
    return seg[index];
}

int query(int index, int low, int high, int l, int r)
{
    // std::cout<<"low: "<<low<<" high: "<<high<<std::endl;
    //complete overlap
    if(low >= l and high <= r)
    {
        return seg[index];
    }
    //no overlap
    if(r < low or l > high)
    {
        return INT_MAX;
    }
    //partial overlap
    int mid = (low + high)/2;
    int left = query(2*index+1, low, mid, l, r);
    int right = query(2*index+2, mid+1, high, l, r);
    return min(left, right);
}

void update(int index, int low, int high, int val, int node, vector<int>& arr)
{
    if(low == high)
    {
        seg[index] = val;
        arr[node] = val;
        return;
    }
    int mid = (low + high)/2;
    if(node <= mid)
    {
        update(2*index+1, low, mid, val, node, arr);
    }
    else{
        update(2*index+2, mid+1, high, val , node, arr);
    }
    seg[index] = std::min(seg[2*index+1], seg[2*index+2]);
}

vector<int> tree(4*n), lazyTree(4*n, 0);   // lazyTree is extra tree which stores the value which is to be added @ that node.
                                            //  i.e. at index i u got one node in tree and one more extra node in lazyTree.
 
void updateRange(int node, int st, int en, int l, int r, int val)
{
 
    // case 1.  Invalid or out of range
    if (l > en || r < st || l > r)
        return;
 
    
    // first see u have extra data stored in lazy tree for this current node 
    if(lazyTree[node] != 0)
    {
        tree[node] += lazyTree[node] * (r - l + 1); // val * no of child nodes
 
        // propagate lazyTree[node] value for child nodes as well so that for next time we can relax that node as well.
        if(l != r) // if has child ?
        {
            tree[2*node] += lazyTree[node];  // left one
            tree[2*node+1] += lazyTree[node]; // right one
        }
 
        // Since you have used lazyTree[node] value for current node so  make it 0
        lazyTree[node] = 0;
    }
 
    // case 2. overlapping range 
    if(l >= st && r <= en)
    {
        // update the value 
        tree[node] += val * (r - l + 1);
 
        // atleast update immediate children (will be updated in O(1) otherwise for all children u may need O(n)) the value
         //   but we will update in lazyTree 
        if( l != r) // has the children so not a leaf node 
        {
            lazyTree[2*node] += val;  
            lazyTree[2*node+1] += val;  
        }
        return;  // since updation is done so return 
    }
 
    // case 3. partial overlap 
    int mid = (st + en)/2;
 
    // call for left sub tree & right : it will get the ans based on above logic
    updateRange(node, st, mid, l, r, val);
    updateRange(node, mid+1, en, l, r, val);
 
    // update the current node  with whatever we got from left &  right 
    tree[node] =  tree[2*node] + tree[2*node + 1];
}

int main()
{
    vector<int> arr = {2,1,0,4,3,7};
    seg = vector<int>(4*arr.size());
    build(0, 0, arr.size()-1, arr);
    // for(auto it: seg)
    // {
    //     std::cout<<it<<" ";
    // }
    // std::cout<<std::endl;
    
    
    while(true)
    {
        std::cout<<"Enter your choice: (1 = query,2 = update)\n";
        int choice;
        std::cin>>choice;
        if(choice == 1)
        {
            std::cout<<"start the query: \n";
            int l, r;
            std::cin>>l>>r;
            std::cout<<query(0, 0, arr.size()-1, l, r)<<std::endl;
        }
        else{
            std::cout<<"Enter the index and value: ";
            int ind, val;
            std::cin>>ind>>val;
            update(0, 0, arr.size()-1, val, ind, arr);
        }
        
    }
}