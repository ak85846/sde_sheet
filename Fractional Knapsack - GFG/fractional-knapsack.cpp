// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    bool static comparison(Item a,Item b){
       double p1=(double)a.value/(double)a.weight;
       double p2=(double)b.value/(double)b.weight;
       return(p1>p2);
    }
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comparison);
        int curr_weight=0;
        double max_value=0;
        for(int i=0;i<n;i++){
            if(curr_weight+arr[i].weight<=W){
                curr_weight+=arr[i].weight;
                max_value+=arr[i].value;
            }
            else{
                int remain_weight=W-curr_weight;
                max_value+=((double)arr[i].value/(double)arr[i].weight)*(double)remain_weight;
                break;
            }
        }
        return max_value;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends