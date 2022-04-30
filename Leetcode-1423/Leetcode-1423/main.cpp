//
//  main.cpp
//  Leetcode-1423
//
//  Created by Jing Luo on 4/30/22.
//

#include <iostream>
#include <vector>

using namespace std;

/* Solution 1: time: O(n), space: O(n)
int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    vector<int> frontSum;
    vector<int> tailSum(n);
    int points = 0;
    for (auto card: cardPoints) {
        points += card;
        frontSum.emplace_back(points);
    }
    points = 0;
    for (int i = n-1; i >= 0; i —) {
        points += cardPoints[i];
        tailSum[n-i-1] = points;
    }
    int result = 0;
    for (int i = 0; i <= k; i ++) {
        if (i == 0) {
            result = max(result, tailSum[k-1]);
    continue;
    }
    if (i == k) {
        result = max(result, frontSum[k-1]);
    continue;
    }
    result = max(result, frontSum[i-1] + tailSum[k-i-1]);
    }
    return result;
}*/

// time: O(n), space: (1)
int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int points = 0;
    for (int i = 0; i < k; i ++) {
        points += cardPoints[i];
    }
    int result = points;
    for (int i = k-1; i >= 0; i --) {
        points = points - cardPoints[i] + cardPoints[n - (k - i)];
        result = max(result, points);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    std::cout << maxScore(cardPoints, 3) << "\n";
    return 0;
}
