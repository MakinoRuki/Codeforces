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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int q;
string s;
bool check(string& s1, string& s2) {
	if (s1.size()>s2.size()) return true;
	if (s1.size()==s2.size() && s1>s2) return true;
	return false;
}
int main() {
	cin>>q;
	for (int cas=1; cas<=q; ++cas) {
		scanf("%d", &n);
		cin>>s;
		if (s.size()>2) {
			cout<<"YES"<<endl;
			cout<<2<<endl;
			cout<<s.substr(0,1)<<" "<<s.substr(1)<<endl;
		} else {
			if (s[1]>s[0]) {
				cout<<"YES"<<endl;
				cout<<2<<endl;
				cout<<s.substr(0,1)<<" "<<s.substr(1)<<endl;
			} else {
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
