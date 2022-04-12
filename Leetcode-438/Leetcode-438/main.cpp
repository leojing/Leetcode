//
//  main.cpp
//  Leetcode-438
//
//  Created by Jing Luo on 4/12/22.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    if (s.length() < p.length()) return {};
    
    int need[128] = {0};
    int count = 0;
    for (auto c: p) {
        need[c] ++;
    }
    int left = 0, right = 0;
    vector<int> result;
    // find first window
    while (right < p.length()) {
        need[s[right]] --;
        if (need[s[right]] >= 0) {
            count ++;
        }
        right ++;
        if (count == p.length()) {
            result.emplace_back(left);
        }
    }
    right --;
    // from first window, move left ++ & right ++ every time and see if new left & new right meet requirement.
    while (right < s.length() - 1) {
        if (need[s[left]] >= 0) {
            count --;
        }
        need[s[left]] ++;
        left ++;
        
        right ++;
        need[s[right]] --;
        if (need[s[right]] >= 0) {
            count ++;
        }
        if (count == p.length()) {
            result.emplace_back(left);
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    string s = "aaaaaasaaaa";
    string p = "aaaaa";
    vector<int> result = findAnagrams(s, p);
    std::cout << result.size() << "\n";
    return 0;
}


/*
 time: O(n), n is s.length()
 space: O(128) ~= O(1)
 */
