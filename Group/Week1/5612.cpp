#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	int tmp = m;
	int res = 0;
	for (int i = 0; i < n; i++){
		int add, sub; cin >> add >> sub;
		tmp += (add - sub);
		if (tmp < 0) {
			cout << 0 << '\n';
			return 0;
		}
		res = max(res, tmp);
	}
	cout << res << '\n';
	return 0;
}