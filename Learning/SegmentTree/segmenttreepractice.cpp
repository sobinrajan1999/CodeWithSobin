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