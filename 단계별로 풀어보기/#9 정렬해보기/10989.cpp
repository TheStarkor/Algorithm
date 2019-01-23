#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int n, d[10001] = {0};
	scanf("%d", &n);
	for (int i=0;i<n;i++){
		int tmp;
		scanf("%d", &tmp);
		d[tmp]+=1;
	}
	for (int i=1;i<=10000;i++){
		if (d[i] > 0){
			for (int j=0;j<d[i];j++) printf("%d\n", i);
		}
	}
}
