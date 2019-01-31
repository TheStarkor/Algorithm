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
struct Edge {
	int to, cost;
	Edge(int to, int cost) : to(to), cost(cost) {}
};
vector<Edge> a[100001];
long long inf = 0x3f3f3f3f;
long long dist[100001];
bool check[100001];
int ans;
void dfs(int node, int end, int mi) {
	check[node] = true;
	if (node == end) {
		ans = mi;
		return;
	}
	for (auto &p : a[node]) {
		int next = p.to;
		if (!check[next]) {
			if (dist[next] > dist[node] + p.cost) {
				dist[next] = dist[node] + p.cost;
			}
			if (mi < p.cost) dfs(next, end, p.cost);
			else dfs(next, end, mi);
		}
	}
}
int main() {
	int n, r1, r2; cin >> n >> r1 >> r2;
	for (int i = 0; i < n - 1; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		a[from].push_back(Edge(to, cost));
		a[to].push_back(Edge(from, cost));
	}
	for (int i = 1; i <= n; i++) dist[i] = inf;
	dist[r1] = 0;
	dfs(r1, r2, 0);
	cout << dist[r2] - ans;
}
