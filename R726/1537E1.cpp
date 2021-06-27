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
int t, n, m;
int k;
int q;
string s;
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
	int i;
	string tmp = s;
	while(s.size() < k) {
		s += s;
	}
	while(s.size() > k) {
		s.pop_back();
	}
	for (i = 1; i < n; ++i) {
		string t = s.substr(0, i);
		while(t.size() < k) {
			t += t;
		}
		while(t.size() > k) {
			t.pop_back();
		}
		if (t < s) {
			break;
		}
		// if (check(s, s.substr(i))) {
		// 	break;
		// }
	}
//	cout<<i<<endl;
	while(s.size() > i) {
		s.pop_back();
	}
	while(s.size() < k) {
		s += s;
	}
	while(s.size() > k) {
		s.pop_back();
	}
	// while(s.size() < k) {
	// 	int i = 1;
	// 	for (i = 1; i < s.size(); ++i) {
	// 		if (s[0] < s[i]) {
	// 			break;
	// 		}
	// 	}
	// 	while(s.size() > i) {
	// 		s.pop_back();
	// 	}
	// 	s = s+s;
	// }
	// while(s.size() > k) {
	// 	s.pop_back();
	// }
	cout<<s<<endl;
  return 0;
}
