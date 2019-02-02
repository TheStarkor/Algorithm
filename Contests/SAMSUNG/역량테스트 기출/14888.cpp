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
int a[15];
int n, plu, minu, multi, mod;
int inf = 2000000000;
int fi[11][11][11][11];
int se[11][11][11][11];
void solve(int ind, int pl, int mi, int mu, int mo) {
	if (ind == n) return;
	if (pl > plu || mi > minu || mu > multi || mo > mod) return;
	fi[pl + 1][mi][mu][mo] = max(fi[pl + 1][mi][mu][mo], fi[pl][mi][mu][mo] + a[ind]);
	se[pl + 1][mi][mu][mo] = min(se[pl + 1][mi][mu][mo], se[pl][mi][mu][mo] + a[ind]);
	solve(ind + 1, pl + 1, mi, mu, mo);
	fi[pl][mi + 1][mu][mo] = max(fi[pl][mi + 1][mu][mo], fi[pl][mi][mu][mo] - a[ind]);
	se[pl][mi + 1][mu][mo] = min(se[pl][mi + 1][mu][mo], se[pl][mi][mu][mo] - a[ind]);
	solve(ind + 1, pl, mi + 1, mu, mo);
	fi[pl][mi][mu + 1][mo] = max(fi[pl][mi][mu + 1][mo], fi[pl][mi][mu][mo] * a[ind]);
	se[pl][mi][mu + 1][mo] = min(se[pl][mi][mu + 1][mo], se[pl][mi][mu][mo] * a[ind]);
	solve(ind + 1, pl, mi, mu + 1, mo);
	fi[pl][mi][mu][mo + 1] = max(fi[pl][mi][mu][mo + 1], fi[pl][mi][mu][mo] / a[ind]);
	se[pl][mi][mu][mo + 1] = min(se[pl][mi][mu][mo + 1], se[pl][mi][mu][mo] / a[ind]);
	solve(ind + 1, pl, mi, mu, mo + 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> plu >> minu >> multi >> mod;
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			for (int k = 0; k < 11; k++) {
				for (int l = 0; l < 11; l++) {
					fi[i][j][k][l] = -inf;
					se[i][j][k][l] = inf;
				}
			}
		}
	}
	fi[0][0][0][0] = a[0];
	se[0][0][0][0] = a[0];
	solve(1, 0, 0, 0, 0);
	cout << fi[plu][minu][multi][mod] << '\n' << se[plu][minu][multi][mod];
}
