#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#define N 5002
using namespace std;
typedef long long ll;
int n, m;
int a[N];
int main() {
	cin>>n>>m;
	int i;
	for (i = 1; i <= n; ++i) {
		if (m == 0) break;
		//cout<<i<<" "<<m<<endl;
		if (i == 1) a[i] = 1;
		else if (i == 2) a[i] = 2;
		else {
			int det = (i-1)/2;
			if (det <= m) {
				a[i] = a[1]+a[i-1];
				m -= det;
			} else {
				int l = i - 2*m;
				a[i] = a[l]+a[i-1];
				m = 0;
			}
		}
	}
	if (m > 0) {
		cout<<-1<<endl;
	} else {
		int now = 1000000000;
		for (int j = n; j >= i; --j) {
			a[j] = now;
			now -= 2*n;
		}
		for (int i = 1; i <= n; ++i) {
			cout<<a[i];
			if (i < n) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
