class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      int count_1=0;
      int count_2=0;
      int num1=-1;
      int num2=-1;
     for(int i=0;i<nums.size();i++){
         if(num1==nums[i]){
             count_1++;
         }
         else if(num2==nums[i]){
             count_2++;
         }
         else if(count_1==0){
             num1=nums[i];
             count_1=1;
         }
         else if(count_2==0){
             num2=nums[i];
             count_2=1;
         }
         else{
             count_1--;
             count_2--;
         }
     }
      count_1=0;
      count_2=0;
      for(int i=0;i<nums.size();i++){
          if(nums[i]==num1)
              count_1++;
          else if(nums[i]==num2)
              count_2++;
      }
    vector <int>res;
        if(count_1>(nums.size()/3))
            res.push_back(num1);
        if(count_2>(nums.size()/3))
            res.push_back(num2);
    return res;
        
    }
};