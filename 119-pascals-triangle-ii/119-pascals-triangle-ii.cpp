class Solution {
public:
    vector<int> getRow(int rowIndex) {
       vector<vector<int>>res;
        for(int i=0;i<=rowIndex;i++){
               vector<int>temp;
            temp.push_back(1);
            for(int j=1;j<i;j++){
                int x=res[i-1][j]+res[i-1][j-1];
                temp.push_back(x);
            }
            if(i!=0)
                temp.push_back(1);
            res.push_back(temp);
        }
        return res[rowIndex];
    }
};