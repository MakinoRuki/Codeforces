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
int t,n,q;
string s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &q);
		cin>>s;
		for (int i = 1; i <= q; ++i) {
			int l, r;
			scanf("%d%d", &l, &r);
			bool ok=false;
			string t=s.substr(l-1, r-l+1);
			int lm[105];
			int rm[105];
			for (int i =0 ; i <= n+1; ++i) {
				lm[i]=-1;
				rm[i]=-1;
			}
			int j = 1;
			//lm[0]=0;
			for (int i = 1; i <= n; ++i) {
				lm[i]=lm[i-1];
				if (j <= t.size() && s[i-1]==t[j-1]) {
					lm[i]=j;
					j++;
				}
				//cout<<"l="<<i<<" "<<lm[i]<<endl;
			}
			rm[n+1]=n+2;
			j = (int)t.size();
			for (int i = n; i >= 1; --i) {
				rm[i]=rm[i+1];
				if (j >= 1 && s[i-1]==t[j-1]) {
					rm[i] = j;
					j--;
				}
				//cout<<"r="<<i<<" "<<rm[i]<<endl;
			}
			for (int i = 1; i <= n; ++i) {
				if (lm[i-1] +1>=rm[i+1]) {
					ok=true;
					break;
				}
			}
			if (ok) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}
