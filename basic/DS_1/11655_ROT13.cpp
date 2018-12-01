#include <iostream>
#include <string>
using namespace std;
// '\n' ""

int main(){
	string s;
	getline(cin,s);
	for (int i=0;s[i];i++){
		if (int(s[i]) >= 65 && int(s[i]) <= 90) printf("%c",(int(s[i])-65+13)%26+65);
		else if (int(s[i] >= 97 && int(s[i]) <= 97+25)) printf("%c",(int(s[i])-97+13)%26+97);
		else cout << s[i];
	}
}