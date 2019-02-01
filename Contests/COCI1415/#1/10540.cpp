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
	int min_x = 200, min_y = 200, max_x = 0, max_y = 0;
	for (int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;
		min_x = min(x, min_x);
		max_x = max(x, max_x);
		min_y = min(y, min_y);
		max_y = max(y, max_y);
	}
	int l = max(max_x - min_x, max_y - min_y);
	cout << l * l;
}
