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
int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int b, c; cin >> b >> c;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += 1;
		a[i] -= b;
		if (a[i] > 0) {
			int num = (a[i] - 1) / c;
			ans += num + 1;
		}
	}
	cout << ans;
}
