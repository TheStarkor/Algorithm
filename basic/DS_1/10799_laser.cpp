#include <iostream> 
#include <string>
#include <stack>
using namespace std;
// '' ""

int main(){
	int cnt = 0;
	string s;
	stack<int> tmp;
	cin >> s;
	
	for (int i=0;i<s.size();i++){
		if(s[i] == '(') tmp.push(i);
		else{
			if (tmp.top() == i-1){
				tmp.pop();
				cnt = cnt + tmp.size();
			}
			else {
				cnt++;
				tmp.pop();
			}
		}
	}
	cout << cnt;
}