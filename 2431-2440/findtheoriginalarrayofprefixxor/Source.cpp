// O(n) time and space
// key is to understand
/* 
    a^x = b
    a^a^x = a^b
    0^x = a^b
    x = a^b
*/

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> xora{pref[0]};
        for (int i = 1; i < pref.size(); i++) {
            pref[i] ^= xora[i - 1];
            xora.push_back(xora[i - 1] ^ pref[i]);
        }
        return pref;
    }
};