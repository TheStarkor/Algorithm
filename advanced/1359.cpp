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
int c[9][9];
int main()
{
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i <= 8; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) c[i][j] = 1;
			else {
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			}
		}
	}
	double ans = 0.0;
	for (int i = k; i <= m; i++) {
		ans += c[m][i] * c[n - m][m - i];
	}
	ans /= c[n][m];
	cout << setprecision(20) << ans;
}
