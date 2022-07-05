class Solution {
public:
    void allcombination(int indx,int target,vector<int> &candidates,vector<int>  &temp,vector<vector<int>> &res){
        if(indx==candidates.size()){
            if(target==0){
                res.push_back(temp);
            }
            return;
        }
        if(candidates[indx]<=target){
            temp.push_back(candidates[indx]);
            allcombination(indx,target-candidates[indx],candidates,temp,res);
            temp.pop_back();
        }
        allcombination(indx+1,target,candidates,temp,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        allcombination(0,target,candidates,temp,res);
        return res;
    }
};