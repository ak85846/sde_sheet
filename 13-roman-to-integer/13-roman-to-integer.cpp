class Solution {
public:
    int romanToInt(string s) {
           unordered_map<char,int> z;
  z.insert({'I',1});
  z.insert({'V',5});
  z.insert({'X',10});
  z.insert({'L',50});
  z.insert({'C',100});
  z.insert({'D',500});
  z.insert({'M',1000});
  int res=0;
  int n=s.length();
  for(int i=0;i<n;i++){
    int a=z[s[i]];
    if(i+1<n){
      int b=z[s[i+1]];
      if(a<b)
        res=res-a;
      else
        res=res+a;
    }
    else
      res=res+a;
  }
  return res;
    }
};