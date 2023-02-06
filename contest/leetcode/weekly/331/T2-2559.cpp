#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> s{'a', 'e', 'i', 'o', 'u'};
        int n = words.size();
        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) {
            string& word = words[i];
            pre[i + 1] = pre[i] + (s.find(word[0]) != s.end() && s.find(word.back()) != s.end());
        }
        int k = queries.size();
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            int l = queries[i][0], r = queries[i][1];
            ans[i] = pre[r + 1] - pre[l];
        }
        return ans;
    }
};