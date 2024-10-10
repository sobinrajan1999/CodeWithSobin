//Question: https://leetcode.com/problems/data-stream-as-disjoint-intervals

class SummaryRanges {
public:
    // using vector to store the intervals
    std::vector<vector<int>> arr;
    // using binary search to calculate the index where the value should go.
    int binarySearch(int target) {
        int start = 0;
        int end = arr.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            // if the value already lies within the range. we don't need to find
            // the index of it.
            if (arr[mid][0] <= target and arr[mid][1] >= target) {
                return -1;
            }
            // trying to the find the index based on the max value of the
            // interval.
            if (arr[mid][1] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }

    SummaryRanges() {}

    void addNum(int value) {
        // if the array is empty
        if (arr.empty()) {
            arr.push_back({value, value});
            return;
        }
        // using binary search to find the index of the value.
        int index = binarySearch(value);
        // std::cout<<"index: "<<index<<std::endl;
        // this means the value is already present in the array. no need for
        // insertion
        if (index == -1) {
            return;
        }
        // if the interval of the left of index is 1 less than the current
        // "value" then the "value" can be included into the interval
        if (index > 0 and (value - arr[index - 1][1]) == 1) {
            // if the interval of the right of index is also 1 less than the
            // current "value" then both the intervals will be merged together.
            if (index < arr.size() and (arr[index][0] - value) == 1) {
                arr[index][0] = arr[index - 1][0];
                arr.erase(arr.begin() + index - 1);
            }
            // else insert only into the left interval
            else {
                arr[index - 1][1] = value;
            }
        }
        // if the "value" is adding into the right interval then add it into
        // right interval
        else if (index < arr.size() and (arr[index][0] - value) == 1) {
            arr[index][0] = value;
        }
        // in this case the "value" is not coming under any interval so insert
        // it into the position given by the binary search.
        else {
            arr.insert(arr.begin() + index, {value, value});
        }
    }

    vector<vector<int>> getIntervals() { return arr; }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */