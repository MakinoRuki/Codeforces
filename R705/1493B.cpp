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
int h, m;
int t;
int check2(int x) {
	if (x == 0 || x == 1 || x == 8) {
		return x;
	}
	if (x == 2) return 5;
	if (x == 5) return 2;
	return -1;
}
bool check(int h1, int m1) {
	if (h1 >= 0 && h1 < h && m1 >= 0 && m1 < m) {
		int h2=0,m2=0;
		if (check2(m1%10)>=0) {
			h2 = h2*10+check2(m1%10);
		} else {
			return false;
		}
		m1/=10;
		if (check2(m1)>=0) {
			h2 = h2*10+check2(m1);
		} else {
			return false;
		}
		if (check2(h1%10)>=0) {
			m2 = m2*10+check2(h1%10);
		} else {
			return false;
		}
		h1/=10;
		if (check2(h1)>=0) {
			m2 = m2*10 + check2(h1);
		} else {
			return false;
		}
		if (h2>=0 && h2<h && m2 >= 0 && m2 < m) {
			return true;
		}
	}
	return false;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &h, &m);
		string s;
		cin>>s;
		int h1 = (s[0]-'0')*10+s[1]-'0';
		int m1 = (s[3]-'0')*10+s[4]-'0';
		bool found=false;
		for (int d = 0; d <= (h-1)*m+m-1; ++d) {
			int cur = h1*m+m1+d;
			int th = (cur/m%h);
			int tm = cur%m;
		//	if (d == 1) cout<<"x="<<cur/m<<" "<<cur%m<<endl;
			if (check(th, tm)) {
				string h2 = to_string(th);
				string m2 = to_string(tm);
				if (h2.size() < 2) h2 = "0"+h2;
				if (m2.size() < 2) m2 = "0"+m2;
				cout<<h2+":"+m2<<endl;
				break;
			}
		}
	}
  return 0;
}
