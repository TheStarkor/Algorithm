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
vector<int> color[100001];
bool check[100001];
int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<pair<int,int>> a(n);
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		a[i] = make_pair(x, y);
		color[y].push_back(x);
		check[y] = true;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i <= 100000; i++) {
		if (!check[i]) continue;
		sort(color[i].begin(), color[i].end());
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int pos = a[i].first, col = a[i].second;
		if (color[col].size() == 1) continue;
		int x = lower_bound(color[col].begin(), color[col].end(), pos) - color[col].begin();
		if (x == 0) ans += color[col][x + 1] - color[col][x];
		else if (x == (int)color[col].size() - 1) ans += color[col][x] - color[col][x - 1];
		else ans += min(color[col][x + 1] - color[col][x], color[col][x] - color[col][x - 1]);
	}
	cout << ans;
}
