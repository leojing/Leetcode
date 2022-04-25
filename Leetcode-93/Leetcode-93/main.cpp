//
//  main.cpp
//  Leetcode-93
//
//  Created by Jing Luo on 4/25/22.
//

#include <iostream>
#include <vector>

using namespace std;

bool isValid(string s) {
    int len = s.size();
    if (len > 1 && s[0] == '0') {
        return false;
    }
    int result = 0;
    for (int i = 0; i < len; i ++) {
        if (s[i] < '0' && s[i] > '9') {
            return false;
        }
        result = result * 10 + (s[i] - '0');
    }
    return result <= 255;
}

string join(vector<string> curr) {
    string res = "";
    for (int i = 0; i < curr.size()-1; i ++) {
        res += curr[i] + ".";
    }
    res += curr[curr.size()-1];
    return res;
}

void helper(string s, int index, vector<string> curr, vector<string>& result) {
    int len = s.length();
    if (curr.size() > 4) {
        return;
    }
    if (index >= len && curr.size() == 4) {
        result.emplace_back(join(curr));
        return;
    }
    for (int i = 1; i <= 3, index+i <= len; i ++) {
        string tempS = s.substr(index, i);
        if (isValid(tempS)) {
            curr.emplace_back(tempS);
            helper(s, index+i, curr, result);
            curr.pop_back();
        }
    }
}
    
vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    helper(s, 0, {}, result);
    return result;
}

int main(int argc, const char * argv[]) {
    vector<string> result = restoreIpAddresses("25525511135");
    std::cout << result.size() << "\n";
    return 0;
}


/*
 time: O(s.size() * 3^SEG_COUNT), 这里SEG_COUNT=4，要求分割成4段IP
 space: O(SEG_COUNT)
 
 我们用 SEG_COUNT=4 表示 IP 地址的段数。

 时间复杂度：O(3^SEG_COUNT×∣s∣)。由于 IP 地址的每一段的位数不会超过 3，因此在递归的每一层，我们最多只会深入到下一层的 3 种情况。由于 SEG_COUNT=4，对应着递归的最大层数，所以递归本身的时间复杂度为 O(3^SEG_COUNT)。如果我们复原出了一种满足题目要求的 IP地址，那么需要O(∣s∣) 的时间将其加入答案数组中，因此总时间复杂度为 O(3^SEG_COUNT ×∣s∣)。

 空间复杂度：O(SEG_COUNT)，这里只计入除了用来存储答案数组以外的额外空间复杂度。递归使用的空间与递归的最大深度SEG_COUNT 成正比。并且在上面的代码中，我们只额外使用了长度为 SEG_COUNT 的数组segments 存储已经搜索过的 IP 地址，因此空间复杂度为 O(SEG_COUNT)。
 
 */
