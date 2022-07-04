// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void fun(int indx,int sum,vector<int>&arr,int n,vector<int>&subset_sum){
        if(indx==n){
            subset_sum.push_back(sum);
            return;
        }
        fun(indx+1,sum+arr[indx],arr,n,subset_sum);
        fun(indx+1,sum,arr,n,subset_sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>subset_sum;
        fun(0,0,arr,N,subset_sum);
        return subset_sum;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends