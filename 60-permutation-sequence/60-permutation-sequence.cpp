class Solution {
public:
    string getPermutation(int n, int k) {
        string res="";
        vector<int>num;
       int fact=1;
        //we need fact only of n-1 because one element is fix at starting
        for(int i=1;i<n;i++){
            fact=fact*i;
            num.push_back(i);
        }
        num.push_back(n);
        k=k-1;//because of 0 indexing
        while(true){
            res=res+ to_string(num[k/fact]);
            num.erase(num.begin()+k/fact);
            if(num.size()==0)
                break;
            k=k%fact;
            //to reduce the fact
            fact=fact/num.size();
        }
        return res;
    }
};