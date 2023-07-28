class Solution {
public:
    bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> closingToOpening = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (st.empty() || st.top() != closingToOpening[ch]) {
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}
};
