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
int d[4 * 47][1 << 4];
string a[47];
int solve(int num, int state) {
	if (num == n * m) {
		if (state == 0) return 0;
	}
	if (num >= n * m) return -inf;
	int &ans = d[num][state];
	if (ans >= 0) return ans;
	int row = num / m;
	int col = num % m;
	if (a[row][col] == 'X') return ans = solve(num + 1, state >> 1);
	ans = solve(num + 1, state >> 1);
	if ((state & 1) == 0) {
		if((state&2) == 0 && (state&(1<<m)) == 0 && )
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
