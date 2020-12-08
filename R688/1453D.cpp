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
#define N 2005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		ll k;
		scanf("%lld", &k);
		if (k%2) {
			cout<<-1<<endl;
		} else {
			vector<int> ds;
			ds.clear();
			int tot=0;
			while(k) {
				int pw=1;
				while((1LL<<(pw+1))-2 <= k) {
					pw++;
				}
				pw--;
				tot += pw;
				ds.push_back(pw);
				k -= (1LL<<(pw+1))-2;
			}
			printf("%d\n", tot);
			for (int i = 0; i < ds.size(); ++i) {
				int d=ds[i];
				for (int j = 1; j <= d; ++j) {
					if (j==1) printf("%d", 1);
					else printf("%d", 0);
					tot--;
					if (tot>0) cout<<" ";
					else cout<<endl;
				}
			}
		}
	}
	return 0;
}
