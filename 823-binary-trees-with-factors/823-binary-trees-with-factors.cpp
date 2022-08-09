class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = 1e9 + 7;
        unordered_map<int, int> m;
        int res = 0;
        
        sort(arr.begin(), arr.end());
        
        for (int head : arr)
        {
            m[head] = 1;
            for (auto [child1, value] : m)
            {
                int child2 = head / child1;
                if (child1 *child2 == head && m.find(child2) != m.end())
                {
                    long tmp = ((long)m[child1] * (long)m[child2]) % mod;
                    m[head] = (m[head] + tmp) % mod;
                }
            }
            res = (res + m[head]) % mod;
        }
       
        return res;
    }
};