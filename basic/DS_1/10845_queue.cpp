#include <iostream>
#include <string>
#include <queue>
using namespace std;
// '\n' ""

int main(){
	int n;
	string s;
	queue<int> q;
	cin >> n;
	while (n--) {
		cin >> s;
		if (s == "push"){
			int num;
			cin >> num;
			q.push(num);
		}
		else if (s == "pop"){
			if (q.empty()) cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (s == "size") cout << q.size() << '\n';
		else if (s == "empty") cout << q.empty() << '\n';
		else if (s == "front"){
			if (q.empty()) cout << -1 << '\n';
			else cout << q.front() << '\n';
		}
		else if (s == "back"){
			if (q.empty()) cout << -1 << '\n';
			else cout << q.back() << '\n';
		}
	}
}