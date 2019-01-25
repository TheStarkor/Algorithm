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
vector<int> kmp(string s, string p) {
	vector<int> ans;
	int n = s.size(), m = p.size(), j = 0;
	vector<int> pi = processing(p);
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j]) j = pi[j - 1];
		if (j == m - 1) {
			ans.push_back(i - m + 1);
			j = pi[j];
		}
		else j += 1;
	}
	return ans;
}
int main()
{
	string a, b;
	cin >> a;
	cin >> b;
	b = b + b;
	b.pop_back();
	auto ans = kmp(b, a);
	cout << ans.size();
}
