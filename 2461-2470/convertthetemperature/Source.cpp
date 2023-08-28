// O(1) solution

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return vector<double> {(double)celsius + 273.15, (double)(celsius * 1.8 + 32.0f)};
    }
};