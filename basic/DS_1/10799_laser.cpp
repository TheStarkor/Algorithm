#include <iostream> 
#include <vector>
#include <string>
#include <stack>
using namespace std;
// '' ""

int main(){
	int cnt = 0;
	string s;
	vector<int> laser(0);
	stack<int> tmp;
	cin >> s;
	
	for (int i=0;i<s.size();i++){
		if(s[i] == '(') tmp.push(i);
		else{
			if (tmp.top() == i-1){
				laser.push_back(i-1);
				tmp.pop();
			}
			else{
				for (int j=0;j<laser.size();j++){
					if (tmp.top() < laser[j] && laser[j] < i) cnt++;
				}
				tmp.pop();
				cnt++;
			}
		}
	}
	cout << cnt;
}