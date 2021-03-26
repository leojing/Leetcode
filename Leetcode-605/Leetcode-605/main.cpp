//
//  main.cpp
//  Leetcode-605
//
//  Created by Jing Luo on 3/26/21.
//

#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
   int i = 0;
   int size = int(flowerbed.size());
   for (i = 0; i < size; i ++) {
       if (flowerbed[i] == 1) {
           continue;
       }
       if ((i-1 >= 0 && flowerbed[i-1] == 0) || i - 1 < 0) {
           if ((i+1 < size && flowerbed[i+1] == 0) || i + 1 >= size) {
               n --;
               flowerbed[i] = 1;
           }
       }
   }
   return n <= 0; // 注意这里n可能会<0,因为遍历所有，找到的其实是最多能种多少花，有可能会比n多，所以前面n--会导致n<0的情况
}

int main(int argc, const char * argv[]) {
    vector<int> flowerbed = {0,0,1,0,0};
    std::cout << canPlaceFlowers(flowerbed, 1) << "\n";
    return 0;
}


/*
 test case:
 [0,0,0,0,0,1,0,0]
 0
 
 [0]
 1
 
 [1,0,0,1]
 2

 [0,0,0]
 1
 */
