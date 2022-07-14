class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      stack<int>s;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums2.size();i++){
            mpp[nums2[i]]=i;
        }
        for(int i=nums2.size()-1;i>=0;i--){
           while(!s.empty() &&nums2[i]>=s.top()){
               s.pop();
           }
            int temp=nums2[i];
           if(!s.empty()){
            nums2[i]=s.top();   
           }
            else
                nums2[i]=-1;
            s.push(temp);
       }
        for(int i=0;i<nums1.size();i++){
            nums1[i]=nums2[mpp[nums1[i]]];
        }
        return nums1;
    }
};