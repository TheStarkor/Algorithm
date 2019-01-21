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
int go(int i, int state){
	if (i == n * m) {
		if (state == 0) return 1;
		else return 0;
	}
	int &ans = d[i][state];
	if (ans != -1) return ans;
	ans = 0;
	if (state & 1) ans = go(i + 1, (state >> 1));
	else {
		ans = go(i + 1, (state >> 1) | (1 << (m - 1)));
		if ((i%m) != (m - 1) && (state & 2) == 0) {
			ans += go(i + 2, (state >> 2));
		}
	}
	ans %= 9901;
	return ans;
}
int main() {
	cin >> n >> m;
	memset(d, -1, sizeof(d));
	cout << go(0, 0);
}
