//Leetcode 227

int calculate(string s) {

    stack < int > st;
    int res = 0;
    long long temp = 0;
    char sign = '+';
    for (int i = 0; i < s.size(); i++) {

        if (isdigit(s[i])) {
            temp = temp * 10 + s[i] - '0';
        }
        if (!isdigit(s[i]) and!isspace(s[i]) || i == s.size() - 1) {
            if (sign == '-') {
                st.push(-temp);
            } else if (sign == '+') {
                st.push(temp);
            } else {
                int num;
                if (sign == '*') {
                    num = st.top() * temp;
                } else {
                    num = st.top() / temp;
                }
                st.pop();
                st.push(num);
            }
            sign = s[i];
            temp = 0;
        }
    }

    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;

}
