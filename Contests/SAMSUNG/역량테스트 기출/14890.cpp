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
int a[101][101];
int main() {
	ios_base::sync_with_stdio(false);
	int n, l; cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		bool ok = true;
		bool check = true;
		for (int j = 1; j < n; j++) {
			if (a[i][j - 1] != a[i][j]) {
				if (abs(a[i][j - 1] - a[i][j]) != 1) break;
				if (a[i][j - 1] > a[i][j]) {
					if (!check) break;
					check = false;
					cnt = 1;
					if (l == 1 && cnt >= 1) {
						check = true;
						cnt = 0;
					}
				}
				else {
					if (cnt < l || !check) break;
					cnt = 1;
				}
			}
			else {
				cnt += 1;
				if(!check){
					if (cnt == l) {
						cnt -= l;
						check = true;
					}
				}
			}
			if (check && j == n - 1) {
				ans += 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		bool ok = true;
		bool check = true;
		for (int j = 1; j < n; j++) {
			if (a[j - 1][i] != a[j][i]) {
				if (abs(a[j - 1][i] - a[j][i]) != 1) break;
				if (a[j - 1][i] > a[j][i]) {
					if (!check) break;
					check = false;
					cnt = 1;
					if (l == 1 && cnt >= 1) {
						check = true;
						cnt = 0;
					}
				}
				else {
					if (cnt < l || !check) break;
					cnt = 1;
				}
			}
			else {
				cnt += 1;
				if (!check) {
					if (cnt == l) {
						cnt -= l;
						check = true;
					}
				}
			}
			if (check && j == n - 1) {
				ans += 1;
			}
		}
	}
	cout << ans;
}
