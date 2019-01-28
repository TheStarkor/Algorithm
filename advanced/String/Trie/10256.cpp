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
int to_int(char x) {
	if (x == 'A') return 0;
	else if (x == 'G') return 1;
	else if (x == 'C') return 2;
	else return 3;
}
struct Node {
	int children[4];
	int pi;
	bool valid;
	Node() {
		for (int i = 0; i < 4; i++) children[i] = -1;
		pi = -1;
		valid = false;
	}
};
vector<Node> trie;
int init() {
	Node x;
	trie.push_back(x);
	return (int)trie.size() - 1;
}
void add(int node, string &s, int index) {
	if (index == s.size()) {
		trie[node].valid = true;
		return;
	}
	int c = to_int(s[index]);
	if (trie[node].children[c] == -1) {
		int next = init();
		trie[node].children[c] = next;
	}
	add(trie[node].children[c], s, index + 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		trie.clear();
		int n, m; cin >> n >> m;
		string s, p;
		cin >> s;
		cin >> p;
		int root = init();
		for (int i = 0; i < m; i++) {
			for (int j = i; j <= m; j++) {
				string tmp = p;
				reverse(tmp.begin() + i, tmp.begin() + j);
				add(root, tmp, 0);
			}
		}
		queue<int> q;
		trie[root].pi = root;
		q.push(root);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int next = trie[cur].children[i];
				if (next == -1) continue;
				if (cur == root) trie[next].pi = root;
				else {
					int x = trie[cur].pi;
					while (x != root && trie[x].children[i] == -1) {
						x = trie[x].pi;
					}
					if (trie[x].children[i] != -1) {
						x = trie[x].children[i];
					}
					trie[next].pi = x;
				}
				int pi = trie[next].pi;
				trie[next].valid |= trie[pi].valid;
				q.push(next);
			}
		}
		int ans = 0;
		int node = root;
		for (int i = 0; i < s.size(); i++) {
			int c = to_int(s[i]);
			while (node != root && trie[node].children[c] == -1) {
				node = trie[node].pi;
			}
			if (trie[node].children[c] != -1) {
				node = trie[node].children[c];
			}
			if (trie[node].valid) ans += 1;
		}
		cout << ans << '\n';
	}
}
