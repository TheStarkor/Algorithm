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
string s;
int solution() {
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (i == s.size() - 1) {
			ans += 1;
			break;
		}
		if (s[i] == 'c') {
			if (s[i + 1] == '=') i += 1;
			else if (s[i + 1] == '-') i += 1;
			ans += 1;
		}
		else if (s[i] == 'd') {
			if (s[i + 1] == 'z') {
				if (s[i + 2] == '=') i += 2;
			}
			else if (s[i + 1] == '-') i += 1;
			ans += 1;
		}
		else if (s[i] == 'l') {
			if (s[i + 1] == 'j') i += 1;
			ans += 1;
		}
		else if (s[i] == 'n') {
			if (s[i + 1] == 'j') i += 1;
			ans += 1;
		}
		else if (s[i] == 's') {
			if (s[i + 1] == '=') i += 1;
			ans += 1;
		}
		else if (s[i] == 'z') {
			if (s[i + 1] == '=') i += 1;
			ans += 1;
		}
		else ans += 1;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> s;
	cout << solution();
}
