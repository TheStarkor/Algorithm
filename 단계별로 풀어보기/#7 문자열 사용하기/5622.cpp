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
	int a[26] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
	string s; cin >> s;
	int ans = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		ans += a[(int)(s[i] - 'A')];
	}
	cout << ans;
}
