class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        int n = numbers.size();
        for(int i=0;i<n;i++)
        {
            int x = target - numbers[i];
            int l=i+1;
            int h=n-1;
            int mid;
            bool flag = false;
            while(l<=h)
            {
                mid = l+(h-l)/2;
                if(numbers[mid]==x)
                {
                    
                    flag = true;
                    break;
                }
                else if(numbers[mid]>x)
                {
                    h = mid-1;
                }
                else
                    l = mid+1;
            }
            if(flag)
            {
                ans.push_back(i+1);
                ans.push_back(mid+1);
                break;
            }
        }
        return ans;
    }
};