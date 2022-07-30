class Solution {
public:
vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    
    vector<int>freq2(26,0);   
    vector<string> ans;       
    
    for(int i=0;i<words2.size();i++){
        
        string current=words2[i];   
        vector<int> temp(26,0);     
        
        for(auto ch:current){       
            temp[ch-'a']++;      
            
            freq2[ch-'a']=max(freq2[ch-'a'], temp[ch-'a']);   
        }
    }
    
    for(int i=0;i<words1.size();i++){
        
        vector<int>freq1(26,0);  
        bool flag=true;             
        
        string current=words1[i];   
        for(auto ch: current){     
            freq1[ch-'a']++;
        }
        
        for(int i=0;i<26;i++){           
            if(freq2[i]>freq1[i]){     
                flag=false;            
                break;
            }
        }
        
        if(flag==true){
            ans.push_back(current);
        }
    }
    
    return ans;
}
};