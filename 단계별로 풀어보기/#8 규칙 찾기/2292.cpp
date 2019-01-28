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
	int num = 1;
	int cnt = 1;
	int j = 1;
	while (true) {
		if (n <= num) break;
		num += 6 * (j++);
		cnt += 1;
	}
	cout << cnt;
}
