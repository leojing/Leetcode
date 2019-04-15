//
//  main.cpp
//  Leetcode-443
//
//  Created by JINGLUO on 10/4/19.
//  Copyright © 2019 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>

/* Solution 1: Time O(n), extra space
void append(char a, int count, std::string &result) {
    result.push_back(a);
    if (count != 1) {
        result.append(std::to_string(count));
    }
}

int compress(std::vector<char>& chars) {
    if (chars.size() == 0) {
        return 0;
    }
    char pre = chars[0];
    std::map<char, int> mapping;
    mapping[pre] = 1;
    int i;
    std::string result;
    for (i = 1; i < chars.size(); i ++) {
        if (chars[i] == pre) {
            mapping[pre] = mapping[pre] + 1;
        } else {
            append(pre, mapping[pre], result);
            mapping[pre] = 0;
            pre = chars[i];
            mapping[pre] = 1;
        }
    }
    append(pre, mapping[pre], result);
    if (result.size() < chars.size()) {
        return int(result.size());
    }
    
    return int(chars.size());
}
 */

/* Solution 2: Time O(n), no extra space */

int compress(std::vector<char>& chars) {
    int l = 0, i = 0, j = 0;
    for (j = 0; j < chars.size(); j ++) {
        if (j+1 == chars.size() || chars[j+1] != chars[j]) {
            chars[l++] = chars[j];
            if (i < j) {
                std::string len = std::to_string(j-i+1);
                for(char c:len) {
                    chars[l++] = c;
                }
            }
            i = j + 1;
        }
    }
    return l;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<char> chars = {'a','a','b','b','c','c','c'};
    std::cout << compress(chars) << "\n";
    return 0;
}
