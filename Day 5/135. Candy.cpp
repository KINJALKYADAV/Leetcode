\\ Better
\\ Time complexity : O(N)
\\ Space Complexity : O(N)
\\ Left-Right Pass
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum =0;
        vector<int>ans(n,1);
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                if(ans[i]<=ans[i-1])
                    ans[i]=ans[i-1]+1;
            }
        }
        for(int i=n-1;i>=1;i--)
        {
            if(ratings[i-1]>ratings[i])
            {
                if(ans[i]>=ans[i-1])
                    ans[i-1]=ans[i]+1;
            }
        }
        for(int i=0;i<n;i++)
            sum = sum +ans[i];
        return sum;
    }
};

\\ Optimal
\\ Time complexity : O(N)
\\ Space complexity : O(1)
\\ Slope Method

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum =1;
        int i=1;
        int upSlope =0;
        int upSlopeLength= 0;
        int downSlope = 0;
        while(i<n)
        {
            if(ratings[i]==ratings[i-1])
            {
                upSlope =0;
                downSlope = 0;
                upSlopeLength = 0;
                sum++;
            }
            else if(ratings[i]>ratings[i-1])
            {
                upSlope = upSlope==0?1:upSlope;
                upSlope ++;
                downSlope =0;
                sum +=upSlope;
                upSlopeLength = upSlope;
            }
            else
            {
            upSlope =0;
                downSlope ++;
                int slopeDiff =(downSlope+1-upSlopeLength)>0?1:0;
                sum += downSlope + slopeDiff;
            }
            i++;
            
        }
        return sum;
    }
};