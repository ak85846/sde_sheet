class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            if(ans.empty()){
                ans.push_back(intervals[i]);
            }
            else{
            vector<int>& vec=ans.back();
                if(vec[1]>=intervals[i][0]){
                    vec[1]=max(vec[1],intervals[i][1]);
                }
                else{
                  ans.push_back(intervals[i]);  
                }
                }
        }
        return ans;
    }
};