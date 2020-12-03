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
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 20005
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,q;
int t;
int p[N];
int lm[N], rm[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &p[i]);
		}
		for (int i = 1; i <= n; ++i) {
			if (i==1) lm[i]=i;
			else {
				lm[i]=lm[i-1];
				if (p[i] < p[lm[i]]) {
					lm[i] = i;
				}
			}
		}
		for (int i = n; i >= 1; --i) {
			if (i==n) rm[i]=i;
			else {
				rm[i] = rm[i+1];
				if (p[i] < p[rm[i]]) {
					rm[i] = i;
				}
			}
		}
		bool found=false;
		for (int i = 2; i < n; ++i) {
			if (p[i] > p[lm[i-1]] && p[i] > p[rm[i+1]]) {
				found=true;
				cout<<"YES"<<endl;
				printf("%d %d %d\n", lm[i-1], i, rm[i+1]);
				break;
			}
		}
		if (!found) {
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
