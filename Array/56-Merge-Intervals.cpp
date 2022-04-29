/**
* 56. Merge Intervals

* Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

*/

#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start, end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};

vector<Interval> intervals;

bool comp(const Interval lhs, const Interval rhs) {
    return (lhs.start == rhs.start) ? lhs.end < rhs.end : lhs.start < rhs.start;
}

vector<Interval> mergeInterval(vector<Interval> &intervals) {

    int l = intervals.size();
    vector<Interval> result;

    sort(intervals.begin(), intervals.end(), comp);

    // [2, 5] [3, 7]
    for (int j=0; j<l; j++) {
        int rSize = result.size();

        if(rSize > 0 && result[rSize-1].end >= intervals[j].start){
            result[rSize-1].end = max(result[rSize-1].end, intervals[j].end);
        }
        else {
            result.push_back(intervals[j]);
        }
    }

    return result;
}

int main (int argc, const char* argv[])
{
    Interval arr[10007];
    int num1, num2;

    for (int i=0; i<4; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
        intervals.push_back(arr[i]);
    }

    vector<Interval> r = mergeInterval(intervals);

    for (int k=0; k<r.size(); k++) {
        cout << "[" << r[k].start << "," << r[k].end << "]" << endl;
    }

    return 0;
}

/************Leetcode submission**************

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int l = intervals.size();
        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end());

        // [2, 5] [3, 7]
        for (int j=0; j<l; j++) {
            if(!result.empty() && result.back()[1] >= intervals[j][0]){
                result.back()[1] = max(result.back()[1], intervals[j][1]);
            }
            else {
                result.push_back(intervals[j]);
            }
        }

        return result;
    }
};
*/
