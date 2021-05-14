#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int index = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[index] != nums[i])
                nums[++index] = nums[i];
        }
        return index + 1;
    }
};

int rm_dup_v(T* arr, int len){
    if (len <= 0) return 0;

    int idx = 0;
    for (int i = 1; i < len; i++){
        if (arr[idx] != arr[i]){
            arr[++idx] = arr[i];
        }
    }
}


int main(int argc, char** argv){
    vector<int> nums{1,2,3,4,4,5,5,5,6,7,7};
    Solution so;
    so.removeDuplicates(nums);
    for (auto n:nums){
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0;
}

