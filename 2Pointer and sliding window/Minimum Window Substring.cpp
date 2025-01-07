/*
76. Minimum Window Substring
https://leetcode.com/problems/minimum-window-substring/description/
*/



class Solution {
public:
    bool check(vector<int>& big, vector<int>& small) {
        for (int i = 0; i < 52; i++) {
            if (big[i] < small[i]) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        int head = -1, tail = 0;
        int n = s.length();
        int ansi = -1, ansj = -1;
        vector<int> bigMap(52, 0);
        vector<int> smallMap(52, 0);
        for (char c : t) {
            if (isupper(c)) {
                smallMap[c - 'A' + 26]++;
            } else {
                smallMap[c - 'a']++;
            }
        }
        while (tail < n) {
            while ((head + 1 < n) && !check(bigMap, smallMap)) {
                head++;
                if (isupper(s[head])) {
                    bigMap[s[head] - 'A' + 26]++;
                } else {
                    bigMap[s[head] - 'a']++;
                }
            }

            if (check(bigMap, smallMap)) {
                if (ansi == -1 || head - tail < ansj - ansi) {
                    ansi = tail;
                    ansj = head;
                }
            }

            if (tail <= head) {
                if (isupper(s[tail])) {
                    bigMap[s[tail] - 'A' + 26]--;
                } else {
                    bigMap[s[tail] - 'a']--;
                }
                tail++;
            } else {
                tail++;
                head = tail - 1;
            }
        }

        if (ansi == -1 || ansj == -1) {
            return "";
        }

        return s.substr(ansi, ansj - ansi + 1);
    }
};
