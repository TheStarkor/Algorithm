#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int n, m;
int d[11][(1 << 11)];
char a[11][11];
bool isset(int state, int i) {
	return (state & (1 << i)) > 0;
}
bool check(int row, int state) {
	if (row < 0) return true;
	for (int i = 0; i < m - 1; i++) {
		if (isset(state, i) && isset(state, i + 1)) return false;
	}
	for (int i = 0; i < m; i++) {
		if (a[row][i] == 'x' && isset(state, i)) return false;
	}
	return true;
}
int main() {
	int c; cin >> c;
	while (c--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		memset(d, 0, sizeof(d));
		for (int row = 0; row < n; row++) {
			for (int state = 0; state < (1 << m); state++) {
				if (!check(row, state)) continue;
				for (int pstate = 0; pstate < (1 << m); pstate++) {
					if (!check(row - 1, pstate)) continue;
					int cnt = 0;
					bool ok = true;
					for (int i = 0; i < m; i++) {
						if (isset(state, i)) {
							cnt += 1;
							if (i - 1 >= 0 && isset(pstate, i - 1)) ok = false;
							if (i + 1 < m && isset(pstate, i + 1)) ok = false;
						}
					}
					if (ok) {
						if (row == 0) d[row][state] = max(d[row][state], cnt);
						else d[row][state] = max(d[row][state], d[row - 1][pstate] + cnt);
					}
				}
			}
		}
		int ans = 0;
		for (int state = 0; state < (1 << m); state++) {
			if (d[n - 1][state] > ans) ans = d[n - 1][state];
		}
		cout << ans << '\n';
	}
}
