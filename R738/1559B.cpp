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
int t, n, m, k;
int a[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		string s;
		cin>>s;
		int id = -1;
		for (int i = 0; i < n; ++i) {
			if (s[i] != '?') {
				id = i;
				break;
			}
		}
		if (id < 0) {
			for (int i = 0; i < n; ++i) {
				if (i == 0) s[i] = 'B';
				else s[i] = (s[i-1] == 'B' ? 'R' : 'B');
			}
			cout<<s<<endl;
			continue;
		}
		for (int i = id-1; i >= 0; --i) {
			if (s[i+1] == 'R') s[i] = 'B';
			else s[i] = 'R';
		}
		id = -1;
		for (int i = n-1; i >= 0; --i) {
			if (s[i] != '?') {
				id = i;
				break;
			}
		}
		for (int i = id+1; i < n; ++i) {
			s[i] = (s[i-1] == 'B' ? 'R' : 'B');
		}
		for (int i = 1; i < n; ++i) {
			if (s[i] == '?') {
				s[i] = (s[i-1] == 'R' ? 'B' : 'R');
			}
		}
		cout<<s<<endl;
	}
  return 0;
}
