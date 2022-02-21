//
//  main.cpp
//  Leetcode-278
//
//  Created by Jing Luo on 2/22/22.
//

#include <iostream>

bool isBadVersion(int n) {
    return random() % 2;
}

// Can't run as isBadVersion doesn't return correct answer

int firstBadVersion(int n) {
    int start = 1, end = n, mid;
    while(start + 1 < end) {
        mid = start + (end - start) / 2;
        if (isBadVersion(mid)) {
            end = mid;
        } else {
            start = mid;
        }
    }
    if (isBadVersion(start)) {
        return start;
    }
    return end;
}

int main(int argc, const char * argv[]) {
    std::cout << firstBadVersion(4) << "\n";
    return 0;
}
