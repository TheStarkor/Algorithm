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
vector<int> processing(string p) {
	int m = p.size();
	vector<int> pi(m);
	pi[0] = 0;
	int j = 0;
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j]) {
			pi[i] = j + 1;
			j += 1;
		}
		else {
			pi[0] = 0;
		}
	}
	return pi;
}
int main()
{
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	string a;
	int ans = 0;
	for (char c : s) {
		a = c + a;
		vector<int> next = processing(a);
		int m = next.size();
		for (int i = 0; i < m; i++) {
			if (ans < next[i]) ans = next[i];
		}
	}
	cout << ans << '\n';
	return 0;
}
