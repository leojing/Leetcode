//
//  main.cpp
//  Leetcode-524
//
//  Created by Jing Luo on 7/23/21.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Cmp {
    bool operator()(const string& lhs, const string& rhs) {
        if (lhs.size() == rhs.size()) {
            return lhs < rhs;
        }
        return lhs.size() > rhs.size();
    }
};

// time: O(x), x refers to the average string size
bool validWord(string s, string t) {
    int sIndex = 0, tIndex = 0;
    int sSize = (int)s.size(), tSize = (int)t.size();
    if (sSize < tSize) {
        return false;
    }
    while (sIndex < sSize && tIndex < tSize) {
        if (s[sIndex] == t[tIndex]) {
            tIndex ++;
        }
        sIndex ++;
    }
    return tIndex == tSize;
}

string findLongestWord(string s, vector<string>& dictionary) {
    sort(dictionary.begin(), dictionary.end(), Cmp()); // time: (x*nLogN), space: O(logN), n refers to the number of strings in dictionary
    // time: O(n*x)
    for (auto t : dictionary) {
        if (validWord(s, t)) {
            return t;
        }
    }
    return "";
}

// solution 2: 可以不用sorting，一边判断valid一边取最优值，这样time: O(n*x), space: O(x), 因为要申请一个result string的变量来保存结果

int main(int argc, const char * argv[]) {
    string s = "abpcplea";
    vector<string> dic = {"ale","apple","pplea","monkey","plea"};
    std::cout << findLongestWord(s, dic) << "\n";
    return 0;
}


// time: (n*xLogN + n*x), Space complexity : O(logN). Sorting takes O(logN) space in average case.
