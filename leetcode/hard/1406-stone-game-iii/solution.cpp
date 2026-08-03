class Solution {
public:
    int n;
    vector<int> t;

    int solve(vector<int>& s, int i) {
        if (i >= n)
            return 0;

        int result = 0;
        if (t[i] != -1)
            return t[i];

        result = s[i] - solve(s, i + 1);

        if (i + 1 < n)
            result = max(result, s[i] + s[i + 1] - solve(s, i + 2));

        if (i + 2 < n)
            result = max(result, s[i] + s[i + 1] + s[i + 2] - solve(s, i + 3));

        return t[i]=result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        t.resize(n + 1, -1);

        int diff = solve(stoneValue, 0);

        if (diff > 0)
            return "Alice";
        else if (diff < 0)
            return "Bob";
        return "Tie";
    }
};