//
//  main.cpp
//  Leetcode-452
//
//  Created by Jing Luo on 3/26/21.
//

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> Interval;

struct Cmp {
    bool operator()(const Interval& lhs, const Interval& rhs) {
       if (lhs.first == rhs.first) {
           return lhs.second < rhs.second;
       }
       return lhs.first < rhs.first;
   }
};

int findMinArrowShots(vector<vector<int>>& points) {
    if (points.size() == 0) {
        return 0;
    }
    vector<Interval> intervals;
    for (auto point: points) {
        intervals.push_back(Interval(point[0], point[1]));
    }
    sort(intervals.begin(), intervals.end(), Cmp());
    int start = intervals[0].first, end = intervals[0].second;
    int result = 1;
    for (int i = 1; i < intervals.size(); i ++) {
        Interval current = intervals[i];
        if (current.first >= start && current.first <= end) {
            start = current.first;
            if (current.second < end) {
                end = current.second;
            }
        } else {
            start = current.first;
            end = current.second;
            result ++;
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> points = {{1,2}, {2,3}, {3,4}}; //{{10,16},{2,8},{1,6},{7,12}};
    std::cout << findMinArrowShots(points) << "\n";
    return 0;
}


/*
 test case:
 [[10,16],[2,8],[1,6],[7,12]] = 2
 
 [] = 0
 
 [[1,2], [2,3], [3,4]] = 2
 
 [[1,2],[3,4],[5,6],[7,8]] = 4
 
 */
