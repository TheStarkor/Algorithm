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
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> a[i][j];
	}
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		if (i < n/2) d[i] = 0;
		else d[i] = 1;
	}
	int ans = 10000000;
	do {
		vector<int> start, link;
		int sum_s = 0, sum_l = 0;
		for (int i = 0; i < n; i++) {
			if (d[i] == 1) start.push_back(i);
			else link.push_back(i);
		}
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				sum_s += a[start[i]][start[j]];
				sum_l += a[link[i]][link[j]];
			}
		}
		int dif = abs(sum_s - sum_l);
		if (ans > dif) ans = dif;
	} while (next_permutation(d.begin(), d.end()));
	cout << ans;
}
