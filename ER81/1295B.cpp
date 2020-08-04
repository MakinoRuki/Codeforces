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
#define N 200005
#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
string s;
ll x;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%lld", &n, &x);
		cin>>s;
		int c0 = 0, c1 = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') c0++;
			else c1++;
		}
		int cnt=0;
		int c00=0, c11=0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') c00++;
			else c11++;
			ll det = x - (c00-c11);
			ll det2 = c0-c1;
			if (det2==0) {
				if (det==0) cnt++;
			} else if (det2>0 && det >= 0) {
				if (det%det2==0) {
					cnt++;
				}
			} else if (det2<0 && det<=0) {
				if (abs(det)%abs(det2) == 0) {
					cnt++;
				}
			}
		}
		if (c0 == c1) {
			if (cnt) cout<<-1<<endl;
			else {
				if (x==0) cout<<1<<endl;
				else cout<<0<<endl;
			}
		} else {
			if (x==0) {
				cnt++;
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}
