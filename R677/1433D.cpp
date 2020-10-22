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
#define N 6000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n;
int a[N];
int par[N];
int find(int x) {
	return x==par[x] ? x : par[x]=find(par[x]);
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		int n;
		scanf("%d", &n);
		set<int> ss;
		ss.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			ss.insert(a[i]);
			par[i]=i;
		}
		if (ss.size()<=1) {
			cout<<"NO"<<endl;
		} else {
			cout<<"YES"<<endl;
			for (int i =1 ; i <= n; ++i) {
				int j;
				for (j = 1; j <= n; ++j) {
					if (i!=j && a[i] != a[j]) {
						int pi=find(i);
						int pj=find(j);
						if (pi != pj) {
							printf("%d %d\n", i, j);
							par[pi]=pj;
							break;
						}
					}
				}
			}
		}
	}
	return 0;
}
