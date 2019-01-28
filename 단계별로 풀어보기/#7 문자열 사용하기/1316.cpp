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
bool c[26];
bool check(string s) {
	memset(c, false, sizeof(c));
	c[(int)(s[0] - 'a')] = true;
	for (int i = 1; i < (int)s.size(); i++) {
		int x = (int)(s[i] - 'a');
		if (c[x]) {
			if (s[i] != s[i - 1]) return false;
		}
		c[x] = true;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int ans = 0;
	while (n--) {
		string s; cin >> s;
		if (check(s)) ans += 1;
	}
	cout << ans;
}
