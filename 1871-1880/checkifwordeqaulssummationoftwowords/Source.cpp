class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int i;
        for (i = 0; i < firstWord.length(); i++) {
            firstWord[i] = firstWord[i] - 49;
        }
        for (i = 0; i < secondWord.length(); i++) {
            secondWord[i] = secondWord[i] - 49;
        }
        for (i = 0; i < targetWord.length(); i++) {
            targetWord[i] = targetWord[i] - 49;
        }
        return (stoi(firstWord) + stoi(secondWord)) == stoi(targetWord);
    }
};