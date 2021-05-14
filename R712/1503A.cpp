#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <deque>
#include <cmath>
#include <time.h>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int inf = 1000000000;
int t,n;
string s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d", &n);
		string s = "";
		cin>>s;
		int cnt0=0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') cnt0++;
		}
		int cnt1 = n- cnt0;
		if (s[0] != '1' || s.back() != '1' || (cnt0%2)) {
			puts("NO");
		} else {
			string a = "";
			string b = "";
			int c1=0,c0=0;
			for (int i = 0; i < n; ++i) {
				if (s[i] == '1') {
					c1++;
					if (c1 <= cnt1/2) {
						a.push_back('(');
						b.push_back('(');
					} else {
						a.push_back(')');
						b.push_back(')');
					}
				} else {
					c0++;
					if (c0 % 2) {
						a.push_back(')');
						b.push_back('(');
					} else {
						a.push_back('(');
						b.push_back(')');
					}
				}
			}
			puts("YES");
			cout<<a<<endl;
			cout<<b<<endl;
		}
	}
	return 0;
}
