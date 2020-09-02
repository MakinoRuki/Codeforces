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
#define N 1005
#define eps 1e-6
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int m,n;
bool seq[32];
int main() {
	memset(seq, false, sizeof(seq));
	//cout<<(1<<29)<<endl;
	//cout<<1000000000+1000000000<<endl;
	//cout<<(1000000000+1<=(1LL<<31)-1)<<endl;
	scanf("%d%d",&m,&n);
	for (int i = 0; i < n; ++i) {
		printf("%d\n", m);
		fflush(stdout);
		int x;
		scanf("%d", &x);
		if (x==0) {
			return 0;
		}
		if (x==-1) {
			continue;
		} else {
			seq[i] = true;
		}
	}
	int cur=0;
	int l = 1, r = m;
	while(l < r) {
		int mid=(l+r)/2;
		printf("%d\n", mid);
		fflush(stdout);
		int x;
		scanf("%d", &x);
		if (x==0) {
			return 0;
		}
		if (x>0) {
			if (!seq[cur]) {
				l=mid+1;
			} else {
				r=mid;
			}
		} else {
			if (!seq[cur]) {
				r=mid;
			} else {
				l=mid+1;
			}
		}
		cur=(cur+1)%n;
	}
	printf("%d\n", r);
	return 0;
}
