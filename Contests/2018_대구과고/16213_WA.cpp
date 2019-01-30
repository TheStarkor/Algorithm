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
struct MaximumFlow {
	struct Edge {
		int to;
		int capacity;
		Edge *rev;
		Edge(int to, int capacity) : to(to), capacity(capacity){}
	};
	int n;
	int source, sink;
	vector<vector<Edge *>> graph;
	vector<vector<Edge *>> tmp;
	vector<bool> check;
	MaximumFlow(int n) : n(n) {
		graph.resize(n);
		check.resize(n);
	};
	void add_edge(int u, int v, int cap) {
		Edge *ori = new Edge(v, cap);
		Edge *rev = new Edge(u, 0);
		ori->rev = rev;
		rev->rev = ori;
		graph[u].push_back(ori);
		graph[v].push_back(rev);
	}
	int dfs(int x, int c) {
		if (check[x]) return 0;
		check[x] = true;
		if (x == sink) return c;
		for (int i = 0; i < tmp[x].size(); i++) {
			if (tmp[x][i]->capacity > 0) {
				int nc = tmp[x][i]->capacity;
				if (c != 0 && c < nc) {
					nc = c;
				}
				int f = dfs(tmp[x][i]->to, nc);
				if (f) {
					tmp[x][i]->capacity -= f;
					tmp[x][i]->rev->capacity += f;
					return f;
				}
			}
		}
	}
	void init() {
		tmp = graph;
	}
	int flow(int source, int si) {
		int ans, i = 0;
		sink = si;
		init();
		while (true) {
			fill(check.begin(), check.end(), false);
			if (i == 0) {
				ans = dfs(source, 0);
				if (ans == 0) break;
				i += 1;
			}
			else {
				int f = dfs(source, 0);
				if (f == 0) break;
				if (f > ans) ans = f;
				cout << f << '\n';
			}
		}
		return ans;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	int n, m, q; cin >> n >> m >> q;
	MaximumFlow mf(n+1);
	for (int i = 0; i < m; i++) {
		int a, b, v; cin >> a >> b >> v;
		mf.add_edge(a, b, v);
		mf.add_edge(b, a, v);
	}
	for (int i = 0; i < q; i++) {
		int a, b; cin >> a >> b;
		cout << mf.flow(a, b) << '\n';
	}
}
