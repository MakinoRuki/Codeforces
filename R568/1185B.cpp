#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#define N 3005
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n;
string s, t;
int main() {
	cin>>n;
	for (int i = 1; i <= n; ++i) {
		cin>>s>>t;
		int k = 0;
		int j;
		for (j = 0; j < s.size(); ++j) {
			if (t[k] == s[j]) k++;
			else {
				if (j == 0) break;
				while(k < t.size() && t[k] == s[j-1]) k++;
				if (k < t.size() && t[k] == s[j]) k++;
				else break;
			}
		}
		if (j < s.size()) {
			cout<<"NO"<<endl;
		} else {
			while(k < t.size() && t[k] == s.back()) {
				k++;
			}
			if (k >= t.size()) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}
