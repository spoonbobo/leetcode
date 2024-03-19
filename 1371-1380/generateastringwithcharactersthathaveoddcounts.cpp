class Solution {
public:
    string generateTheString(int n) {
        string res(n, 'a');
        if (n%2==0)
            res[0] ='b';
        return res;
    }
};