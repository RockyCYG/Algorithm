// Problem: E. Two Teams
// Contest: Codeforces - Codeforces Round 552 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1154/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

// 双向链表 + 排序
/* struct node {
    int index{};
    int val{};
    node *prev{};
    node *next{};
};

bool cmp(node *node1, node *node2) {
    return node1->val < node2->val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    node *head = new node();
    node *tail = new node();
    int n, k;
    cin >> n >> k;
    int a[n];
    node *nodes[n];
    node *cur = head;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cur->next = nodes[i] = new node();
        nodes[i]->index = i;
        nodes[i]->val = a[i];
        nodes[i]->prev = cur;
        cur = cur->next;
    }
    nodes[n - 1]->next = tail;
    tail->prev = nodes[n - 1];
    sort(nodes, nodes + n, cmp);
    int ans[n];
    memset(ans, 0, sizeof(ans));
    int num = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (ans[nodes[i]->index]) {
            continue;
        }
        ans[nodes[i]->index] = (num & 1) + 1;
        node *left = nodes[i]->prev;
        for (int j = 0; j < k && left != head; j++, left = left->prev) {
            ans[left->index] = (num & 1) + 1;
        }
        node *right = nodes[i]->next;
        for (int j = 0; j < k && right != tail; j++, right = right->next) {
            ans[right->index] = (num & 1) + 1;
        }
        left->next = right;
        right->prev = left;
        num++;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << "\n";
    return 0;
} */

// 数组模拟双向链表
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    int hash[n + 1];
    int left[n + 1];
    int right[n + 1];
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	hash[a[i]] = i;
    	right[i - 1] = i;
    	left[i] = i - 1;
    }
    right[n] = n + 1;
    int ans[n + 1];
    memset(ans, 0, sizeof(ans));
    int num = 1;
    for (int x = n; x >= 1; x--) {
    	int pos = hash[x];
    	if (ans[pos]) {
    		continue;
    	}
    	ans[pos] = num;
    	int l = left[pos], r = right[pos];
    	right[l] = r;
    	left[r] = l;
    	for (int c = 0, i = left[pos]; c < k && i > 0; c++, i = left[i]) {
    		ans[i] = num;
	    	int l = left[i], r = right[i];
	    	right[l] = r;
	    	left[r] = l;
    	}
    	for (int c = 0, i = right[pos]; c < k && i < n + 1; c++, i = right[i]) {
    		ans[i] = num;
    		int l = left[i], r = right[i];
    		right[l] = r;
    		left[r] = l;
    	}
    	num ^= 3;
    }
    for (int i = 1; i <= n; i++) {
    	cout << ans[i];
    }
    cout << "\n";
    return 0;
}