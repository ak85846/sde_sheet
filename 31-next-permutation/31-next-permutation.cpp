class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
         if(n==1)
             return;
        int indx1,indx2;
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
                indx1=i;
                break;
            }       
        }
        cout<<indx1;
        if(indx1==-1){
            reverse(nums.begin(),nums.end()); 
            return;
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[indx1]){
                indx2=i;
                break;
            }
        }
         swap(nums[indx1],nums[indx2]);
         reverse(nums.begin()+(indx1+1),nums.end());
        
        
    }
};