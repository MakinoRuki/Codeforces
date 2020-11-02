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
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int a,b,f,k;
int main() {
	cin>>a>>b>>f>>k;
	bool ok=true;
	bool used=true;
	int cur=b;
	int ans=0;
	for (int i = 1; i <= k; ++i) {
		int now=i&1;
		if (now) {
			if (cur<f) {
				ok=false;
				break;
			}
			cur -= f;
			if ((i+1>k && cur>=a-f) || (i+1<=k && cur>=2*(a-f))) {
				cur -= a-f;
			} else {
				ans++;
				cur=b-(a-f);
			}
			if (cur<0) {
				ok=false;
				break;
			}
		} else {
			if (cur<a-f) {
				ok=false;
				break;
			}
			cur -= a-f;
			if ((i+1>k && cur>=f) || (i+1<=k && cur >= 2*f)) {
				cur-=f;
			} else {
				ans++;
				cur = b-f;
			}
			if (cur<0) {
				ok=false;
				break;
			}
		}
	}
	if (!ok) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
