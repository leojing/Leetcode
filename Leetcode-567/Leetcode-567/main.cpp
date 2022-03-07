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
}
                                                                     
int main(int argc, const char * argv[]) {
    string s1 = "adsc";
    string s2 = "dcda";
    std::cout << checkInclusion(s1, s2) << "\n";
    return 0;
}
