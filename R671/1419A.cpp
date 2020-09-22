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
#define N 200
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int t;
string s;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>s;
		if (n%2==0) {
			bool found=false;
			for (int i = 1; i < n; i += 2) {
				int d=s[i]-'0';
				if (d%2==0) {
					found=true;
				}
			}
			if (found) {
				cout<<2<<endl;
			} else {
				cout<<1<<endl;
			}
		} else {
			bool found=false;
			for (int i = 0; i < n; i += 2) {
				int d=s[i]-'0';
				if (d%2) {
					found=true;
				}
			}
			if (found) {
				cout<<1<<endl;
			} else {
				cout<<2<<endl;
			}
		}
	}
	return 0;
}
