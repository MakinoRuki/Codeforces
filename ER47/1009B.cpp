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
#define M 52
#define N 2000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
string s;
int main() {
	cin>>s;
	n = s.size();
	int idx=-1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '2' && idx < 0) {
			idx=i;
			break;
		}
	}
	if (idx<0) {
		sort(s.begin(), s.end());
		cout<<s<<endl;
	} else {
		string t1="";
		string t2="";
		for (int i = 0; i < n; ++i) {
			if (i < idx) {
				t1.push_back(s[i]);
			} else {
				if (s[i] == '1') {
					t1.push_back(s[i]);
				} else {
					t2.push_back(s[i]);
				}
			}
		}
		sort(t1.begin(), t1.end());
		cout<<t1+t2<<endl;
	}
  return 0;
}
