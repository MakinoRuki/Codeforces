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
#define M 2002
#define N 30002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n;
int a[N];
int b[N];
int val[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i = 1;i <= n; ++i) {
			b[i]=a[i];
		}
		val[1]=b[1];
		for (int i = 2; i <= n; ++i) {
			val[i]=min(val[i-1], b[i]);
		}
		ll sum=0LL;
		bool ok1=true;
		for (int i = n-1; i>=2; --i) {
			b[i] -= sum;
			if (b[i]>b[i+1]) {
				sum += b[i]-b[i+1];
				b[i]=b[i+1];
			}
			if (val[i]<sum) {
				ok1=false;
				break;
			}
		}
		bool ok2=true;
		for (int i = 1; i <= n; ++i) {
			b[i]=a[i];
		}
		val[n]=b[n];
		for (int i = n-1; i>= 1; --i) {
			val[i]=min(val[i+1], b[i]);
		}
		sum=0LL;
		for (int i = 2; i < n; ++i) {
			b[i] -= sum;
			if (b[i]>b[i-1]) {
				sum += b[i]-b[i-1];
				b[i]=b[i-1];
			}
			if (val[i]<sum) {
				ok2=false;
				break;
			}
		}
	//	cout<<ok1<<" "<<ok2<<endl;
		if (ok1 || ok2) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
