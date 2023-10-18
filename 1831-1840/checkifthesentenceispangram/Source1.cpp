// Slightly optimized version of source.cpp using set to check size equals 26

class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> s;
        for (auto& c : sentence)
            s.insert(c);
        return s.size() == 26;
    }
};