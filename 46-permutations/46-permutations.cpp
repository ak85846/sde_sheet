class Solution {
public:
    void permu(int indx,vector<int>&nums,vector<vector<int>>&res){
        if(indx==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=indx;i<nums.size();i++){
            swap(nums[indx],nums[i]);
            permu(indx+1,nums,res);
            swap(nums[indx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        permu(0,nums,res);
        return res;
    }
};