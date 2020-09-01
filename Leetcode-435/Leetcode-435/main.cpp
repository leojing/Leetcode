//
//  main.cpp
//  Leetcode-435
//
//  Created by Jing Luo on 8/27/20.
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

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    vector<Interval> array;
    int result = 0;
    Interval previous;
    for (auto i : intervals) {
        array.push_back(Interval(i[0], i[1]));
    }
    sort(array.begin(), array.end(), Cmp());
    for (auto i : array) {
        if (result == 0) {
            previous = i;
            result += 1;
            continue;
        }
        if (i.first >= previous.second) {
            previous = i;
            result += 1;
        } else {
            if (i.second < previous.second) {
                previous = i;
            }
        }
    }
    return int(intervals.size()) - result;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> intervals {{1,2}};//{{1,2},{2,3}};//{{1,2},{1,2},{1,2}};//{{1,2},{2,3},{3,4},{1,3}};
    std::cout << eraseOverlapIntervals(intervals) << "\n";
    return 0;
}

// greedy贪心算法，time: O(n), space: O(n)
