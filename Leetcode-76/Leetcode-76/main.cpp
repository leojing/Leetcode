//
//  main.cpp
//  Leetcode-76
//
//  Created by Jing Luo on 7/19/21.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string minWindow(string s, string t) {
    // space: O(1)
    vector<int> need(128, 0);
    // time: O(n)
    for (auto c : t) {
        need[c] ++;
    }
    int count = 0, left = 0, min_left = 0, min_size = INT_MAX;
    // time: O(m)
    for (int right = 0; right < s.size(); right ++) {
        if (need[s[right]] > 0) { //如果存在于t中，count+1
            count ++;
        }
        need[s[right]] --; // 如果不存在于t中，则会<0
        if (count == t.size()) {
            while (left < right && need[s[left]] < 0) { // 去掉前面无关紧要的字符
                need[s[left]] ++;
                left ++;
            }
            if (right - left + 1 < min_size) { // 替换成最优解
                min_size = right - (min_left = left) + 1;
            }
            // 将left往后移动一位，继续找新的解
            need[s[left]] ++;
            left ++;
            count --;
        }
    }
    return min_size == INT_MAX ? "" : s.substr(min_left, min_size);
}

int main(int argc, const char * argv[]) {
//    string s = "a";
//    string t = "b";
    
//    string s = "bba";
//    string t = "ab";
    
    string s = "ADOBECODEBANC";
    string t = "ABC";
//
//    string s = "addbasa";
//    string t = "aba";
    std::cout << minWindow(s, t) << "\n";
    return 0;
}


/*
 time: O(n+m), space: O(1)
 */
