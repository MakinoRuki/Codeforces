#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 100005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
int a[N], b[N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}
	sort(a+1, a+n+1);
	sort(b+1, b+n+1);
	ll det=0;
	int i = n, j = n;
	bool cur=false;
	while(i>=1 || j >= 1) {
		if (!cur) {
			if (i<1) {
				j--;
			} else {
				if (j<1) {
					det += a[i];
					i--;
				} else {
					if (a[i] >= b[j]) {
						det+=a[i];
						i--;
					} else {
						j--;
					}
				}
			}
		} else {
			if (j<1) {
				i--;
			} else {
				if (i<1) {
					det -= b[j];
					j--;
				} else {
					if (b[j]>=a[i]) {
						det -= b[j];
						j--;
					} else {
						i--;
					}
				}
			}
		}
		cur = !cur;
	}
	cout<<det<<endl;
	return 0;
}
