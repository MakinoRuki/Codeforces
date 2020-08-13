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
#define N 100005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
//const ll mod2 = 999999937LL;
int t, r,g,b,w;
bool check(int rn, int gn, int bn, int wn) {
	int cnt=0;
	if (rn%2) cnt++;
	if (gn%2) cnt++;
	if (bn%2) cnt++;
	if (wn%2) cnt++;
	if (cnt <= 1) return true;
	return false;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d%d%d", &r,&g,&b,&w);
		bool ok = check(r,g,b,w);
		if (r>=1&&g>=1&&b>=1) {
			ok |= check(r-1,g-1,b-1,w+3);
		}
		if (r>=2&&g>=2&&b>=2) {
			ok |= check(r-2,g-2,b-2,w+6);
		}
		int v = min(min(r,g),b);
		ok |= check(r-v,g-v,b-v,w+3*v);
		if (ok) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
