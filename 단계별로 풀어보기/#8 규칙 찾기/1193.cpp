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
	int sum = 1;
	int i = 1;
	while (true) {
		if (n <= sum) {
			break;
		}
		i += 1;
		sum += i;
	}
	if (i % 2 == 0) {
		n -= (i - 1)*i / 2;
		cout << n << "/" << i + 1 - n;
	}
	else {
		n -= (i - 1)*i / 2;
		cout << i + 1 - n << "/" << n;
	}
}
