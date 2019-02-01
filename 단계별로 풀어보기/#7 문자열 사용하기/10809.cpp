#include <iostream>
#include <string>
using namespace std;
// '\n' ""

int main(){
	int n[26];
	fill_n(n, 26, -1);
	string s;
	cin >> s;

	for(int i=0;i<s.size();i++){
		if (n[int(s[i]-97)] == -1) n[int(s[i]-97)] = i;
	}
	for(int i=0;i<26;i++) cout << n[i] << " ";
}
