//
//  main.cpp
//  Leetcode-1103
//
//  Created by Jing Luo on 8/17/20.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> distributeCandies(int candies, int num_people) {
    vector<int> result(num_people);
    int index = 0;
    int currCandy = 1;
    while (candies > 0) {
        if (candies - currCandy > 0) {
            result[index] += currCandy;
        } else {
            result[index] += candies;
        }
        candies -= currCandy;
        currCandy ++;
        index ++;
        if (index == num_people) {
            index = 0;
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> result = distributeCandies(78, 4);
    return 0;
}



/*
###算法
模拟题

###代码实现
***有什么要注意的地方
参照代码，已注释
***有什么要优化的地方

###时空复杂度
time O(candies)
space O(num_people)

###相关的题目有哪些
*/
