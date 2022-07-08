class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
if(nums.size()==1) return nums[0];
        
        int left=0, right=nums.size()-1;
        
        while(left < right){
           int mid = (left+right)/2;
           int t = (mid%2 == 0) ? mid+1 : mid-1;
            if(nums[mid]==nums[t])
                left = mid+1;
            else right = mid;
        }
        return nums[right];
    }
};