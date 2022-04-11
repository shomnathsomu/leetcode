#include <bits/stdc++.h>
using namespace std;

// Negative marking approach

// Time Complexity: O(n)
// Space Complexity: O(1)

vector<int> nums;

class Solution{
public:
    int findDuplicate(vector<int>& nums){
        int duplicate=-1;
        for(int i=0; i<nums.size(); i++){
            int cur = abs(nums[i]);
            if(nums[cur] < 0){
                duplicate = cur;
                break ;
            }

            nums[cur] = nums[cur]*-1;
        }

        for(auto& num: nums)
            num = abs(num);

        return duplicate;
    }
};

int main(int argc, const char * argv[]) {

    DI(n);
    int num;
    for(int i=0; i<n; i++) {
        scanf("%d", &num);
        nums.push_back(num);
    }

    Solution sol;
    int res = sol.findDuplicate(nums);

    printf("%d\n", res);

    return 0;
}