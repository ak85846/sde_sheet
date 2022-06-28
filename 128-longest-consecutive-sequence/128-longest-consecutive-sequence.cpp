class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashset;
        int longcs=0;
        for(int n:nums){
            hashset.insert(n);
        }
        for(int n:nums){
          if(!hashset.count(n-1)){
              int currentnum=n;
              int currentcs=1;
              while(hashset.count(currentnum+1)){
                  currentnum+=1;
                  currentcs+=1;
              }
              longcs=max(longcs,currentcs);
          }  
        }
        return longcs;
    }
};