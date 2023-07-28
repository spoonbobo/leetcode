// O(sort) solution. Beats 99% time complexity.

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int answer = 0;
        for (int i = 0; i < students.size(); i++) {
            answer = answer + abs(students[i] - seats[i]);
        }
        return answer;
    }
};