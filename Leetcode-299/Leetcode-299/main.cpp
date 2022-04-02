//
//  main.cpp
//  Leetcode-299
//
//  Created by Jing Luo on 4/2/22.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getHint(string secret, string guess) {
    int bulls = 0;
    int cows = 0;
    vector<int> sMap(10, 0);
    vector<int> gMap(10, 0);
    for (int i = 0; i < secret.size(); i ++) {
        if (secret[i] == guess[i]) {
            bulls ++;
        } else {
            sMap[secret[i] - '0'] ++;
            gMap[guess[i] - '0'] ++;
        }
    }
    for (int i = 0; i < 10; i ++) {
        cows += min(sMap[i], gMap[i]);
    }
    return to_string(bulls) + "A" + to_string(cows) + "B";
}

int main(int argc, const char * argv[]) {
    string secret = "18393";
    string guess = "73653";
    std::cout << getHint(secret, guess) << "\n";
    return 0;
}
