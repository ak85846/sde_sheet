class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        if(nums.empty())
            return res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long target2=(long)target-nums[i]-nums[j];
                int front=j+1,back=n-1;
                while(front<back){
                    long twosum=nums[front]+nums[back];
                    if(twosum>target2){
                        back--;
                    }
                    else if(twosum<target2){
                        front++;
                    }
                    else{
                        vector<int> fourdigit(4,0);
                        fourdigit[0]=nums[i];
                        fourdigit[1]=nums[j];
                        fourdigit[2]=nums[front];
                        fourdigit[3]=nums[back];
                        res.push_back(fourdigit);
                        
                        while(front<back && nums[front]==fourdigit[2])
                            ++front;
                        while(front<back && nums[back]==fourdigit[3])
                            --back;
                            
                    }        
                }
                while(j+1<n && nums[j+1]==nums[j])
                        ++j;
                
            }
               while(i+1<n && nums[i+1]==nums[i])
                        ++i;
            
        }
        return res;
    }
};