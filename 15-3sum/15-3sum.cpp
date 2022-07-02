class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>vec;
      for(int i=0;i<n-2;i++){
          if(i==0 ||(i>0 && (nums[i]!=nums[i-1]))){
          int sum2=0-nums[i];
          int low=i+1;
          int high=n-1;
          while(low<high){
              if((nums[low]+nums[high])>sum2){
                  high--;
              }
             else if(nums[low]+nums[high]<sum2){
                  low++;
              }
            else{
                vector<int>threedigit;
               threedigit.push_back(nums[i]);
                  threedigit.push_back(nums[low]);
                   threedigit.push_back(nums[high]);
                vec.push_back(threedigit);
                 
                while(low<high &&nums[low]==nums[low+1])
                    low++;
                while(low<high &&nums[high]==nums[high-1])
                    high--;
               low++,high--; 
            }  
          }
      }
      }
        return vec;
    }
};