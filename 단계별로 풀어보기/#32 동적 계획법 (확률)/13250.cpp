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
double d[1000001];
int main()
{
	int n; cin >> n;
	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j <= 6; j++) {
			if (i - j >= 0) d[i] += d[i - j] / 6;
		}
	}
	cout << setprecision(10) << d[n];
}
