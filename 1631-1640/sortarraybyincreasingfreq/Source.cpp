// O(freq * sort) solution, beats 100% time, and 68% space

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<short int, short int> ctr;

        // O(n)
        for (int& num : nums)
            ctr[num]++;

        // O(uniqueUnmbers < N)
        unordered_map<short int, vector<short int>> ctr2;
        for (const auto& entry : ctr)
            ctr2[entry.second].push_back(entry.first);

        // O(allPossibleFreq < N)
        vector<short int> freqK;
        for (const auto& entry : ctr2)
            freqK.push_back(entry.first);

        // O(sort)
        sort(freqK.begin(), freqK.end());

        // vector<short int> res;
        short int k = 0;
        // O(freq * sort)
        for (short int i = 0; i < freqK.size(); i++) {
            sort(ctr2[freqK[i]].begin(), ctr2[freqK[i]].end(), greater<>());
            for (auto elem : ctr2[freqK[i]])
                for (short int push_i = 0; push_i < freqK[i]; push_i++) {
                    nums[k] = elem;
                    k++;
                }
        }

        return nums;
    }
};