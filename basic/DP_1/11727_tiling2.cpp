#include <iostream>
using namespace std;
int d[1000+1]={1,1,};

int main(){
	int n;
	cin >> n;
	for (int i=2;i<=n;i++){
		d[i] = d[i-1] + 2*d[i-2];
		d[i] %= 10007;
	}
	cout << d[n];
}