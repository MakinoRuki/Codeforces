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
int t,n,k;
string a,b;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		cin>>a>>b;
		int cnt1[26];
		int cnt2[26];
		for (int i = 0; i < 26; ++i) {
			cnt1[i]=0;
			cnt2[i]=0;
		}
		for (int i = 0; i < n; ++i) {
			cnt1[a[i]-'a']++;
			cnt2[b[i]-'a']++;
		}
		int cur=0;
		bool ok = true;
		for (int i = 0 ; i < 26; ++i) {
			cur += cnt1[i];
			if (cur < cnt2[i]) {
				ok=false;
				break;
			}
			int det=cur-cnt2[i];
			if (det%k!=0) {
				ok=false;
				break;
			}
			cur -= cnt2[i];
		}
		if (cur!=0) {
			ok=false;
		}
		if (ok) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
