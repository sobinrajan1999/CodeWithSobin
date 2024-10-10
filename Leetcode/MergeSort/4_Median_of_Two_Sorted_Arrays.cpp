//Question : https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    // using the merge function from merge sort to merge the two sorted array
    std::vector<int> mergeSortedArray(std::vector<int> num1,
                                      std::vector<int> num2) {
        std::vector<int> arr;
        int n1 = num1.size();
        int n2 = num2.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (num1[i] > num2[j]) {
                arr.push_back(num2[j++]);
            } else {
                arr.push_back(num1[i++]);
            }
        }
        while (i < n1) {
            arr.push_back(num1[i++]);
        }
        while (j < n2) {
            arr.push_back(num2[j++]);
        }
        return arr;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // using this function to sort the sorted arrays
        auto result = mergeSortedArray(nums1, nums2);
        int i = 0;
        int j = result.size() - 1;
        // using the result to find the median
        while (i <= j) {
            // if the value is the middle element
            if (j - i == 0) {
                return result[i];
            }
            // if the array has two middle element
            else if (j - i == 1) {
                return (result[i] + result[j]) / 2.000;
            }
            i++;
            j--;
        }
        return 0;
    }
};