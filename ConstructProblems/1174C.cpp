#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int main() {
	int n;
	cin>>n;
	bool prime[100010];
	memset(prime, true, sizeof(prime));
	for (int i =2; i * i <= n; ++i) {
		if (prime[i]) {
			for (int j = i * 2; j <= n; j += i) {
				prime[j] = false;
			}
		}
	}
	int cnt = 0;
	int a[100010];
	for (int i = 2; i <= n; ++i) {
		if (prime[i]) {
			a[i] = ++cnt;
		}
	}
	for (int i = 2; i <= n; ++i) {
		if (!prime[i]) {
			for (int j = 2; j * j <= i; ++j) {
				if (i % j == 0) {
					a[i] = a[j];
				}
			}
		}
	}
	for (int i = 2; i <= n; ++i) {
		cout<<a[i];
		if (i < n) cout<<" ";
		else cout<<endl;
	}
	return 0;
}
