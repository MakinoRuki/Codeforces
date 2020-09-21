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
#define N 200005
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
ll n;
string a,b,c;
int getres(string& s, ll m) {
	int len=s.size();
	int cnt1[26];
	int cnt2[26];
	memset(cnt1, 0, sizeof(cnt1));
	memset(cnt2, 0, sizeof(cnt2));
	for (int i = 0; i < len; ++i) {
		if (s[i]>='a' && s[i]<='z') {
			cnt1[s[i]-'a']++;
		}
	}
	for (int i = 0; i < len; ++i) {
		if (s[i]>='A' && s[i]<='Z') {
			cnt2[s[i]-'A']++;
		}
	}
	ll maxv=0;
	for (int i = 0; i < 26; ++i) {
		maxv=max(maxv, (ll)cnt1[i]);
	}
	for (int i = 0; i < 26; ++i) {
		maxv=max(maxv, (ll)cnt2[i]);
	}
	if (maxv==len) {
		if (m%2==0) return len;
		if (m==1) return len-1;
		return len;
	} else {
		return min((ll)len, maxv+m);
	}
}
int main() {
	cin>>n;
	cin>>a>>b>>c;
	if (a.size()==1) {
		cout<<"Draw"<<endl;
		return 0;
	}
	int ra=getres(a, n);
	int rb=getres(b, n);
	int rc=getres(c, n);
	if (ra > rb && ra> rc) {
		cout<<"Kuro"<<endl;
	} else if (rb > ra && rb > rc) {
		cout<<"Shiro"<<endl;
	} else if (rc > ra && rc > rb) {
		cout<<"Katie"<<endl;
	} else {
		cout<<"Draw"<<endl;
	}
	return 0;
}
