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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int a[(1<<16)+2];
int b[(1<<16)+2];
int main() {
	cin>>n;
	for (int i = 2; i <= n; ++i) {
		printf("XOR %d %d\n", 1, i);
		fflush(stdout);
		scanf("%d", &a[i]);
	}
	unordered_map<int,int> mp;
	mp.clear();
	for (int i = 2; i <= n; ++i) {
		if (mp.find(a[i]) != mp.end()) {
			int id=mp[a[i]];
			printf("AND %d %d\n", id, i);
			fflush(stdout);
			int res;
			scanf("%d", &res);
			b[id]=res;
			b[i]=res;
			if (id != 1) b[1] = a[id] ^ b[id];
			for (int i = 2; i <= n; ++i) {
				b[i]=b[1]^a[i];
			}
			printf("!");
			for (int i =1; i <= n; ++i) {
				printf(" %d", b[i]);
			}
			cout<<endl;
			return 0;
		}
		mp[a[i]] = i;
	}
	int i=2;
	for (i=2; i <= n; ++i) {
		if (a[i]==0) {
			break;
		}
	}
	if (i<=n) {
		printf("AND %d %d\n", 1, i);
		fflush(stdout);
		int res;
		scanf("%d", &res);
		b[1]=res;
		for (int i =2; i <= n; ++i) {
			b[i]=b[1]^a[i];
		}
		printf("!");
		for (int i = 1; i <= n; ++i) {
			printf(" %d", b[i]);
		}
		cout<<endl;
		return 0;
	}
	mp.clear();
	for (int i = 2; i <= n; ++i) {
		int x=(n-1)^a[i];
		if (mp.find(x) != mp.end()) {
			int id=mp[x];
			int y,z;
			printf("AND %d %d\n", 1, id);
			fflush(stdout);
			scanf("%d", &y);
			printf("AND %d %d\n", 1, i);
			fflush(stdout);
			scanf("%d", &z);
			b[id] = (n-1+a[id]+2*y-a[i]-2*z)/2;
			b[i] = (n-1-a[id]-2*y+a[i]+2*z)/2;
			b[1] = b[id]^a[id];
			for (int i= 2; i <= n; ++i) {
				b[i]=b[1]^a[i];
			}
			printf("!");
			for (int i = 1; i <= n; ++i) {
				printf(" %d\n", b[i]);
			}
			cout<<endl;
			return 0;
		} else {
			mp[a[i]] = i;
		}
	}
	return 0;
}
