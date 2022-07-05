class Solution {
public:
   void allcombination(int indx,int target,vector<int>& candidates,vector<int>& temp,vector<vector<int>>&res){
       if(target==0){
           res.push_back(temp);
           return;
       }
       for(int i=indx;i<candidates.size();i++){
           if(i>indx && candidates[i]==candidates[i-1])
               continue;
           if(candidates[i]>target)
               break;
           temp.push_back(candidates[i]);
           allcombination(i+1,target-candidates[i],candidates,temp,res);
           temp.pop_back();
       }
   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(),candidates.end());
        vector<int>temp;
        vector<vector<int>>res;
        allcombination(0,target,candidates,temp,res);
        return res;
    }
};