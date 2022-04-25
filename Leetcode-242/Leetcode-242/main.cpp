//
//  main.cpp
//  Leetcode-242
//
//  Created by Jing Luo on 4/26/22.
//

#include <iostream>
#include <unordered_map>

using namespace std;

void mapping(string s, unordered_map<char, int>& mapping) {
    for (auto ch: s) {
        mapping[ch] ++;
    }
}

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    unordered_map<char, int> sMap, tMap;
    mapping(s, sMap);
    mapping(t, tMap);
    if (sMap == tMap) return true;
    return false;
}

int main(int argc, const char * argv[]) {
    std::cout << isAnagram("abc", "cba") << "\n";
    return 0;
}

// time: O(n)
// space: O(n)
