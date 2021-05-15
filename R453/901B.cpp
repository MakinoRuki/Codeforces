#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#define N 200
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int n, m;
int h;
int c1[N], c2[N];
int main() {
	cin>>n;
	memset(c1, 0, sizeof(c1));
	memset(c2, 0, sizeof(c2));
	c1[0] = 1;
	bool ok=true;
	for (int i = 1; i <= n; ++i) {
		int tc[N];
		memset(tc, 0, sizeof(tc));
		bool ok2 = true;
		for (int j = n; j >= 0; --j) {
			tc[j] = c2[j];
			if (j > 0) tc[j] += c1[j-1];
			if (abs(tc[j]) > 1) {
				ok2=false;
				break;
			}
		}
		if (!ok2) {
			memset(tc, 0, sizeof(tc));
			for (int j = n; j >= 0; --j) {
				tc[j] = -c2[j];
				if (j>0) tc[j] += c1[j-1];
				if (abs(tc[j]) > 1) {
					ok = false;
					break;
				}
			}
		}
		if (!ok) break;
		for (int j = 0; j <= n; ++j) {
			c2[j] = c1[j];
			c1[j] = tc[j];
		}
	//	if (i==1) cout<<"v="<<c1[1]<<" "<<c2[0]<<endl;
	}
	if (!ok) puts("-1");
	else {
		int m1=0,m2=0;
		for (int i = 0; i <= n; ++i) {
			if (c1[i] != 0) m1 = i;
			if (c2[i] != 0) m2 = i;
		}
		printf("%d\n", m1);
		for (int i = 0; i <= m1; ++i) {
			printf("%d", c1[i]);
			if (i < m1) cout<<" ";
			else cout<<endl;
		}
		printf("%d\n", m2);
		for (int i = 0; i <= m2; ++i) {
			printf("%d", c2[i]);
			if (i < m2) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
