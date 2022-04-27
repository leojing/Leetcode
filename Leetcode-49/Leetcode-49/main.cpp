//
//  main.cpp
//  Leetcode-49
//
//  Created by Jing Luo on 4/27/22.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* Solution 1: time: O(m*NLogN), m is strs.length, n is strs[i].length
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mapping;
    for (auto str: strs) {
        string newS = str;
        sort(newS.begin(), newS.end());
        if (mapping.find(newS) == mapping.end()) {
            mapping[newS] = vector<string>();
        }
        mapping[newS].emplace_back(str);
    }
    vector<vector<string>> result;
    for (auto m: mapping) {
        result.emplace_back(m.second);
    }
    return result;
}
*/
    
// Solution 2: time: O(m*n*26) = O(m*n), m is strs.length, n is strs[i].length

string count(string s) {
    int ch[26] = {0};
    for (auto c: s) {
        ch[c-'a'] ++;
    }
    string result;
    for (int i = 0; i <= 25; i ++) {
        if (ch[i] > 0) {
            result += to_string(ch[i]);
            result += 'a' + i;
        }
    }
    return result;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mapping;
    for (auto str: strs) {
        string key = count(str);
        if (mapping.find(key) == mapping.end()) {
            mapping[key] = vector<string>();
        }
        mapping[key].emplace_back(str);
    }
    vector<vector<string>> result;
    for (auto m: mapping) {
        result.emplace_back(m.second);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = groupAnagrams(strs);
    std::cout << result.size() << "\n";
    return 0;
}
