#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
const int inf = 1000000;
int n, m;
int d[10 * 25][1 << 10];
string a[25];
int solve(int num, int state) {
	if (num == n * m) {
		if (state == 0) return 0;
	}
	if (num >= n * m) return -inf;
	int &ans = d[num][state];
	if (ans >= 0) return ans;
	int row = num / m;
	int col = num % m;
	if (a[row][col] == '1') {
		ans = solve(num + 1, state >> 1) + 1;
		return ans;
	}
	ans = solve(num + 1, state >> 1);
	if ((state & 1) == 0) {
		ans = max(ans, solve(num + 1, state >> 1) + 1);
	}
	if (row != n - 1 && col != m - 1 && (state & 1) == 0 && (state & 2) == 0) {
		if (a[row][col + 1] == '.' && a[row + 1][col] == '.' && a[row + 1][col + 1] == '.') {
			ans = max(ans, solve(num + 2, (state >> 2) | (1 << (m - 1)) | (1 << (m - 2))) + 16);
		}
	}
	return ans;
}
int main() {
	cin >> n >> m;
	vector<string> b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			a[j] += b[i][j];
		}
	}
	swap(n, m);
	memset(d, -1, sizeof(d));
	cout << solve(0, 0);
}
