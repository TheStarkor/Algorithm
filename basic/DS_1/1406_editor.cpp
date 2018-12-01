#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
// '' ""
char s[600000];
int main(){
	int n;
	stack<char> left, right;
	char command, a;
	scanf("%s", s);
	scanf("%d", &n);
	int co = strlen(s);
	for(int i=0;i<co;i++){
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
			if (right.size() != 0){
				left.push(right.top());
				right.pop();
			}
		}
		else if (command == 'B') {
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
		printf("%c", right.top());
		right.pop();
	}
}