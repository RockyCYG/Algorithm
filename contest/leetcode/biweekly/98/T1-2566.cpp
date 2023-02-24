#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string t = s;
        char first = s[0];
        for (auto& c : t) {
            if (c == first) {
                c = '0';
            }
        }
        int mn = stoi(t);
        for (auto c : s) {
            if (c != '9') {
                first = c;
                break;
            }
        }
        for (auto& c : s) {
            if (c == first) {
                c = '9';
            }
        }
        int mx = stoi(s);
        return mx - mn;
    }
};