#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums);
};

int Solution::removeDuplicates(vector<int> &nums) {
    int i, iCount, iNum, k, rk;
    k = 0;
    iNum = 100000;
    rk = 0;
        
    // Go through array
    for (i = 0; i < nums.size(); i++) {
    // If integer has not been encountered set to new one
    if (iNum != nums[i]) {
        iNum = nums[i];
        // Has been seen so far once
        iCount = 1;
    }
    else {
        iCount++;
    }
    nums[i-rk] = iNum;
        if (iCount < 3) {
            k++;
        }
        else {
            rk++;
        }
    }
    return k;
}