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
int main() {
	ios_base::sync_with_stdio(false);
	string s; cin >> s;
	int n = s.length();
	vector<int> sa(n);
	vector<vector<int>> group(20, vector<int>(n + 1));
	for (int i = 0; i < n; i++) sa[i] = i;
	for (int i = 0; i < n; i++) group[0][i] = s[i];
	group[0][n] = -1;
	for (int k = 0, len = 1; len / 2 < n; len *= 2, k++) {
		auto cmp = [&](int u, int v) {
			if (group[k][u] == group[k][v]) {
				return group[k][u + len] < group[k][v + len];
			}
			else {
				return group[k][u] < group[k][v];
			}
		};
		sort(sa.begin(), sa.end(), cmp);
		group[k + 1][sa[0]] = 0;
		group[k + 1][n] = -1;
		for (int i = 1; i < n; i++) {
			if (cmp(sa[i - 1], sa[i])) {
				group[k + 1][sa[i]] = group[k + 1][sa[i - 1]] + 1;
			}
			else {
				group[k + 1][sa[i]] = group[k + 1][sa[i - 1]];
			}
		}
	}
	for (int i = 0; i < n; i++) cout << sa[i] << '\n';
}
