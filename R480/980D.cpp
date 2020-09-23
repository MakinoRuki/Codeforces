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
#define M 20005
#define N 5002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
int a[N];
int ans[N];
bool prime[M];
bool b[SZ];
int main() {
	vector<int> ps;
	ps.clear();
	memset(prime, true, sizeof(prime));
	for (int i = 2; i <= 20000; ++i) {
		if (prime[i]) {
			ps.push_back(i);
			for (int j = i*i; j <= 20000; j += i) {
				prime[j]=false;
			}
		}
	}
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (a[i]==0) continue;
		int sign=1;
		if (a[i]<0) sign=-1;
		a[i]=abs(a[i]);
		for (int j = 0; j < ps.size(); ++j) {
			int p = ps[j]*ps[j];
			while(a[i]%p==0) {
				a[i]/=p;
			}
		}
		a[i]*=sign;
	}
	for (int i = 0; i <= 200000000; i++) {
		b[i]=false;
	}
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= n; ++i) {
	//	cout<<"i="<<i<<" "<<a[i]<<endl;
		int cnt=0;
		for (int j = i; j <= n; ++j) {
			int num=a[j]+100000000;
			if (!b[num]) {
				cnt++;
				b[num]=true;
			}
			if (b[100000000]) {
				if (cnt==1) ans[cnt]++;
				else ans[cnt-1]++;
			} else {
				ans[cnt]++;
			}
		}
		for (int j = i; j <= n; ++j) {
			int num=a[j]+100000000;
			b[num]=false;
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d", ans[i]);
		if (i < n) {
			cout<<" ";
 		} else {
 			cout<<endl;
 		}
	}
	return 0;
}
