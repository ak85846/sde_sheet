class Solution {
    struct node{
        int no;
        int freq;
        node(int a,int b){
            no=a;
            freq=b;
        }
    };
       struct compare{
           bool operator()(node const& a,node const& b){
               return a.freq<b.freq;
           }
       };
public:
 
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int>m;
        for(int i:nums)
            m[i]+=1;
        priority_queue<node,vector<node>,compare>heap;
        for(auto it:m)
            heap.push(node(it.first,it.second));
        vector<int>res;
        
        while(k--){
            node temp=heap.top();
            heap.pop();
            res.push_back(temp.no);
        }
        return res;
    }
};