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
int a[101];
int b[101];
int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		cout << b[i] * i - b[i - 1] * (i-1) << " ";
	}
}
