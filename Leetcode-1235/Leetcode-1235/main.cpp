//
//  main.cpp
//  Leetcode-1235
//
//  Created by Jing Luo on 6/18/22.
//

#include <iostream>
#include <vector>

using namespace std;

typedef tuple<int, int, int> Job;
struct Cmp {
    bool operator()(const Job& lhs, const Job& rhs) {
        if (get<1>(lhs) == get<1>(rhs)) {
            return get<0>(lhs) < get<0>(rhs);
        }
        return get<1>(lhs) < get<1>(rhs);
    }
};

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = profit.size();
    if (n == 0) {
        return 0;
    }
    vector<int> dp(n); // dp[i] means till at job[i], the max value it could be
    vector<Job> jobs;
    for (int i = 0; i < n; i ++) {
        jobs.emplace_back(make_tuple(startTime[i], endTime[i], profit[i]));
    }
    sort(jobs.begin(), jobs.end(), Cmp());
    dp[0] = get<2>(jobs[0]);
    for (int i = 1; i < n; i ++) {
        int s = 0, e = i-1, pre = 0;
        // binary search 👇
        while (s + 1 < e) {
            int mid = s + ((e - s) >> 2);
            if (get<1>(jobs[mid]) <= get<0>(jobs[i])) {
                pre = dp[mid];
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        if (get<1>(jobs[s]) <= get<0>(jobs[i])) {
            pre = dp[s];
        }
        if (get<1>(jobs[e]) <= get<0>(jobs[i])) {
            pre = dp[e];
        }
        // binary search 👆
        dp[i] = max(dp[i-1], get<2>(jobs[i]) + pre);
        /* for current job, there are two choice:
            1) not pick it, then it's max value will be dp[i-1], doesn't matter if it's overlapping with previous job.
            2) pick it, then find the most close dp[j] which is not overlapping with jobs[i]. The more close, the value will be more large.
         */
    }
    return dp[n-1];
}

int main(int argc, const char * argv[]) {
    
    vector<int> startTime = {1,2,3,3};
    vector<int> endTime = {3,4,5,6};
    vector<int> profit = {50,10,40,70};
    
    /*
    vector<int> startTime = {6,15,7,11,1,3,16,2};
    vector<int> endTime = {19,18,19,16,10,8,19,8};
    vector<int> profit = {2,9,1,19,5,7,3,19};
    */
    std::cout << jobScheduling(startTime, endTime, profit) << "\n";
    return 0;
}

// time: O(NLogN), space: O(n)
