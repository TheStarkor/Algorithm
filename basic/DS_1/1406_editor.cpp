#include <iostream> 
#include <string>
#include <stack>
using namespace std;
// '' ""

int main(){
	int n;
	stack<char> left, right;
	char command, a;
	string s, res;
	cin >> s;
	cin >> n;
	
	for(int i=0;i<s.size();i++){
		left.push(s[i]);
	}
	for(int i=0;i<n;i++){
		cin >> command;
		if (command == 'L'){
			if (left.size() != 0){
				right.push(left.top());
				left.pop();
			}
		}
		else if (command == 'D'){
			if (right.size() != n){
				left.push(right.top());
				right.pop();
			}
		}
		else if (command == 'B'){
			if (left.size() != 0) left.pop();
		}
		else if (command == 'P'){
			cin >> a;
			left.push(a);
		}
	}
	int cnt = left.size();
	for(int i=0;i<cnt;i++){
		right.push(left.top());
		left.pop();
	}
	for(int i=0;right.size();i++){
		res += right.top(); // append left
		right.pop();
	}
	cout << res;
}