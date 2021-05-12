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
#define M 25
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		string s;
		cin>>s;
		n = s.size();
		bool ok = false;
		for (int i = 0; i <= n; ++i) {
			int j;
			int j2=-1;
			int n1=0,n2=0;
			for (j = i; j >= 1; --j) {
				if (s[j-1] == '1') {
					if (j2 >= 0 && j+1>=j2) {
						break;
					}
					j2=j;
					n1++;
				}
			}
			if (j >= 1) continue;
			j2 = -1;
			for (j = i+1; j <=n; ++j) {
				if (s[j-1] == '0') {
					if (j2>=0 && j-1<=j2) {
						break;
					}
					j2=j;
					n2++;
				}
			}
			if (j<=n) continue;
			ok=true;
			break;
		}
		if (ok) puts("YES");
		else puts("NO");
	}
  return 0;
}
