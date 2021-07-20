//
//  main.cpp
//  Leetcode-633
//
//  Created by Jing Luo on 7/21/21.
//

#include <iostream>

bool judgeSquareSum(int c) {
    int half = ceil(sqrt(c));
    for (int i = 0; i <= half; i ++) {
        double t = c - pow(i, 2);
        double sqrtT = sqrt(t);
        if (floor(sqrtT) == sqrtT) {
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    std::cout << judgeSquareSum(10) << "\n";
    return 0;
}
