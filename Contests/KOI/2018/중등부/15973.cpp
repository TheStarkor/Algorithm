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
typedef long long ll;
struct Square {
	ll x1, x2, y1, y2;
	Square(ll x1, ll y1, ll x2, ll y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};
int PL(Square p, Square q) {
	if (p.x1 == q.x2 || p.x2 == q.x1) {
		if (p.y2 == q.y1) return 0;
		else if (p.y1 == q.y2) return 0;
		else if (p.y1 < q.y2 && q.y2 <= p.y2) return 1;
		else if (p.y1 <= q.y1 && q.y1 < p.y2) return 1;
		else if (q.y1 < p.y2 && p.y2 <= q.y2) return 1;
		else if (q.y1 <= p.y1 && p.y1 < q.y2) return 1;
	}
	if (p.y1 == q.y2 || p.y2 == q.y1) {
		if (p.x1 == q.x2) return 0;
		else if (p.x2 == q.x1) return 0;
		else if (p.x1 <= q.x1 && q.x1 < p.x2) return 1;
		else if (p.x1 < q.x2 && q.x2 <= p.x2) return 1;
		else if (q.x1 <= p.x1 && p.x1 < q.x2) return 1;
		else if (q.x1 < p.x2 && p.x2 <= q.x2) return 1;
	}
	return -1;
}
bool In(Square p, Square q) {
	if (q.y1 < p.y2 && p.y2 <= q.y2) {
		if (p.x2 <= q.x1) return false;
		else if (p.x1 >= q.x2) return false;
		else return true;
	}
	if (q.y1 <= p.y1 && p.y1 < q.y2) {
		if (p.x2 <= q.x1) return false;
		else if (p.x1 >= q.x2) return false;
		else return true;
	}
	if (p.y1 <= q.y1 && q.y2 <= p.y2) {
		if (p.x2 <= q.x1) return false;
		else if (p.x1 >= q.x2) return false;
		else return true;
	}
	if (q.x1 < p.x2 && p.x2 <= q.x2) {
		if (p.y2 <= q.y1) return false;
		else if (p.y1 >= q.y2) return false;
		else return true;
	}
	if (q.x1 <= p.x1 && p.x1 < q.x2) {
		if (p.y2 <= q.y1) return false;
		else if (p.y1 >= q.y2) return false;
		else return true;
	}
	if (p.x1 <= q.x1 && q.x2 <= p.x2) {
		if (p.y2 <= q.y1) return false;
		else if (p.y1 >= q.y2) return false;
		else return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	Square p(x1, y1, x2, y2);
	cin >> x1 >> y1 >> x2 >> y2;
	Square q(x1, y1, x2, y2);
	int t1 = PL(p, q);
	bool t2 = In(q, p) | In(p,q);
	if (t1 == 0) cout << "POINT" << '\n';
	else if (t1 == 1) cout << "LINE" << '\n';
	else if (t2) cout << "FACE" << '\n';
	else cout << "NULL" << '\n';
}
