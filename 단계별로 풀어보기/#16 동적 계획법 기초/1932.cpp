#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <stack>
#include <set>
#include <map>
using namespace std;
int a[501][501];
int d[501][501];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	d[0][0] = a[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) d[i][j] = d[i - 1][j] + a[i][j];
			if (j == i) d[i][j] = d[i - 1][j - 1] + a[i][j];
			d[i][j] = max(d[i - 1][j - 1] + a[i][j], d[i - 1][j] + a[i][j]);
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		ans = max(ans, d[n - 1][i]);
	}
	cout << ans;
}
