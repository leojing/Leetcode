//
//  main.cpp
//  Leetcode-57
//
//  Created by Jing Luo on 9/16/20.
//

#include <iostream>
#include <vector>

using namespace std;

/*
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int start = -1, end = -1, length = int(intervals.size());
    bool canMerge = 0;
    bool doneMerge = 0;
    vector<vector<int>> result;
    if (length == 0) {
        return {newInterval};
    }
    for (int i = 0; i < length; i ++) {
        vector<int> current = intervals[i];
        if (doneMerge) {
            result.push_back(current);
            continue;
        }
        if (canMerge) {
            if (newInterval[1] < current[0]) {
                end = newInterval[1];
                result.push_back({start, end});
                result.push_back(current);
            } else if (newInterval[1] >= current[0] && newInterval[1] <= current[1]) {
                end = current[1];
                result.push_back({start, end});
            } else {
                if (i == length - 1) {
                    end = newInterval[1];
                    result.push_back({start, end});
                }
                continue;
            }
            doneMerge = true;
        } else {
            if (newInterval[0] < current[0]) {
                start = newInterval[0];
                canMerge = true;
                if (newInterval[1] < current[0]) {
                    end = newInterval[1];
                    doneMerge = true;
                    result.push_back({start, end});
                    result.push_back(current);
                } else if (newInterval[1] <= current[1]) {
                    end = current[1];
                    doneMerge = true;
                    result.push_back({start, end});
                } else {
                    if (i == length - 1) {
                        end = newInterval[1];
                        result.push_back({start, end});
                    }
                }
            } else if (newInterval[0] >= current[0] && newInterval[0] <= current[1]) {
                start = current[0];
                canMerge = true;
                if (newInterval[1] <= current[1]) {
                    doneMerge = true;
                    result.push_back(current);
                } else {
                    if (i == length - 1) {
                        end = newInterval[1];
                        result.push_back({start, end});
                    }
                }
            } else {
                result.push_back(current);
                if (i == length - 1) {
                    result.push_back(newInterval);
                }
            }
        }
    }
    return result;
}
*/

// Solution 2:
// First, put all intervals that are to the left of the inserted interval.
// Second, merge all intervals that intersect with the inserted interval.
// Finally, put all intervals that are to the right of the inserted interval.
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int index = 0;
    vector<vector<int>> result;
    int length = int(intervals.size());
    // left
    while (index < length && intervals[index][1] < newInterval[0]) {
        result.push_back(intervals[index]);
        index ++;
    }
    
    // intersect
    while (index < length && intervals[index][0] <= newInterval[1]) {
        newInterval[0] = min(intervals[index][0], newInterval[0]);
        newInterval[1] = max(intervals[index][1], newInterval[1]);
        index ++;
    }
    result.push_back(newInterval);
    
    // right
    while (index < length) {
        result.push_back(intervals[index]);
        index ++;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> intervals = {{0,3}, {6,8}, {9,12}};//{{1,5}};//{};//{{3,5},{6,7},{8,10},{17,19},{20,21},{23,24}};
    vector<int> newInterval = {0,4};
    vector<vector<int>> result = insert(intervals, newInterval);
    std::cout << result.size() << "\n";
    return 0;
}

/*
 Test case:
 {{1,5}} , {0,6}
 {{1,5}} , {2,7}
 {{1,5}} , {5,8}
 [[0,3],[6,8],[9,12]] , [0,4]
 */

// Time: O(n), Space: O(n)
