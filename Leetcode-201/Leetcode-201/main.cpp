//
//  main.cpp
//  Leetcode-201
//
//  Created by Jing Luo on 3/30/22.
//

#include <iostream>

/* Solution 1：移位法
// m 5 1 0 1
//   6 1 1 0
// n 7 1 1 1
// 把可能包含0的全部右移变成
// m 5 1 0 0
//   6 1 0 0
// n 7 1 0 0
// 所以最后结果就是m<<count

至于为什么只需要判断m，n是否有公共前缀，因为m是最小的，如果最小的数和最大的数在x位上都存在1，那么他们之间的数肯定也在x位上存在1
time: O(logN), space: O(1)
 */
int rangeBitwiseAnd1(int left, int right) {
    int count = 0;
    while (left != right) {
        left >>= 1;
        right >>= 1;
        count ++;
    }
    return left << count;
}

// Solution 2: 汉明重量，不断移除right的最后一个1，直到它小于等于left，意味着已经找到left和right的公共前缀
// time: O(logN), space: O(1)
int rangeBitwiseAnd(int left, int right) {
    while (left < right) {
        right &= right - 1;
    }
    return right;
}

int main(int argc, const char * argv[]) {
    std::cout << rangeBitwiseAnd(2, 10) << "\n";
    return 0;
}


/*
 Solution 1:

 */
