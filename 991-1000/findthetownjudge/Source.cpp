// beats 90.58% time and 62.99% spaace
// O(n) time and space

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // purpose of this is to find, in the n-by-n graph, if there is [i,i] such that ith ROWSUM == 0, COLSUM == n-1 (properties 1&2)
        // each pair in trust pair updates n-by-n trust graph
        vector<int> rowsum(n, 0); // to trust, whoever trusted once must not be judge
        vector<int> colsum(n, 0); // being trusted


        for (auto& trust_pair : trust) {
            rowsum[trust_pair[0] - 1]++; // convert to 0-index
            colsum[trust_pair[1] - 1]++; // convert to 0-index
        }

        vector<int> possible_judges;

        for (int i = 0; i < n; i++) {
            if (possible_judges.size() > 1)
                return -1; // violates property 3
            if (rowsum[i] == 0 && colsum[i] == n - 1)
                possible_judges.push_back(i + 1); // satisfies property1&2
        }

        if (possible_judges.size() == 0)
            return -1; // violates property 3 

        return possible_judges[0];
    }
};