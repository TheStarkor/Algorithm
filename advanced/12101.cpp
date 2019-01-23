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
long long d[11] = { 1,1,2, };
vector<int> ans;
void print(int n, long long k) {
	if (n == 0) return;
	if (d[n - 1] >= k) {
		ans.push_back(1);
		print(n - 1, k);
	}
	else if (d[n - 2] >= k - d[n-1]) {
		ans.push_back(2);
		print(n - 2, k - d[n - 1]);
	}
	else {
		ans.push_back(3);
		print(n - 3, k - d[n - 1] - d[n - 2]);
	}
}
int main() {
	int n;
	long long k;
	cin >> n >> k;
	for (int i = 3; i <= n; i++) d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	if (d[n] < k) cout << -1 << '\n';
	else {
		print(n, k);
		for (int i = 0; i < ans.size();i++) {
			cout << ans[i];
			if (i != (int)ans.size() - 1) cout << '+';
		}
	}
}
