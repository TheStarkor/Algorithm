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
	Edge(int to, int cost) : to(to), cost(cost) {};
};
vector<Edge> a[200001];
bool chk_ans[200001];
bool check[200001];
long long dist[200001];
long long tmp[200001];
long long inf = 999999999999999999LL;
void init(int n) {
	for (int i = 0; i <= n; i++) tmp[i] = inf;
	memset(check, false, sizeof(check));
}
int main() {
	ios_base::sync_with_stdio(false);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int from, to, cost; cin >> from >> to >> cost;
		a[from].push_back(Edge(to, cost));
		a[to].push_back(Edge(from, cost));
	}
	for (int i = 0; i <= n; i++) dist[i] = inf;
	priority_queue<pair<int,int>> pq;
	dist[1] = 0;
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		auto next = pq.top(); pq.pop();
		int x = next.second;
		if (check[x]) continue;
		check[x] = true;
		for (auto &p : a[x]) {
			if (dist[p.to] > dist[x] + p.cost) {
				dist[p.to] = dist[x] + p.cost;
				pq.push(make_pair(-dist[p.to], p.to));
			}
		}
	}
	vector<int> foll(k);
	for (int i = 0; i < k; i++) cin >> foll[i];
	for (int num = 0; num < k; num++) {
		priority_queue<pair<int, int>> q;
		init(n);
		tmp[foll[num]] = 0;
		chk_ans[foll[num]] = true;
		q.push(make_pair(0, foll[num]));
		while (!q.empty()) {
			auto p = q.top(); q.pop();
			int x = p.second;
			if (check[x]) continue;
			check[x] = true;
			for (auto &r : a[x]) {
				if (tmp[r.to] > tmp[x] + r.cost) {
					tmp[r.to] = tmp[x] + r.cost;
					if (tmp[r.to] <= dist[r.to]) chk_ans[r.to] = true;
					q.push(make_pair(-tmp[r.to], r.to));
				}
			}
		}
	}
	vector<int> ans;
	for (int i = 2; i <= n; i++) {
		if (!chk_ans[i]) ans.push_back(i);
	}
	if ((int)ans.size() == 0) cout << "0";
	else {
		for (int x : ans) cout << x << " ";
	}
}
