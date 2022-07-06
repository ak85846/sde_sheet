class Solution {
public:
   bool is_palindr(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    void palin_parti(int indx,string s,vector<string>&path,vector<vector<string>>&res){
        if(indx==s.size()){
            res.push_back(path);
            return;
        }
        for(int i=indx;i<s.size();i++){
            if(is_palindr(s,indx,i)){
                path.push_back(s.substr(indx,i-indx+1));
                palin_parti(i+1,s,path,res);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>path;
        vector<vector<string>> res;
      palin_parti(0,s,path,res);
        return res;
    }
};