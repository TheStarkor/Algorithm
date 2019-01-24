#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
vector<int> a[1001];
long long time[1001];
int ind[1001];
int d[1001];
int main()
{
	int t; cin >> t;
	while (t--) {
		int n, k; scanf("%d %d", &n, &k);
		memset(time, 0, sizeof(time));
		memset(ind, 0, sizeof(ind));
		memset(d, 0, sizeof(d));
		for (int i = 0; i <= 1000; i++) a[i].clear();
		for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
		for (int i = 0; i < k; i++) {
			int from, to; scanf("%d %d", &from, &to);
			a[from].push_back(to);
			ind[to] += 1;
		}
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (ind[i] == 0) q.push(i);
		}
		for (int i = 0; i < n; i++) {
			int x = q.front(); q.pop();
			time[x] += d[x];
			for (int y : a[x]) {
				if (time[x] > time[y]) time[y] = time[x];
				ind[y] -= 1;
				if (ind[y] == 0) q.push(y);
			}
		}
		int w; cin >> w;
		cout << time[w] << '\n';
	}
}
