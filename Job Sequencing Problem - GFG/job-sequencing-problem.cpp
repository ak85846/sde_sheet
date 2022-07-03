// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    bool static comparison(struct Job a,struct Job b){
        return (a.profit>b.profit);
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comparison);
        int max_dead=0;
        for(int i=0;i<n;i++){
            max_dead=max(max_dead,arr[i].dead);
        }
        int schedule[max_dead+1];
        for(int i=0;i<max_dead+1;i++){
            schedule[i]=-1;
        }
        int count_jobs=0,max_profit=0;
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(schedule[j]==-1){
                    schedule[j]=arr[i].id;
                    count_jobs++;
                    max_profit+=arr[i].profit;
                    break;
                }
            }
        }
      return {count_jobs,max_profit}  ;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends