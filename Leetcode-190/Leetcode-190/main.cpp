//
//  main.cpp
//  Leetcode-190
//
//  Created by Jing Luo on 3/30/22.
//

#include <iostream>

uint32_t reverseBits(uint32_t n) {
    int pow = 31;
    uint32_t result = 0;
    while (n) {
        result += (n & 1) << pow; // result |= (n & 1) << pow; | 或运算即位+
        n >>= 1;
        pow --;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    std::cout << reverseBits(5434) << "\n";
    return 0;
}

// time: O(32), space: O(1)
