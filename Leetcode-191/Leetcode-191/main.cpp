//
//  main.cpp
//  Leetcode-191
//
//  Created by Jing Luo on 3/28/22.
//

#include <iostream>

/*
int hammingWeight(uint32_t n) {
    int result = 0;
    while (n) {
        n = n & (n-1); // 依次移除最后一个1，知道n为0，即全部为0
        result ++;
    }
    return result;
}*/

int hammingWeight(uint32_t n) {
    int result = 0;
    for (int i = 0; i < 32; i ++) {
        if (n & (1 << i)) { // 将0-32的位置依次设置为1，与n进行&，如果n的i位置也是1，即结果为1，否则为0（可知此位置为0）
            result ++;
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    std::cout << hammingWeight(54) << "\n";
    return 0;
}
