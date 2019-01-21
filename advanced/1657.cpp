#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int n, m;
int d[15*15][(1 << 15)];
char a[15][15];
int cost[6][6] = {
	{10,8,7,5,0,1},
	{8,6,4,3,0,1},
	{7,4,3,2,0,1},
	{5,3,2,2,0,1},
	{0,0,0,0,0,0},
	{1,1,1,1,0,0}
};
int score(char a, char b) {
	return cost[(int)(a - 'A')][(int)(b - 'A')];
}
int go(int i, int state){
	if (i >= m * n) return 0;
	int &ans = d[i][state];
	if (ans != -1) return ans;
	ans = 0;
	int row = i / m;
	int col = i % m;
	ans = go(i + 1, state >> 1);
	if ((state & 1) == 0) {
		if (row != n - 1) {
			int tmp = go(i + 1, (state >> 1) | (1 << m - 1));
			tmp += score(a[row][col], a[row + 1][col]);
			ans = max(ans, tmp);
		}
		if (col != m - 1 && (state & 2) == 0) {
			int tmp = go(i + 2, state >> 2);
			tmp += score(a[row][col], a[row][col + 1]);
			ans = max(ans, tmp);
		}
	}
	return ans;
}
int main() {
	cin >> n >> m;
	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << go(0, 0);
}
