// beats 100% time complexity O(n). But use more space
int compare(string temp, string needle) {
    int first_repeat = -1, i;
    for (i = 0; i < temp.length(); i++) {
        if (temp[i] == needle[0] && i != 0 && first_repeat == -1)
            first_repeat = i;
        if (temp[i] != needle[i]) {
            if (first_repeat == -1) return i;
            return first_repeat;
        }
    }
    return i;
}

class Solution {
public:
    int strStr(string haystack, string needle) {
        // trivial cases
        if (needle.length() == haystack.length()) {
            if (needle == haystack) return 0;
            else return -1;
        }

        if (needle.length() > haystack.length()) {
            return -1;
        }

        int i = 0, compare_res;
        string temp;

        while (i <= haystack.length() - needle.length() + 1) {
            if (haystack[i] == needle[0]) {
                temp = haystack.substr(i, needle.length());
                compare_res = compare(temp, needle);
                if (compare_res == needle.length())
                    return i;
                if (compare_res == -1)
                    i += needle.length();
                else i += compare_res;
            }
            else i++;
        }

        return -1;

    }
};