//
//  main.cpp
//  Leetcode-853
//
//  Created by Jing Luo on 5/22/22.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> Car;
    
struct Cmp {
    bool operator()(const Car& lhs, const Car& rhs) {
        return lhs.first < rhs.first;
    }
};

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    vector<Car> cars;
    for (int i = 0; i < n; i ++) {
        cars.emplace_back(make_pair(position[i], speed[i]));
    }
    sort(cars.begin(), cars.end(), Cmp());
    stack<double> stk;
    for (auto car: cars) {
        double time = double(target - car.first) / double(car.second);
        while (!stk.empty() && stk.top() <= time) {
            stk.pop();
        }
        stk.emplace(time);
    }
    return stk.size();
}

int main(int argc, const char * argv[]) {
    vector<int> position = {6,8};//{0,4,2};//{10,8,0,5,3};
    vector<int> speed = {3,2};//{2,1,3};//{2,4,1,1,3};
    std::cout << carFleet(10, position, speed) << "\n";
    return 0;
}


//  通过计算每辆车达到target需要的time来判断pos在前面的车是否会被后面的车追上，一旦追上，就需要跟速度慢的车（即前车）一起前进，循环找到所有能追上前车的后车，弹出stack，最后即可以将前车的time放置于stack的top中
// time: O(NLogN), sort time
// space: O(N), stack
