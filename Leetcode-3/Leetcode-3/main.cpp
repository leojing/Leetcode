//
//  main.cpp
//  Leetcode-3
//
//  Created by Jing Luo on 8/5/20.
//

#include <iostream>
#include <set>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int maxLength = 0;
    int i = 0, j = 0;
    int length = int(s.size());
    if (length == 0) {
        return 0;
    }
    set<int> exsit;
    for (i = 0; i < length; i ++) {
        if (exsit.find(s[i]) == exsit.end()) {
            exsit.insert(s[i]);
            maxLength = max(int(exsit.size()), maxLength);
        } else {
            while (exsit.find(s[i]) != exsit.end()) {
                exsit.erase(s[j]);
                j ++;
            }
            exsit.insert(s[i]);
        }
    }
    return maxLength;
}

int main(int argc, const char * argv[]) {
    std::cout << lengthOfLongestSubstring("aaccaabbcbb") << "\n";
    return 0;
}

/*
 ###算法
 sliding window
 
 ###代码实现
 ***有什么要注意的地方
 参照代码，已注释
 ***有什么要优化的地方
 
 ###时空复杂度
 time O(n)
 space O(n)
 
 ###相关的题目有哪些
 */

