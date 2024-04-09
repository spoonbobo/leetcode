class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int unwant_ct = 0;
        int preference;
        queue<int> studentq;
        stack<int> swstk;

        // push students to queue
        for (int i = 0; i < students.size(); i++) {
            studentq.push(students[i]);
        }

        // push sandwiches to stack
        for (int i = sandwiches.size() - 1; i >= 0; i--) {
            swstk.push(sandwiches[i]);
        }

        while (unwant_ct != studentq.size()) {
            preference = studentq.front();
            // case 1, eat
            if (preference == swstk.top()) {
                swstk.pop();
                studentq.pop();
                unwant_ct = 0; // reset
            }
            else {
                // case 2 not eat
                studentq.pop();
                studentq.push(preference);
                unwant_ct++;
            }
        }
        return studentq.size();
    }
};