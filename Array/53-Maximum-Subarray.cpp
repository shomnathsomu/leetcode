#include<bits/stdc++.h>
using namespace std;

vector<int> arr;

class solution{
public:
    int maxSubArray(vector<int>& nums){
        int n = nums.size();

        return binarySumArray(nums, 0, n-1);
    }

    int binarySumArray(vector<int>& nums, int low, int high){

        if(high <= low) return nums[low];

        int mid = (low+high)/2;

        int maxLeft = INT_MIN;
        int sum=0;

        for(int i = mid; i>=low; i--){
            sum += nums[i];
            if(sum > maxLeft){
                maxLeft = sum;
            }
        }

        int maxRight = INT_MIN;
        sum=0;

        for(int j = mid+1; j<=high; j++){
            sum += nums[j];
            if(sum > maxRight){
                maxRight = sum;
            }
        }

        int maxLeftRight = max(binarySumArray(nums, low, mid), binarySumArray(nums, mid+1, high));

        return max(maxLeftRight, maxLeft+maxRight);

    }
};

int main(int argc, const char* argv[]){

    int n, num;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &num);
        arr.push_back(num);
    }

    solution sol;
    int res = sol.maxSubArray(arr);

    cout << res << endl;

    return 0;
}

/*
7
2 -4 1 9 -6 7 -3
9
-2 1 -3 4 -1 2 1 -5 4
*/
