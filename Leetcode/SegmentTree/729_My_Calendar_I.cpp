//question : https://leetcode.com/problems/my-calendar-i

#include <iostream>
using namespace std;

struct calendar {
    int starttime, endtime; // Start and end times of the calendar booking
    calendar* left; // Left subtree (for bookings that end before this booking starts)
    calendar* right; // Right subtree (for bookings that start after this booking ends)

    // Constructor to initialize a calendar booking with a start and end time
    calendar(int start, int end) {
        starttime = start;
        endtime = end;
        left = nullptr;
        right = nullptr;
    }
};

class MyCalendar {
public:
    calendar* root; // Root of the binary search tree for bookings

    // Recursive function to insert a booking in the BST if it does not overlap with existing bookings
    bool build(int start, int end, calendar*& node) {
        if (!node) {
            // If the current node is null, we can insert the new booking here
            node = new calendar(start, end);
            return true;
        }

        if (end <= node->starttime) {
            // New booking ends before the current booking starts, so check the left subtree
            return build(start, end, node->left);
        } else if (start >= node->endtime) {
            // New booking starts after the current booking ends, so check the right subtree
            return build(start, end, node->right);
        } else {
            // Overlap found, cannot insert the booking
            return false;
        }
    }

    // Constructor to initialize the calendar
    MyCalendar() {
        root = nullptr; // Start with an empty calendar
    }
    
    // Public function to add a new booking if no overlap exists
    bool book(int startTime, int endTime) {
        return build(startTime, endTime, root); // Attempt to insert into the BST
    }
};

/**
 * Usage:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime, endTime);
 */
