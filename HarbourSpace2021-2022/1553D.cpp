#pragma GCC optimize(2)
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
#include <time.h>
#define eps 1e-7
#define M 22
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int q, n, m, k;
bool check(string& s, int id, string& t) {
	int c = id%2;
	int j = id+1;
	for (int i = 1; i < t.size(); ++i) {
		while(j < s.size() && ((s[j] != t[i]) || (j%2==c))) {
			j++;
		}
		if (j < s.size()) {
			c = j%2;
			j++;
		} else {
			return false;
		}
	}
	int det = (int)s.size()-j;
	if (det%2==0) return true;
	return false;
}
int main() {
	cin>>q;
	for (int cas=1; cas<=q; ++cas) {
		string s,t;
		cin>>s>>t;
		int id1=-1,id2=-1;
		bool ok = false;
		for (int i = 0; i  < s.size(); ++i) {
			if (s[i] == t[0]) {
				if (id1 < 0) {
					id1 = i;
				} else if ((id1%2) != (i%2)) {
					id2 = i;
					break;
				}
			}
		}
		if (id1 >= 0 && check(s, id1, t)) {
			ok=true;
		} else if (id2 >= 0 && check(s, id2, t)) {
			ok=true;
		}
		if (ok) puts("YES");
		else puts("NO");
	}
  return 0;
}
