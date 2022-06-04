//
//  main.cpp
//  Leetcode-763
//
//  Created by Jing Luo on 6/4/22.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> partitionLabels(string s) {
    vector<int> result;
    int n = s.size();
    vector<int> lastPos(26, -1);
    for (int i = n - 1; i >= 0; i --) {
        lastPos[s[i] - 'a'] = max(lastPos[s[i] - 'a'], i);
    }
    int start = 0, end = lastPos[s[0] - 'a'];
    for (int i = 1; i < n; i ++) {
        if (i > end) {
            result.emplace_back(end - start + 1);
            start = i;
            end = lastPos[s[i] - 'a'];
        } else {
            end = max(lastPos[s[i] - 'a'], end);
        }
    }
    result.emplace_back(end - start + 1);
    return result;
}

int main(int argc, const char * argv[]) {
    std::cout << partitionLabels("sahhvjkdbfe").size() << "\n";
    return 0;
}

// time: O(n), space: O(26)
