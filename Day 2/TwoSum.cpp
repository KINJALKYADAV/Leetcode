#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        int x,y;
        for(int i=0;i<nums.size();i++)
        {
            int a = nums[i];
            int more= target-a;
            if(mpp.find(more)!=mpp.end())
            {
                x=i;
                y=mpp[more];
                break;
            }
                mpp[a]=i;
        }
        return {x,y};
    }
};