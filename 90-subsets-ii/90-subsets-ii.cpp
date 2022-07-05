class Solution {
public:
    void subset2(int indx,vector<int>& nums,vector<int>& temp,vector<vector<int>>&res){
        res.push_back(temp);
        for(int i=indx;i<nums.size();i++){
            if(i!=indx&& nums[i]==nums[i-1])
                continue;
            temp.push_back(nums[i]);
            subset2(i+1,nums,temp,res);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>res;
        subset2(0,nums,temp,res);
        return res;
    }
};