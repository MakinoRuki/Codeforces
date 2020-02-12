#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
int a[N];
string s, t;
int main() {
	cin>>n;
	cin>>s;
	int s1=0;
	int s2=0;
	int cnt1=0;
	int cnt2=0;
	for (int i = 0; i < n; ++i) {
		if (i < n/2) {
			if (s[i] != '?') s1 += s[i]-'0';
			else cnt1++;
		} else {
			if (s[i] != '?') s2+=s[i]-'0';
			else cnt2++;
		}
	}
	if (s1 == s2) {
		if (cnt1 == cnt2) cout<<"Bicarp"<<endl;
		else cout<<"Monocarp"<<endl;
	} else {
		if (s1 < s2) {
			swap(s1, s2);
			swap(cnt1, cnt2);
		}
		if (cnt1 >= cnt2) {
			cout<<"Monocarp"<<endl;
		} else {
			bool ok = false;
			int d1 = s1-s2;
			if (cnt1) {
				d1+=9;
				int r = cnt2-cnt1+1;
				if ((r+1)/2 * 9 < d1) {
					ok = true;
				}
			} else {
				int r = cnt2-cnt1;
				if (r/2*9 < d1) {
					ok = true;
				}
			}
			d1 = s1-s2;
			int r = cnt2-cnt1;
			if ((r+1)/2 * 9 > d1) {
				ok = true;
			}
			if (ok) cout<<"Monocarp"<<endl;
			else cout<<"Bicarp"<<endl;
		}
	}
	return 0;
}
