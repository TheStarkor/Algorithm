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
int cnt;
bool check[10001];
vector<int> a[10001];
void dfs(int node) {
	if (check[node]) return;
	check[node] = true;
	for (int y : a[node]) {
		dfs(y);
	}
	cnt += 1;
}
int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d %d", &x, &y);
		a[y].push_back(x);
	}
	vector<int> ans;
	int max = 0;
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		memset(check, false, sizeof(check));
		dfs(i);
		if (cnt > max) {
			ans.clear();
			max = cnt;
			ans.push_back(i);
		}
		else if (cnt == max) ans.push_back(i);
	}
	for (int x : ans) printf("%d ", x);
}
