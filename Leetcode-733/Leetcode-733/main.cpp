//
//  main.cpp
//  Leetcode-733
//
//  Created by Jing Luo on 3/12/22.
//

#include <iostream>
#include <vector>

using namespace std;

void helper(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor) {
    int n = image.size();
    int m = image[0].size();
    
    image[sr][sc] = newColor;
    
    int dir[8] = {0,1,1,0,0,-1,-1,0};
    for (int i = 0; i < 8; i += 2) {
        int newR = sr + dir[i];
        int newC = sc + dir[i+1];
        if (newR < 0 || newR >= n || newC < 0 || newC >= m) {
            continue;
        }
        if (image[newR][newC] != oldColor || image[newR][newC] == newColor) {
            continue;
        }
        helper(image, newR, newC, oldColor, newColor);
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int n = image.size();
    int m = image[0].size();
    
    helper(image, sr, sc, image[sr][sc], newColor);
    return image;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>> newImage = floodFill(image, 1, 1, 2);
    std::cout << "\n";
    return 0;
}
