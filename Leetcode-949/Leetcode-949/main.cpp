//
//  main.cpp
//  Leetcode-949
//
//  Created by Jing Luo on 9/2/20.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

// 1: 0,1,2
// 2: 0,1,2,3,4,5,6,7,8,9
// 3: 0,1,2,3,4,5
// 4: 0,1,2,3,4,5,6,7,8,9

vector<vector<int>> availables = {{0,1,2}, {0,1,2,3,4,5,6,7,8,9}, {0,1,2,3,4,5}, {0,1,2,3,4,5,6,7,8,9}};
vector<int> times;
vector<int> result;

bool availableTime(vector<int> time) {
    int hour = time[0] * 10 + time[1];
    int minute = time[2] * 10 + time[3];
    if (hour <= 23 && minute <= 59) {
        return true;
    }
    return false;
}
bool isGreater(vector<int> newTime, vector<int> oldTime) {
    int oldtime = oldTime[0] * 1000 + oldTime[1] * 100 + oldTime[2] * 10 + oldTime[3];
    int newtime = newTime[0] * 1000 + newTime[1] * 100 + newTime[2] * 10 + newTime[3];
    return newtime > oldtime;
}

void help(int index, vector<int>& A, set<int>& visited) {
    if (times.size() == 4 && availableTime(times)) {
        if (result.empty()) {
            result = times;
        } else if (isGreater(times, result)) {
            result = times;
        }
        return;
    }
    for (int i = 0; i < A.size(); i ++) {
        if (visited.find(i) != visited.end()) {
            continue;
        }
        if (find(availables[index].begin(), availables[index].end(), A[i]) != availables[index].end()) {
            visited.insert(i);
            times.push_back(A[i]);
            help(index + 1, A, visited);
            visited.erase(i);
            times.erase(times.end()-1);
        }
    }
}

string largestTimeFromDigits(vector<int>& A) {
    set<int> visisted;
    help(0, A, visisted);
    string res = "";
    for (int i = 0; i < result.size(); i ++) {
        res += result[i] + '0';
        if (i == 1) {
            res += ':';
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> A = {2,0,6,6};//{1,3,3,4};//{3,3,3,3};
    std::cout << largestTimeFromDigits(A) << "\n";
    return 0;
}


/*
 DFS暴力枚举4个数字全排列的所有24种(4*3*2*1)可能，判断每一种排列是否合法，跟保存的结果进行大小对比，取最大值
 time: O(n!)但是这里n永远等于4,变相可以视为O(1), space: O(1)
 */
