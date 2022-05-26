//
//  main.cpp
//  Leetcode-875
//
//  Created by Jing Luo on 5/26/22.
//

#include <iostream>
#include <vector>

using namespace std;

int eatingHours(vector<int>& piles, int k) {
    int h = 0;
    for (auto pile: piles) {
        h += pile / k;
        if (pile % k != 0) {
            h += 1;
        }
    }
    return h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int start = 1, end = INT_MIN;
    for (auto pile: piles) {
        end = max(pile, end);
    }
    while (start + 1 < end) {
        int mid = start + ((end - start) >> 1);
        int midH = eatingHours(piles, mid);
        if (midH <= h) {
            end = mid;
        } else {
            start = mid;
        }
    }
    int startH = eatingHours(piles, start);
    if (startH <= h) {
        return start;
    }
    int endH = eatingHours(piles, end);
    if (endH <= h) {
        return end;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    vector<int> piles = {333};
    std::cout << minEatingSpeed(piles, 332) << "\n";
    return 0;
}

// time: O(log(max)*piles.length), space: O(1)
