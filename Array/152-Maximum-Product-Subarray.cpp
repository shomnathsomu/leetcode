#include<bits/stdc++.h>
using namespace std;

vector<int> arr;

class solution{
public:
    int maxProduct(vector<int>& nums){
        int n = nums.size();

        return binaryProdArray(nums, 0, n-1);
    }

    int binaryProdArray(vector<int>& nums, int low, int high){

        if(high <= low) return nums[low];

        int mid = (low+high)/2;

        int maxLeft = INT_MIN;
        int minLeft = INT_MAX;
        int prod=1;

        for(int i = mid; i>=low; i--){
            prod *= nums[i];
            maxLeft = max(maxLeft, prod);
            minLeft = min(minLeft, prod);
        }

        int maxRight = INT_MIN;
        int minRight = INT_MAX;
        prod=1;

        for(int j = mid+1; j<=high; j++){
            prod *= nums[j];
            maxRight = max(maxRight, prod);
            minRight = min(minRight, prod);
        }

        int maxLeftRight = max(binaryProdArray(nums, low, mid), binaryProdArray(nums, mid+1, high));

        return max(maxLeftRight, max(maxLeft*maxRight, minLeft*minRight));

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
    int res = sol.maxProduct(arr);

    cout << res << endl;

    return 0;
}

/*
7
2 -4 1 9 -6 7 -3
9
-2 1 -3 4 -1 2 1 -5 4
*/
