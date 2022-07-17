//
//  main.cpp
//  Leetcode-973
//
//  Created by Jing Luo on 7/17/22.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<tuple<double, int, int>> pq;
    for (int i = 0; i < points.size(); ++ i) {
        int x = points[i][0];
        int y = points[i][1];
        double dis = sqrt(x * x + y * y);
        if (pq.size() < k) {
            pq.push(make_tuple(dis, x, y));
            continue;
        }
        tuple<double, int, int> top = pq.top();
        if (get<0>(top) > dis) {
            pq.pop();
            pq.push(make_tuple(dis, x, y));
        }
    }
    vector<vector<int>> result;
    while (!pq.empty()) {
        tuple<double, int, int> top = pq.top();
        pq.pop();
        vector<int> point = {get<1>(top), get<2>(top)};
        result.emplace_back(point);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> points = {{1,3},{-2,2}};
    std::cout << kClosest(points, 1).size() << "\n";
    return 0;
}

// time: O(n), space: O(k)
