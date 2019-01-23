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
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	string s; cin >> s;
	vector<int> a;
	for (int i = 0; i < s.size(); i++) {
		a.push_back((int)(s[i]-'0'));
	}
	sort(a.begin(), a.end(), cmp);
	for (int x : a) cout << x;
}
