#include <iostream>
#include <string>
using namespace std;
// '\n' ""

int main(){
	int cnt;
	string s;
	cin >> s;
	for (int i=0;i<s.size();i++){
		cnt++;
	}
	cout << cnt;
}