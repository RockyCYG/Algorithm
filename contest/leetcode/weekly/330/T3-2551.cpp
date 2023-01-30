#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        for (int i = 0; i < n - 1; i++) {
            weights[i] += weights[i + 1];
        }
        weights.pop_back();
        sort(weights.begin(), weights.end());
        return accumulate(weights.end() - k + 1, weights.end(), 0l) - accumulate(weights.begin(), weights.begin() + k - 1, 0l);
    }
};