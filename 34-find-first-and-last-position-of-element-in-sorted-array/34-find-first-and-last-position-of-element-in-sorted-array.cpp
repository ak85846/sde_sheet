class Solution {
public:
vector<int> searchRange(vector<int>& nums, int target) {

    if(nums.size()==0) return {-1,-1};

    int i = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
    
    if(i>=nums.size() || nums[i]!=target) return {-1,-1};
    
    int j=i;
    while(j+1<nums.size() && nums[j+1]==nums[i]) ++j;
    
    return {i,j};
    
}
};