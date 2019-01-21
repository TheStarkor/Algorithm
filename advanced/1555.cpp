#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
set<int> d[(1 << 6)];
bool is_prime(int x) {
	if (x < 2) return false;
	for (int i = 2; i*i <= x; i++) {
		if (x%i == 0) return false;
	}
	return true;
}
set<int> solve(vector<int> &a, int mask) {
	set<int> &ans = d[mask];
	if (ans.size() > 0) return ans;
	if (mask == 0) return ans;
	int n = a.size();
	for (int i = 0; i < (1<<n); i++) {
		int first = i & mask;
		int second = (~first) & mask;
		if (first == 0 || second == 0) continue;
		solve(a, first);
		solve(a, second);
		for (int x : d[first]) {
			for (int y : d[second]) {
				if (x != 0) ans.insert(y / x);
				if (y != 0) ans.insert(x / y);
				ans.insert(x + y);
				ans.insert(x - y);
				ans.insert(y - x);
				ans.insert(x * y);
			}
		}
	}
	return ans;
}
int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		d[(1 << i)].insert(a[i]);
	}
	set<int> ans = solve(a, (1 << n) - 1);
	int ans_min = -1;
	int ans_max = -1;
	for (auto &x : ans) {
		if (is_prime(x)) {
			if (ans_min == -1) ans_min = x;
			ans_max = x;
		}
	}
	if (ans_min == -1) cout << -1;
	else {
		cout << ans_min << '\n';
		cout << ans_max << '\n';
	}
}
