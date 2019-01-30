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
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost) {}
};
int n, m, q;
vector<Edge> a[200001];
bool check[2000001];
vector<int> s;
set<int> ans;
void dfs(int node, int goal, int c) {
	check[node] = true;
	s.push_back(node);
	if (node == goal) {
		ans.insert(c);
		s.pop_back();
		return;
	}
	for (auto x : a[node]) {
		int next = x.to;
		if (!check[next]) {
			if (x.cost > c) {
				x.cost = c;
			}
			dfs(next, goal, x.cost);
			check[next] = false;
		}
	}
	s.pop_back();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		a[from].push_back(Edge(to, cost));
		a[to].push_back(Edge(from, cost));
	}
	int inf = 2000000000;
	for (int i = 0; i < q; i++) {
		int x, y; cin >> x >> y;
		for (int j = 0; j <= n; j++) check[j] = false;
		ans.clear();
		dfs(x, y, inf);
		int ma = 0;
		for (int x : ans) ma = max(ma,x);
		cout << ma << '\n';
	}

}
