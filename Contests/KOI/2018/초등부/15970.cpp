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
bool check[5001];
int main() {
	ios_base::sync_with_stdio(false);
	vector<pair<int,int>> pos;
	vector<int> a[5001];
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		pos.push_back(make_pair(x,y));
		a[y].push_back(x);
		check[y] = true;
	}
	sort(pos.begin(), pos.end());
	for (int i = 0; i <= 5000; i++) {
		if (check[i]) {
			sort(a[i].begin(), a[i].end());
		}
	}
	int ans = 0;
	for (auto &p : pos) {
		int col = p.second;
		int x = lower_bound(a[col].begin(), a[col].end(), p.first) - a[col].begin();
		if (x == 0) ans += a[col][1] - a[col][0];
		else if (x == a[col].size() - 1) ans += a[col][x] - a[col][x - 1];
		else ans += min(a[col][x] - a[col][x - 1], a[col][x + 1] - a[col][x]);
	}
	cout << ans;
}
