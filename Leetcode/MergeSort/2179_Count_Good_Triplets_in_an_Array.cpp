//Question : https://leetcode.com/problems/count-good-triplets-in-an-array/description/

class Solution {
public:
    vector<int> left;
    vector<int> right;

    void countTriplets(vector<int>& pos, vector<int> & arr, int start, int mid, int end)
    {
        int i = mid;
        int j = end;
        //getting the count of same element present on the right of both array
        for(; i >= start; i--)
        {
            while(j >= mid+1 and pos[arr[i]] < pos[arr[j]])
            {
                j--;
            }
            right[arr[i]] += (end - j);
        }
        i = start;
        //getting the count of same element present on the left of both array
        for(j = mid+1; j <= end; j++)
        {
            while(i <= mid and pos[arr[i]] < pos[arr[j]])
            {
                i++;
            }
            left[arr[j]] += (i - start);
        }
    }

    void merge(vector<int>& pos, vector<int> & arr, int start, int mid, int end)
    {
        //calling the count triplets for the array range
        countTriplets(pos, arr, start, mid, end);
        vector<int> temp(end - start +1);
        int i = start;
        int j = mid+1;
        int k = 0;
        while(i <= mid and j <= end)
        {
            if(pos[arr[i]] < pos[arr[j]])
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
            }
        }
        while( i <= mid)
        {
            temp[k++] = arr[i++];
        }
        while( j <= end)
        {
            temp[k++] = arr[j++];
        }
        for(int i = start; i <= end; i++)
        {
            arr[i] = temp[i - start];
        }
    }

    void mergeSort(vector<int>& pos, vector<int>& arr, int start, int end)
    {
        if (start >= end) return;
            int mid = start + (end - start)/2;
            mergeSort(pos, arr, start, mid);
            mergeSort(pos, arr, mid+1, end);
            merge(pos, arr, start, mid, end);

    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        //array to store no. of same element in both the arrays from the left side
        left = vector<int>(nums1.size(), 0);
        //array to store no. of same element in both the arrays from the right side
        right = vector<int>(nums1.size(), 0);
        //array to store the position of num1
        vector<int> pos(nums1.size(), 0);
        vector<int> arr = nums2;
        //storing the position of num1 array
        for(int i = 0; i< nums1.size(); i++)
        {
            pos[nums1[i]] = i;
        }
        //using merge sort to count the number of values in left and right
        mergeSort(pos, arr, 0, nums1.size()-1);
        long long result = 0;
        //getting the count of total triplets possible.
        for(int i = 0; i< left.size(); i++)
        {
            result += (long long)left[i]*(long long)right[i];
        }
        return result;
    }
};