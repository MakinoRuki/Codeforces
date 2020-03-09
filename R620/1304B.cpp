#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#define N 200005
using namespace std;
typedef long long ll;
int n, m;
vector<string> sv;
bool ispar(string& s) {
	int l = 0, r = s.size() - 1;
	while(l < r) {
		if (s[l] != s[r]) return false;
		l++;
		r--;
	}
	return true;
}
int main() {
	cin>>n>>m;
	unordered_set<string> ss;
	ss.clear();
	sv.clear();
	for (int i = 0; i < n; ++i) {
		string s;
		cin>>s;
		sv.push_back(s);
		ss.insert(s);
	}
	string ls = "";
	string rs = "";
	string ms = "";
	for (int i = 0; i < n; ++i) {
		string s = sv[i];
		ss.erase(s);
		string t = s;
		reverse(t.begin(), t.end());
		if (ss.find(t) != ss.end()) {
			ls = s + ls;
			rs = rs + t;
			ss.erase(t);
		} else {
			if (ispar(s) && ms.empty()) {
				ms = s;
			}
		}
	}
	string ans = ls+ms+rs;
	cout<<ans.size()<<endl;
	cout<<ans<<endl;
	return 0;
}
