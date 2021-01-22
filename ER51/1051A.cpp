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
#define N 150
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,k;
int t;
bool check(string& s) {
	int un = 0, ln = 0, dn = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			un++;
		} else if (s[i] >= 'a' && s[i] <= 'z') {
			ln++;
		} else {
			dn++;
		}
	}
	return un>0&&ln>0&&dn>0;
}
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		string s;
		cin>>s;
		int un = 0, ln = 0, dn = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				un++;
			} else if (s[i] >= 'a' && s[i] <= 'z') {
				ln++;
			} else {
				dn++;
			}
		}
		if (un>0 && ln>0 && dn>0) {
			cout<<s<<endl;
		} else {
			bool found=false;
			for (int i = 0; i < s.size(); ++i) {
				char c = s[i];
				s[i] = 'A';
				if (check(s)) {
					cout<<s<<endl;
					found=true;
					break;
				}
				s[i] = 'a';
				if (check(s)) {
					cout<<s<<endl;
					found=true;
					break;
				}
				s[i] = '1';
				if (check(s)) {
					cout<<s<<endl;
					found=true;
					break;
				}
				s[i] = c;
			}
			if (!found) {
				for (int i = 0; i < s.size()-1; ++i) {
					char c1=s[i];
					char c2=s[i+1];
					s[i]='A',s[i+1]='1';
					if (check(s)) {
						cout<<s<<endl;
						break;
					}
					s[i]='a',s[i+1]='1';
					if (check(s)) {
						cout<<s<<endl;
						break;
					}
					s[i]='A',s[i+1]='a';
					if (check(s)) {
						cout<<s<<endl;
						break;
					}
					s[i]=c1,s[i+1]=c2;
				}
			}
		}
	}
	return 0;
}
