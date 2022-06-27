class Solution {
public:
    int merge(vector<int>&nums,int low,int mid,int high){
        int count=0;
        int j=mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high && nums[i]>((long)2*(nums[j]))){
                j++;
            }
            count+=(j-(mid+1));
        }
        vector<int> temp;
        int i=low;
        j=mid+1;
        while(i<=mid&&j<=high){
            if(nums[i]>=nums[j])
                temp.push_back(nums[j++]);
            else
                temp.push_back(nums[i++]);
        }
        while(i<=mid)
            temp.push_back(nums[i++]);
        while(j<=high)
            temp.push_back(nums[j++]);
        
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
        
        return count;
        
    }
    int mergesort(vector<int>&nums,int low,int high){
        int revpair=0;
       if(low>=high)
           return 0;
        int mid=(low+high)/2;
         revpair+=mergesort(nums,low,mid);
        revpair+=mergesort(nums,mid+1,high);
        revpair+=merge(nums,low,mid,high);
        return revpair;  
    }
    int reversePairs(vector<int>& nums) {
      return mergesort(nums,0,nums.size()-1);
       
    }
};