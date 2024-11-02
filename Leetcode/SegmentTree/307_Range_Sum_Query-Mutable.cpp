//question : https://leetcode.com/problems/range-sum-query-mutable/description/

#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> seg; // Segment tree to store the sum of segments
    int n; // Size of the input array

    // Constructor to initialize the segment tree
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg = vector<int>(4 * n, 0); // Allocate memory for segment tree (4 * n for safe sizing)
        build(nums, 0, 0, n - 1); // Build the segment tree based on the input array
    }

    // Function to build the segment tree
    int build(vector<int>& nums, int index, int left, int right) {
        if (left == right) {
            // Leaf node: set segment tree node to the array value
            seg[index] = nums[left];
            return seg[index];
        }
        
        int mid = (left + right) / 2; // Midpoint of the current range
        // Recursively build the left and right halves of the segment
        int l = build(nums, 2 * index + 1, left, mid);
        int r = build(nums, 2 * index + 2, mid + 1, right);
        
        // Set current node's value as the sum of the left and right children
        seg[index] = l + r;
        return seg[index];
    }

    // Function to update an element in the array
    void update(int i, int val, int left, int right, int index) {
        if (left == right) {
            // If it's a leaf node, directly update the segment tree node
            seg[index] = val;
            return;
        }

        int mid = (left + right) / 2;
        // Recursively update the correct half based on the index to be updated
        if (i <= mid) {
            update(i, val, left, mid, 2 * index + 1);
        } else {
            update(i, val, mid + 1, right, 2 * index + 2);
        }

        // After updating the child, update the current node to maintain correct sums
        seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
    }

    // Function to query the sum in a given range [l, r]
    int query(int left, int right, int index, int l, int r) {
        if (l > right || r < left) {
            // If the current segment is completely outside the query range, return 0
            return 0;
        }
        if (l <= left && r >= right) {
            // If the current segment is completely inside the query range, return its sum
            return seg[index];
        }

        // Otherwise, split the range and query both halves
        int mid = (left + right) / 2;
        int low = query(left, mid, 2 * index + 1, l, r);
        int high = query(mid + 1, right, 2 * index + 2, l, r);

        // Return the sum of the left and right halves
        return low + high;
    }

    // Public update function to update an element at index with value val
    void update(int index, int val) {
        update(index, val, 0, n - 1, 0);
    }
    
    // Public sumRange function to get the sum from index left to right
    int sumRange(int left, int right) {
        return query(0, n - 1, 0, left, right);
    }
};

/**
 * Usage:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index, val);
 * int param_2 = obj->sumRange(left, right);
 */
