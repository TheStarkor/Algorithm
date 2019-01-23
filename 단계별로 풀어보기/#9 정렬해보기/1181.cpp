#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <stack>
#include <set>
#include <map>
using namespace std;
bool cmp(string x, string y) {
	if (x.size() == y.size()) return x < y;
	return x.size() < y.size();
}
int main() {
	int n; cin >> n;
	set<string> s;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		s.insert(tmp);
	}
	vector<string> a;
	for (auto it = s.begin(); it != s.end(); it++) a.push_back(*it);
	sort(a.begin(), a.end(), cmp);
	for (auto x : a) cout << x << '\n';
}
