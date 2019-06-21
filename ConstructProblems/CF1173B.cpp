#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int main() {
	cin>>n;
	int m = n/2+1;
	cout<<m<<endl;
	for (int i = 1; i <= m; ++i) {
		cout<<1<<" "<<i<<endl;
	}
	for (int i = 1; i <= n - m; ++i) {
		cout<<1 + i<<" "<<m<<endl;
	}
	return 0;
}
