class Solution {
public:
    int scoreOfParentheses(string s) {

        stack<int> st;
        int cur = 0;

        for (char c : s) {

            if (c == '(') {
                st.push(cur);
                cur = 0;
            }
            else {
                int inside = cur;
                cur = st.top();
                st.pop();

                if (inside == 0)
                    cur += 1;
                else
                    cur += 2 * inside;
            }
        }

        return cur;
    }
};