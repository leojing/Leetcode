//
//  main.cpp
//  Leetcode-436
//
//  Created by Jing Luo on 9/2/20.
//

#include <iostream>
#include <vector>

using namespace std;

struct Interval {
public:
    int start;
    int end;
    int index;
    Interval(int start, int end, int index) {
        this->start = start;
        this->end = end;
        this->index = index;
    }
};

struct Cmp {
    bool operator()(const Interval& lhs, const Interval& rhs) {
        if (lhs.start == rhs.start) {
            return lhs.end < rhs.end;
        }
        return lhs.start < rhs.start;
    }
};

int binarySearchHelper(vector<Interval>& array, int start, int end, int k) {
    // solution 1: recursion
    if (start > end) {
        return -1;
    }
    Interval target = array[k];
    if (start + 1 < end) {
        int mid = start + (end - start)/2;
        Interval midIntervl = array[mid];
        if (midIntervl.start < target.end) {
            return binarySearchHelper(array, mid, end, k); // 因为是要找左边👈第一个符合要求的，所以没有判断mid，不需要+1
        } else {
            return binarySearchHelper(array, start, mid, k); // 同上，不需要-1
        }
    }
    Interval startInterval = array[start];
    if (startInterval.start >= target.end) {
        return startInterval.index;
    }
    Interval endInterval = array[end];
    if (endInterval.start >= target.end) {
        return endInterval.index;
    }

    /* solution 2: No-recursion
    while (start <= end) {
        int mid = start + (end - start)/2;
        Interval midIntervl = array[mid];
        if (midIntervl.start < target.end) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    if (start < array.size()) {
        return array[start].index;
    }
     */
    return -1;
}

vector<int> findRightInterval(vector<vector<int>>& intervals) {
    vector<int> result(intervals.size(), -1);
    vector<Interval> array;
    for (int i = 0; i < intervals.size(); i ++) {
        array.push_back(Interval(intervals[i][0], intervals[i][1], i));
    }
    sort(array.begin(), array.end(), Cmp());
    int length = int(array.size());
    for (int i = 0; i < length; i ++) {
        Interval curr = array[i];
        // solution 1: 这里的顺序查找可以优化成binary search
//        int j = i+1;
//        while (j < length) {
//            Interval temp = array[j];
//            if (temp.start >= curr.end) {
//                result[curr.index] = temp.index;
//                break;
//            }
//            j ++;
//        }
        // solution 2: Binary search
        result[curr.index] = binarySearchHelper(array, i+1, length-1, i);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> intervals = {{1,12},{2,9},{3,10},{13,14},{15,16},{16,17}};//{{4,5},{2,3},{1,2}};//{{3,4}, {2,3}, {1,2}};//{{1,4},{2,3},{3,4}};//{{3,4}, {2,3}, {1,2}};
    vector<int> result = findRightInterval(intervals);
    std::cout << result.size() << "\n";
    return 0;
}

/*
 Solution 1:
 sorting takes O(NLogN) time
 searching takes O(N!) time
 Space: O(N)
 
 Solution 2:
 sorting takes O(NLogN) time
 searching takes O(NLongN) time
 Space: O(N)
 时间上差不多比Solution 1快3倍
 */
