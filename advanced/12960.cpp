#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int inf = 1000000;
int r, c;
string a[47];
int d[4 * 47][(1 << 5)];
int solve(int num, int state) {
	if (num == r * c && state == 0) return 0;
	if (num >= r * c) return -inf;
	int &ans = d[num][state];
	if (ans != -1) return ans;
	int row = num / c;
	int col = num % c;
	if (a[row][col] == 'X') return ans = solve(num + 1, state >> 1);
	ans = solve(num + 1, state >> 1);
	if ((state & 1) == 0) {
		if ((row + col) % 2 == 0) {
			if (row + 1 < r && col + 1 < c) {
				if ((state & 2) == 0 && a[row + 1][col] == '.' && a[row][col + 1] == '.') {
					ans = max(ans, solve(num + 2, (state >> 2) | (1 << (c - 2))) + 1);
				}
			}
		}
		else {
			if (row + 1 < r && col + 1 < c) {
				if ((state & 2) == 0 && a[row][col + 1] == '.' && a[row + 1][col + 1] == '.') {
					ans = max(ans, solve(num + 2, (state >> 2) | (1 << (c - 1))) + 1);
				}
			}
			if(row + 1 < r && col - 1 >= 0){
				if ((state&(1<<(c - 1))) == 0 && a[row + 1][col - 1] == '.' && a[row + 1][col] == '.') {
					ans = max(ans, solve(num + 1, (state >> 1) | (1 << (c - 2)) | (1 << (c - 1))) + 1);
				}
			}
			if (row + 1 < r && col + 1 < c) {
				if (a[row + 1][col] == '.' && a[row + 1][col + 1] == '.') {
					ans = max(ans, solve(num + 2, (state >> 2) | (1 << (c - 1)) | (1 << (c-2))) + 1);
				}
			}
		}
	}
	return ans;
}
int main() {
	cin >> r >> c;
	vector<string> b(r);
	for (int i = 0; i < r; i++) cin >> b[i];
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) a[i] += b[j][i];
	}
	swap(r, c);
	memset(d, -1, sizeof(d));
	cout << solve(0, 0);
}
