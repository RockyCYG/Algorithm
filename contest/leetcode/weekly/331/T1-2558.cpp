#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0LL;
        priority_queue<int> q(gifts.begin(), gifts.end());
        while (k--) {
            int x = q.top();
            q.pop();
            int y = (int)sqrt(x);
            q.push(y);
        }
        while (!q.empty()) {
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};