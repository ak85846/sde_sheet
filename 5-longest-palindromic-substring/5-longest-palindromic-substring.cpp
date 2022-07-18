class Solution {
public:
    string longestPalindrome(string s) {
        int start=0;
        int end=0;
        int low,high;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            low=i;
            high=i+1;
            
            while(low>=0 and high<n and s[low]==s[high])
            {
                if((end-start)<(high-low))
                {
                    start=low;
                    end=high;
                }
                low--;
                high++;
            }
            low=i;
            high=i+2;
            while(low>=0 and high<n and s[low]==s[high])
            {
                if((end-start)<(high-low))
                {
                    start=low;
                    end=high;
                }
                low--;
                high++;
            }
        }
        return s.substr(start,end-start+1);
    }

    
};