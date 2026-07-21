class Solution {
public:
    int longestValidParentheses(string s) {
        int lB = 0, cB = 0;
        int length = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                cB++;
            } else {
                cB--;
            }
            length++;
            
            if (cB == 0) {
                lB = max(lB, length);
            } else if (cB < 0) {
                cB = 0;
                length = 0;
            }
        }

        cB = 0;
        length = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')') {
                cB++;
            } else {
                cB--;
            }
            length++;

            if (cB == 0) {
                lB = max(lB, length);
            } else if (cB < 0) {
                cB = 0;
                length = 0;
            }
        }

        return lB;
    }
};
