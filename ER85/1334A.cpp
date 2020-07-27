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
#define N 502
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		int p0 = 0, c0=0;
		bool ok = true;
		for (int i = 1; i <= n; ++i) {
			int p, c;
			scanf("%d%d",&p,&c);
			if (p-p0 < c-c0) {
				ok = false;
			}
			if (p<p0 || c<c0) {
				ok=false;
			}
			p0=p,c0=c;
		}
		if (ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
  return 0;
}
