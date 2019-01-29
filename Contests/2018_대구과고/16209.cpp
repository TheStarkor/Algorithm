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
	vector<int> minus;
	vector<int> zero;
	vector<int> plus;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if (tmp < 0) minus.push_back(-tmp);
		else if (tmp == 0) zero.push_back(tmp);
		else plus.push_back(tmp);
	}
	int size_m = minus.size(), size_z = zero.size(), size_p = plus.size();
	vector<int> a(size_m + size_z + size_p);
	sort(minus.begin(), minus.end());
	sort(plus.begin(), plus.end());
	for (int i = 0; i < size_m / 2; i++) {
		a[size_m - 1 - i] = -minus[2*i];
		a[i] = -minus[2*i + 1];
	}
	if (size_m % 2 == 1) a[size_m / 2] = -minus[size_m - 1];
	for (int i = size_m; i < (size_m + size_z); i++) {
		a[i] = 0;
	}
	for (int i = size_m + size_z, k = 0; k < size_p / 2; i++, k++) {
		a[i] = plus[2 * k];
		a[size_m + size_z + size_p - 1 - k] = plus[2 * k + 1];
	}
	if (size_p % 2 == 1) a[size_m + size_z + (size_p / 2)] = plus[size_p - 1];
	for (int i = 0; i < size_m + size_z + size_p; i++) cout << a[i] << " ";
}
