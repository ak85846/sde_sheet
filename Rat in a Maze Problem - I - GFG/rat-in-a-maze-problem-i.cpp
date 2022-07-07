// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

    class Solution{
        public:
        void solve_rat(int i,int j,vector<vector<int>>&m,int n, vector<string>&res,
        vector<vector<int>>&aux,string str,int di[],int dj[]){
            if(i==n-1&&j==n-1){
                res.push_back(str);
                return;
            }
            string dir="DLRU";
            for(int indx=0;indx<4;indx++){
                int nexti=i+di[indx];
                int nextj=j+dj[indx];
                if(nexti>=0 && nextj>=0 &&nexti<n && nextj<n && !aux[nexti][nextj] &&
                m[nexti][nextj]==1){
                    aux[i][j]=1;
                    solve_rat(nexti,nextj,m,n,res,aux,str+dir[indx],di,dj);
                    aux[i][j]=0;
                }
            }
        }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>res;
        vector<vector<int>>aux(n,vector<int>(n,0));
        int di[]={1,0,0,-1};
        int dj[]={0,-1,1,0};
        if(m[0][0]==1) 
        solve_rat(0,0,m,n,res,aux,"",di,dj);
        return res;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends