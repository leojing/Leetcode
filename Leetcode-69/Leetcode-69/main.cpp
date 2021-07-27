//
//  main.cpp
//  Leetcode-69
//
//  Created by Jing Luo on 7/27/21.
//

#include <iostream>

int mySqrt(int x) {
    if (x == 0) {
        return 0;
    }
    int start = 0, end = x;
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        int temp = x / mid; // 注意这里不可以用 mid*mid，因为x为最大的integer，temp会越界, 或者 为了防止 int 超上界，temp使用 long 来存储乘法结果。
        if (temp == mid) {
            return mid;
        } else if (temp > mid) {
            start = mid;
        } else {
            end = mid;
        }
    }
    if (x / end == end) { // 注意这里不可以用 end*end，因为x为最大的integer，会越界
        return end;
    }
    return start;
}

int main(int argc, const char * argv[]) {
    std::cout << mySqrt(9) << "\n";
    return 0;
}
