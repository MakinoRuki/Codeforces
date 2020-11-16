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
#define N 2000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, k;
int a[N], b[N];
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}
	for (int i = 1; i <= n; ++i) {
		bool vis[N];
		for (int j = 1; j <= n; ++j) {
			vis[j]=false;
		}
		int p[N];
		for (int j = 1; j <= n; ++j) {
			if (j != i) {
				p[j]=a[j];
				vis[a[j]]=true;
			}
		}
		int cnt=0;
		int id=0;
		for (int j = 1; j <= n; ++j) {
			if (!vis[j]) {
				id=j;
				cnt++;
			}
		}
		if (cnt!= 1) {
			continue;
		}
		p[i]=id;
		int j;
		cnt=0;
		for (j = 1; j <= n; ++j) {
			if (p[j] != b[j]) {
				cnt++;
			}
		}
		if (cnt==1) {
			for (int j = 1; j <= n; ++j) {
				printf("%d", p[j]);
				if (j<n) cout<<" ";
				else cout<<endl;
			}
			break;
		}
	}
	return 0;
}
