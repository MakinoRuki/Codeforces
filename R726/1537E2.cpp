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
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int k;
int q;
string s;
int nxt[N];
bool check(string x, string y) {
	int len = (int)x.size();
	for (int i = 0; i < y.size(); ++i) {
		if (x[i%len] < y[i]) {
			return true;
		}
	}
	return false;
}
int main() {
	cin>>n>>k;
	cin>>s;
	string ss = s;
	while(s.size() < k) {
		s += s;
	}
	while(s.size() > k) {
		s.pop_back();
	}
	memset(nxt, -1, sizeof(nxt));
	int id = k+1;
	for (int i = 1; i < k; ++i) {
		int j = nxt[i-1];
		while(j >= 0 && s[j+1] != s[i]) {
			if (j + 1 != i && s[j+1] < s[i]) {
				id = min(id, i-j-1);
			}
			j = nxt[j];
		}
		if (s[j+1] == s[i]) {
			nxt[i] = j+1;
		}
	}
	int i;
	for (i = 1; i < n; ++i) {
		if (s[0] < s[i]) {
			break;
		}
	}
	id = min(id, i);
	while(ss.size() > id) {
		ss.pop_back();
	}
	while(ss.size() < k) {
		ss += ss;
	}
	while(ss.size() > k) {
		ss.pop_back();
	}
	cout<<ss<<endl;
  return 0;
}
