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
int n, p;
string s;
int main() {
	cin>>n>>p;
	cin>>s;
	if (n<=p) {
		cout<<"No"<<endl;
		return 0;
	}
	bool ok=false;
	for (int i = 0; i < p; i++) {
		if (i+p>=n) {
			if (s[i]=='.') {
				s[i]='1';
			}
		} else {
			bool has0=false;
			bool has1=false;
			vector<int> pos;
			pos.clear();
			for (int j = i; j < n; j += p) {
				if (s[j] == '0') {
					has0=true;
				} else if (s[j]=='1') {
					has1=true;
				} else {
					pos.push_back(j);
				}
			}
			if (has0 && has1) {
				for (int j = 0; j < pos.size(); ++j) {
					s[pos[j]]='1';
				}
			} else if (!has0 && has1) {
				for (int j = 0; j < pos.size(); ++j) {
					s[pos[j]]='0';
					has0=true;
				}
			} else if (has0 && !has1) {
				for (int j = 0; j < pos.size(); ++j) {
					s[pos[j]]='1';
					has1=true;
				}
			} else {
				s[pos[0]]='0';
				has0=true;
				for (int j = 1; j < pos.size(); ++j) {
					s[pos[j]]='1';
					has1=true;
				}
			}
			if (has0 && has1) {
				ok=true;
			}
		}
	}
	if (ok) {
		cout<<s<<endl;
	} else {
		cout<<"No"<<endl;
	}
	return 0;
}
