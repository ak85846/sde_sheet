class Solution {
public:
    double myPow(double x, int n) {
        double res=1.0;
        long n2=n;
        if(n<0)
            n2=(-1*n2);
        while(n2>0){
            if(n2%2==0){
                x=x*x;
                n2=n2/2;
            }
            else{
                res=res*x;
                n2=n2-1;
            }
        }
        if(n<0){
            res=(double)(1.0) / res;
        }
        return res;
    }
};