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
struct Trie {
	struct Node {
		int children[2];
		bool valid;
		Node() {
			for (int i = 0; i < 2; i++) {
				children[i] = -1;
			}
			valid = false;
		}
	};
	vector<Node> trie;
	int root;
	int init() {
		Node x;
		trie.push_back(x);
		return (int)trie.size() - 1;
	}
	Trie() {
		root = init();
	}
	void add(int node, int num, int bit) {
		if (bit == -1) {
			trie[node].valid = true;
			return;
		}
		int c = (num >> bit) & 1;
		if (trie[node].children[c] == -1) {
			int next = init();
			trie[node].children[c] = next;
		}
		add(trie[node].children[c], num, bit - 1);
	}
	void add(int num) {
		add(root, num, 31);
	}
	int query(int node, int num, int bit) {
		if (bit == -1) return 0;
		int c = (num >> bit) & 1;
		bool ok = true;
		c = 1 - c;
		if (trie[node].children[c] == -1) {
			c = 1 - c;
			ok = false;
		}
		if (trie[node].children[c] == -1) return 0;
		int next = 0;
		if (ok) next = 1 << bit;
		return next | query(trie[node].children[c], num, bit - 1);
	}
	int query(int num) {
		return query(root, num, 31);
	}
};
int main() {
	int n; cin >> n;
	int ans = 0;
	Trie trie;
	while (n--) {
		int num; scanf("%d", &num);
		trie.add(num);
		int tmp = trie.query(num);
		if (ans < tmp) ans = tmp;
	}
	cout << ans;
}
