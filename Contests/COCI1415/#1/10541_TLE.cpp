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
int cnt[26];
int num[26][1000001];
string s;
int count(int n, char c) {
	if (num[c - 'A'][n] != -1) return num[c - 'A'][n];
	num[c - 'A'][0] = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == c) num[c-'A'][i+1] += 1;
		num[c - 'A'][i + 1] += num[c - 'A'][i];
	}
	return num[c - 'A'][n];
}
int main() {
	ios_base::sync_with_stdio(false);
	long long n; cin >> n;
	cin >> s;
	memset(num, -1, sizeof(num));
	int len = s.size();
	for (int i = 0; i < len; i++) {
		int x = s[i] - 'A';
		cnt[x] += 1;
	}
	int k; cin >> k;
	while (k--) {
		long long a;
		int b; char c;
		cin >> a >> c;
		b = c - 'A';
		long long ans = 0;
		long long l, r;
		if (a % 2 == 0) {
			l = (((a / 2) % len) * ((a - 1) % len) + 1) % len;
			r = (((a / 2) % len) * ((a + 1) % len)) % len;
		}
		else {
			l = ((a % len) * (((a - 1) / 2) % len) + 1) % len;
			r = ((a % len) * (((a + 1) / 2) % len)) % len;
		}
		if (l == 0) l = len;
		if (r == 0) r = len;
		if ((len - l + 1) >= a) {
			ans += count(r, c) - count(l - 1, c);
		}
		else {
			ans += cnt[b] - count(l - 1, c);
			ans += cnt[b] * (a - len + l - 1) / len;
			if (r != len) ans += count(r, c);
		}
		cout << ans << '\n';
	}
}
