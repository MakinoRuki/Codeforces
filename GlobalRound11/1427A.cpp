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
#define N 100
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t,n;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		vector<int> bs;
		bs.clear();
		int tot=0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			tot+=a[i];
		}
		if (tot==0) {
			cout<<"NO"<<endl;
		} else {
			sort(a+1, a+n+1);
			if (tot>0) {
				cout<<"YES"<<endl;
				for (int i = n; i >= 1; --i) {
					printf("%d", a[i]);
					if (i>1) cout<<" ";
					else cout<<endl;
				}
			} else {
				cout<<"YES"<<endl;
				for (int i = 1; i <= n; ++i) {
					printf("%d", a[i]);
					if (i<n) cout<<" ";
					else cout<<endl;
				}
			}
		}
	}
	return 0;
}
