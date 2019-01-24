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
typedef long long lld;
long long init(vector<lld> &tree, vector<lld> &a, int node, int start, int end) {
	if (start == end) return tree[node] = a[start];
	else {
		return tree[node] = init(tree, a, node * 2, start, (start + end) / 2) + init(tree, a, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}
void update_lazy(vector<lld> &tree, vector<lld> &lazy, int node, int s, int e) {
	if (lazy[node] != 0) {
		tree[node] += (e - s + 1) * lazy[node];
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void update(vector<lld> &tree, vector<lld> &lazy, int node, int s, int e, int l, int r, long long diff) {
	update_lazy(tree, lazy, node, s, e);
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		tree[node] += (e - s + 1)*diff;
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
long long sum(vector<lld> &tree, vector<lld> &lazy, int node, int s, int e, int l, int r) {
	update_lazy(tree, lazy, node, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return tree[node];
	}
	return sum(tree, lazy, node * 2, s, (s + e) / 2, l, r) + sum(tree, lazy, node * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
int main()
{
	int n, m, k; cin >> n >> m >> k;
	vector<lld> a(n+1);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<lld> tree(tree_size);
	vector<lld> lazy(tree_size);
	m += k;
	init(tree, a, 1, 1, n);
	while (m--) {
		int what; scanf("%d", &what);
		if (what == 1) {
			int start, end;
			long long d;
			scanf("%d %d %lld", &start, &end, &d);
			update(tree, lazy, 1, 1, n, start, end, d);
		}
		else {
			int start, end;
			scanf("%d %d", &start, &end);
			printf("%lld\n", sum(tree, lazy, 1, 1, n, start, end));
		}
	}
}
