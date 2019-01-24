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
int init(vector<int> &tree, vector<int> &a, int node, int start, int end) {
	if (start == end) return tree[node] = a[start];
	return tree[node] = init(tree, a, node * 2, start, (start + end) / 2) + init(tree, a, node * 2 + 1, (start + end) / 2 + 1, end);
}
void lazy_update(vector<int> &tree, vector<int> &lazy, int node, int s, int e) {
	if (lazy[node] != 0) {
		if (lazy[node] & 1) {
			tree[node] = (e - s + 1) - tree[node];
		}
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void update(vector<int> &tree, vector<int> &lazy, int node, int s, int e, int l, int r, int diff) {
	lazy_update(tree, lazy, node, s, e);
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		tree[node] = (e - s + 1) - tree[node];
		if (s != e) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	update(tree, lazy, node * 2, s, (s + e) / 2, l, r, diff);
	update(tree, lazy, node * 2 + 1, (s + e) / 2 + 1, e, l, r, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int sum(vector<int> &tree, vector<int> &lazy, int node, int s, int e, int l, int r) {
	lazy_update(tree, lazy, node, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return tree[node];
	return sum(tree, lazy, node * 2, s, (s + e) / 2, l, r) + sum(tree, lazy, node * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
int main()
{
	int n, m; cin >> n >> m;
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<int> a(n + 1);
	vector<int> tree(tree_size);
	vector<int> lazy(tree_size);
	init(tree, a, 1, 1, n);
	while (m--) {
		int t1, t2, t3; scanf("%d %d %d", &t1, &t2, &t3);
		if (t1 == 0) {
			update(tree, lazy, 1, 1, n, t2, t3, 1);
		}
		else {
			printf("%d\n", sum(tree, lazy, 1, 1, n, t2, t3));
		}
	}
}
