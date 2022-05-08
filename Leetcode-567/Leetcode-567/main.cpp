//
//  main.cpp
//  Leetcode-567
//
//  Created by Jing Luo on 3/1/22.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
void removeCharIn(string& s, char a) {
    for (int i = 0; i < s.length(); i ++) {
        if (s[i] == a) {
            s.erase(i, 1);
            return;
        }
    }
}

bool findCharIn(string s, char a) {
    return s.find(a) != s.npos;
}

bool checkInclusion(string s1, string s2) {
    int start = 0, end = 0, lenght = (int)s1.length();
    while (start < s2.length()) {
        if (s1.length() == lenght && findCharIn(s1, s2[start])) {
            end = start;
            while (end < s2.length()) {
                if (findCharIn(s1, s2[end])) {
                    removeCharIn(s1, s2[end]);
                    if (s1.empty()) {
                        return true;
                    }
                    end ++;
                } else {
                    s1 += s2[start];
                    if (lenght == s1.length()) {
                        break;
                    }
                    start ++;
                }
            }
        }
        start ++;
    }
    return false;
}*/


bool checkInclusion(string s1, string s2) {
    int n = s1.length(), m = s2.length();
    if (n > m) {
        return false;
    }
    vector<int> cnt1(26), cnt2(26);
    for (int i = 0; i < n; ++i) {
        ++cnt1[s1[i] - 'a'];
        ++cnt2[s2[i] - 'a'];
    }
    if (cnt1 == cnt2) {
        return true;
    }
    for (int i = n; i < m; ++i) {
        ++cnt2[s2[i] - 'a'];
        --cnt2[s2[i - n] - 'a'];
        if (cnt1 == cnt2) {
            return true;
        }
    }
    return false;
}
                                                                     
int main(int argc, const char * argv[]) {
    string s1 = "soosg";
    string s2 = "dydsoosoosg";
    std::cout << checkInclusion(s1, s2) << "\n";
    return 0;
}
