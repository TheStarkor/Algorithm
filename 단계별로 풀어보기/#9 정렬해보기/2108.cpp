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
int d[8001];
int main() {
	int n; cin >> n;
	vector<int> a(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
		d[a[i] + 4000] += 1;
	}
	cout << round((double)sum / n) << '\n';
	sort(a.begin(), a.end());
	cout << a[n / 2] << '\n';
	vector<int> ans;
	int cnt = 0;
	for (int i = 0; i <= 8000; i++) {
		if (d[i] == 0) continue;
		if (d[i] > cnt) {
			cnt = d[i];
			ans.clear();
			ans.push_back(i - 4000);
		}
		else if (d[i] == cnt) ans.push_back(i - 4000);
	}
	sort(ans.begin(), ans.end());
	if (ans.size() >= 2) cout << ans[1] << '\n';
	else cout << ans[0] << '\n';
	cout << a[n - 1] - a[0] << '\n';
}
