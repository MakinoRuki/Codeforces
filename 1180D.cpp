#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int main() {
	cin>>n>>m;
	for (int i = 0; i < n / 2; ++i) {
		int lc = 0, rc = m - 1;
		for (int j = 0; j < 2 * m; j+=2) {
			printf("%d %d\n", i+1, lc+1);
			printf("%d %d\n", (n-1-i)+1, rc+1);
			// cout<<i+1<<" "<<lc+1<<endl;
			// cout<<(n-1-i)+1<<" "<<rc+1<<endl;
			lc++;
			rc--;
		}
	}
	if (n % 2) {
		int lc = 0, rc = m - 1;
		while(lc < rc) {
			printf("%d %d\n", n/2+1, lc+1);
			printf("%d %d\n", n/2+1, rc+1);
			// cout<<n/2+1<<" "<<lc+1<<endl;
			// cout<<n/2+1<<" "<<rc+1<<endl;
			lc++;
			rc--;
		}
		if (lc == rc) printf("%d %d\n", n/2+1, lc+1);//cout<<n/2+1<<" "<<lc+1<<endl;
	}
	return 0;
}
