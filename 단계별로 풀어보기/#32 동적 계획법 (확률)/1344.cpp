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
double d[20][20][20];
bool prime(int x) {
	if (x <= 1) return false;
	if (x == 2) return true;
	for (int i = 2; i*i <= x; i++) {
		if (x%i == 0) return false;
	}
	return true;
}
int main()
{
	double tmp[2], p[4];
	for (int i = 0; i < 2; i++) {
		cin >> tmp[i];
		tmp[i] /= 100;
	}
	p[0] = (1 - tmp[0]) * (1 - tmp[1]);
	p[1] = tmp[0] * (1 - tmp[1]);
	p[2] = (1 - tmp[0]) * tmp[1];
	p[3] = tmp[0] * tmp[1];
	d[0][0][0] = 1;
	for (int s = 1; s <= 18; s++) {
		for (int a = 0; a <= s; a++) {
			for (int b = 0; b <= s; b++) {
				if (a == 0 && b == 0) d[s][0][0] = p[0] * d[s - 1][0][0];
				else if (a == 0) d[s][0][b] = d[s - 1][0][b] * p[0] + d[s - 1][0][b - 1] * p[2];
				else if (b == 0) d[s][a][0] = d[s - 1][a][0] * p[0] + d[s - 1][a - 1][0] * p[1];
				else {
					d[s][a][b] = d[s - 1][a][b] * p[0] + d[s - 1][a - 1][b] * p[1] + d[s - 1][a][b - 1] * p[2] + d[s - 1][a - 1][b - 1] * p[3];
				}
			}
		}
	}
	double ans = 0;
	for (int i = 0; i <= 18; i++) {
		for (int j = 0; j <= 18; j++) {
			if (prime(i) || prime(j)) {
				ans += d[18][i][j];
			}
		}
	}
	cout << setprecision(20) << ans;
}
