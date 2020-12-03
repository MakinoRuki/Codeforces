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
#define N 502
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n, k;
string s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &k);
		cin>>s;
		int c0=0,c1=0;
		bool ok=true;
		for (int i = 0; i < k; ++i) {
			bool h1=false, h0=false;
			for (int j = i; j < n; j += k) {
				if (s[j]=='1') h1=true;
				else if (s[j]=='0') h0=true;
			}
			if (h1 && h0) {
				ok=false;
				break;
			} else {
				if (h1) c1++;
				else if (h0) c0++;
			}
		}
		if (!ok) {
			cout<<"NO"<<endl;
		} else {
			if (c1 <= k/2 && c0 <= k/2) {
				cout<<"YES"<<endl;
			} else {
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
