// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    struct meeting{
        int start;
        int end;
        int pos;
    };
    bool static comparator(struct meeting m1,struct meeting m2){
        if(m1.end<m2.end)
        return true;
        else if(m1.end>m2.end)
        return false;
        //if equal
        else if(m1.pos<m2.pos)
        return true;
        else
        return false;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        struct meeting meet[n];
        for(int i=0;i<n;i++){
            meet[i].start=start[i];
            meet[i].end=end[i];
            meet[i].pos=i+1;
        }
     sort(meet, meet+n , comparator);
     
     int curr_end=meet[0].end;
     vector<int>res;
     res.push_back(meet[0].pos);
     for(int i=1;i<n;i++){
         if(meet[i].start>curr_end){
             curr_end=meet[i].end;
             res.push_back(meet[i].pos);
         }
     }
    return (res.size());
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends