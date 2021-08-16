//
//  main.cpp
//  Leetcode-451
//
//  Created by Jing Luo on 8/15/21.
//

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

string frequencySort(string s) {
    unordered_map<char, int> chars;
    for (auto c: s) {
        chars[c] ++;
    }
    map<int, string, greater<>> frequencyChar;
    for (auto& c: chars) {
        int n = c.second;
        frequencyChar[n] += string(n, c.first); // map的查找和插入都是O(LogN)
    }
    string result = "";
    for (auto& it: frequencyChar) {
        result += it.second;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    std::cout << frequencySort("sdsfdse") << "\n";
    return 0;
}


/*
 桶排序的思想，map会根据key自动排序，time: O(n), n=s.length, space: O(n)
 */

