//question : https://leetcode.com/problems/longest-uploaded-prefix/description

#include <vector>
using namespace std;

class LUPrefix {
public:
    int size_n; // Total number of videos
    vector<bool> seg; // Segment tree to track uploaded videos, where true means uploaded

    // Constructor to initialize the segment tree with `n` videos
    LUPrefix(int n) {
        seg = vector<bool>(4 * n, false); // 4 * n ensures enough space for segment tree
        size_n = n;
    }

    // Function to upload a video, marking it as true in the segment tree
    void update(int low, int high, int index, int video) {
        if (low == high) {
            // If at a leaf node corresponding to the specific video
            seg[index] = true;
            return;
        }
        
        int mid = (low + high) / 2;
        // Update the left or right half of the segment tree based on the video position
        if (video <= mid) {
            update(low, mid, 2 * index, video); // Left subtree
        } else {
            update(mid + 1, high, 2 * index + 1, video); // Right subtree
        }

        // Update the current node based on its children's states
        seg[index] = seg[2 * index] & seg[2 * index + 1];
    }

    // Function to query the longest contiguous prefix of uploaded videos
    int query(int low, int high, int index) {
        if (low == high) {
            // Reached a leaf node, return this video's index if it's uploaded, else 0
            return seg[index] ? high : 0;
        }

        if (seg[index]) {
            // If the current segment is fully uploaded, return the high end of this segment
            return high;
        }

        int mid = (low + high) / 2;
        // Check the left child; if it's incomplete, return the result from the left subtree
        if (!seg[2 * index]) {
            return query(low, mid, 2 * index);
        } else {
            // Otherwise, continue with the right subtree and take the max
            return query(mid + 1, high, 2 * index + 1);
        }
    }

    // Public method to upload a video
    void upload(int video) {
        update(1, size_n, 1, video); // Starts update from the root of the segment tree
    }

    // Public method to get the length of the longest contiguous prefix of uploaded videos
    int longest() {
        return query(1, size_n, 1); // Starts query from the root of the segment tree
    }
};

/**
 * Usage:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
