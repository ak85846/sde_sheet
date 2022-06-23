class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec;
        for(int i=0;i<numRows;i++)
        {
               vector<int> vc;
               vc.push_back(1);
               for(int j=1;j<i;j++)
               {
                  vc.push_back(vec[i-1][j]+vec[i-1][j-1]);
               }
            if(i!=0)
            vc.push_back(1);
        vec.push_back(vc);
        }
        return vec;
    }
};