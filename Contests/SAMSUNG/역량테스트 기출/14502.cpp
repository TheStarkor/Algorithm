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
int n, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int a[9][9];
int cnt_0 = 0;
queue<pair<int, int>> q;
int solve(int x1, int y1, int x2, int y2, int x3, int y3) {
	int tmp = cnt_0 - 3;
	int d[9][9];
	queue<pair<int,int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == x1 && j == y1) d[i][j] = 1;
			else if (i == x2 && j == y2) d[i][j] = 1;
			else if (i == x3 && j == y3) d[i][j] = 1;
			else d[i][j] = a[i][j];
			if (d[i][j] == 2) q.push(make_pair(i, j));
		}
	}
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second; q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (d[nx][ny] == 0) {
					d[nx][ny] = 2;
					tmp -= 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return tmp;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 0) cnt_0 += 1;
			if (a[i][j] == 2) q.push(make_pair(i, j));
		}
	}
	int ans = 0;
	for (int i = 0; i < n*m; i++) {
		for (int j = i + 1; j < n*m; j++) {
			for (int k = j + 1; k < n*m; k++) {
				int x1 = i / m, y1 = i % m, x2 = j / m, y2 = j % m, x3 = k / m, y3 = k % m;
				if (a[x1][y1] == 0 && a[x2][y2] == 0 && a[x3][y3] == 0) {
					int tmp = solve(x1, y1, x2, y2, x3, y3);
					if (tmp > ans) ans = tmp;
				}
			}
		}
	}
	cout << ans;
}
