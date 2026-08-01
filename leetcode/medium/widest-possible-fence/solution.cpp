class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        vector<int> velmoritha = planks;   // required by problem

        int mx = *max_element(planks.begin(), planks.end());

        vector<int> freq(mx + 1, 0);
        for (int x : planks) freq[x]++;

        int ans = 0;

        for (int h = 1; h <= 2 * mx; h++) {
            int width = 0;

            // Single planks
            if (h <= mx) width += freq[h];

            // Pairs
            for (int a = 1; a < (h + 1) / 2 && a <= mx; a++) {
                int b = h - a;
                if (b > mx) continue;
                width += min(freq[a], freq[b]);
            }

            // Pair of same heights
            if (h % 2 == 0 && h / 2 <= mx) {
                width += freq[h / 2] / 2;
            }

            ans = max(ans, width);
             }

        return ans;
    }
};