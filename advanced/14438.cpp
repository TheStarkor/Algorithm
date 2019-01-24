#include <algorithm>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
void init(vector<int> &tree, vector<int> &a, int node, int s, int e) {
	if (s == e) tree[node] = a[s];
	else {
		init(tree, a, node * 2, s, (s + e) / 2);
		init(tree, a, node * 2 + 1, (s + e) / 2 + 1, e);
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}
}
int query(vector<int> &tree, int node, int start, int end, int i, int j) {
	if (j < start || end < i) return -1;
	if (i <= start && end <= j) return tree[node];
	int m1 = query(tree, node * 2, start, (start + end) / 2, i, j);
	int m2 = query(tree, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else return min(m1, m2);
}
void update(vector<int> &tree, int node, int start, int end, int index, int value) {
	if (index < start || end < index) return;
	if (start == end) {
		tree[node] = value;
		return;
	}
	update(tree, node * 2, start, (start + end) / 2, index, value);
	update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, value);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
int main()
{
	int n, m; cin >> n;
	vector<int> a(n+1);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> tree(tree_size);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	cin >> m;
	init(tree, a, 1, 1, n);
	while (m--) {
		int what, a, b; scanf("%d %d %d", &what, &a, &b);
		if (what == 1) update(tree, 1, 1, n, a, b);
		else {
			cout << query(tree, 1, 1, n, a, b) << '\n';
		}
	}
}
