//
//  main.cpp
//  Leetcode-912
//
//  Created by Jing Luo on 4/4/22.
//

#include <iostream>
#include <vector>

using namespace std;

// TLE, quick sort time 为O(NlogN), 如果nums已经是排好序，那么会退化成O(n*n)，所以才会TLE，
// 关键点就是要随机取一个数作为pivot，将它交换到end位置
void quickSort(vector<int>& nums, int start, int end) {
    if (start >= end) return;
    // randomized_partition
    int i = rand() % (end - start + 1) + start; // 随机选一个作为我们的主元
    swap(nums[end], nums[i]); //交换
    // partition
    int pivot = nums[end];
    int left = start, right = start;
    while (left < end && right < end) {
        if (nums[right] < pivot) {
            swap(nums[left], nums[right]);
            left ++;
        }
        right ++;
    }
    swap(nums[left], nums[right]);
    // randomized_quicksort
    quickSort(nums, start, left-1);
    quickSort(nums, left+1, end);
}


// 桶排序，time: O(n), space: O(n)
vector<int> countingSort(vector<int>& nums) {
    vector<int> counting(100005, 0);
    for (auto num: nums) {
        counting[num+50000] ++;
    }
    vector<int> result;
    for (int i = 0; i <= 100000; i ++) {
        while (counting[i] > 0) {
            result.emplace_back(i-50000);
            counting[i] --;
        }
    }
    return result;
}

vector<int> sortArray(vector<int>& nums) {
    quickSort(nums, 0, (int)nums.size()-1);
    return nums;
//    return countingSort(nums);
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {5,1,1,2,0,0};
    std::cout << sortArray(nums).size() << "\n";
    return 0;
}
