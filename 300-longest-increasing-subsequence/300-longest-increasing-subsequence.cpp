class Solution {
public:
    
    int fun(int indx,int prev_indx,vector<int>& nums,int n,vector<vector<int>> &dp){
        if(indx==n)
            return 0;
        if(dp[indx][prev_indx+1]!=-1)
            return dp[indx][prev_indx+1];
        int len=0+fun(indx+1,prev_indx,nums,n,dp);
        if(prev_indx==-1 || nums[indx]>nums[prev_indx]){
            len=max(len,1+fun(indx+1,indx,nums,n,dp));
        }
        return dp[indx][prev_indx+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
            return fun(0,-1,nums,n,dp);
    }
};