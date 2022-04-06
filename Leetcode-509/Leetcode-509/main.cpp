//
//  main.cpp
//  Leetcode-509
//
//  Created by Jing Luo on 4/6/22.
//

#include <iostream>
using namespace std;

int f[31] = {0};

int fib(int n) {
    if (n <= 1) {
        f[n] = n;
        return f[n];
    }
    if (f[n]) {
        return f[n];
    }
    f[n] = fib(n-1) + fib(n-2);
    return f[n];
}

int main(int argc, const char * argv[]) {
    std::cout << fib(5) << "\n";
    return 0;
}

/*
 time: O(n), space: O(n)
 */
