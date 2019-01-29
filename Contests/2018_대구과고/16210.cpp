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
	vector<long long> x(n), y(n), a, b;
	vector<long long> sum_x(n + 1), sum_y(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> x[i-1] >> y[i-1];
	}
	a = x;
	b = y;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 1; i <= n; i++) {
		sum_x[i] = sum_x[i - 1] + a[i - 1];
		sum_y[i] = sum_y[i - 1] + b[i - 1];
	}
	int ans = 0;
	long long min;
	for (int i = 0; i < n; i++) {
		int pos_x = lower_bound(a.begin(), a.end(), x[i]) - a.begin();
		int pos_y = lower_bound(b.begin(), b.end(), y[i]) - b.begin();
		long long tmp = 0;
		tmp += (x[i] * pos_x - sum_x[pos_x]) + (sum_x[n] - sum_x[pos_x + 1]) - x[i] * (n - pos_x - 1);
		tmp += (y[i] * pos_y - sum_y[pos_y]) + (sum_y[n] - sum_y[pos_y + 1]) - y[i] * (n - pos_y - 1);
		if (i == 0) {
			min = tmp;
			ans = i + 1;
		}
		else {
			if (min > tmp) {
				min = tmp;
				ans = i + 1;
			}
		}
	}
	cout << ans;
}
