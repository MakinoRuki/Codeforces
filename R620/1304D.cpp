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
int t, n;
string s;
int v1[N];
int v2[N];
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>s;
		set<int> ss;
		ss.clear();
		for (int i = 0; i <= n; ++i) {
			v1[i] = -1;
			v2[i] = -1;
		}
		for (int i = 0; i < n; ++i) {
			if (i == 0 && s[i] == '>') ss.insert(i);
			else if (i == n-1 && s[i-1] == '<') ss.insert(i);
			else if (i > 0 && i < n-1 && s[i] == '>' && s[i-1] == '<') ss.insert(i);
		}
		// for (auto v : ss) {
		// 	cout<<v<<" ";
		// }
		// cout<<endl;
		for (int i = n; i >= 1; --i) {
			int pos = *ss.begin();
			ss.erase(pos);
			v1[pos] = i;
			if (pos - 1 >= 0 && ss.find(pos-1) == ss.end()) {
				if (s[pos-1] == '<' && (pos-2 < 0 || s[pos-2] != '>' || v1[pos-2] >= 0)) {
					ss.insert(pos-1);
				}
			}
			if (pos + 1 < n && ss.find(pos+1) == ss.end()) {
				if (s[pos] == '>' && (pos+2 >= n || s[pos+1] != '<' || v1[pos+2] >= 0)) {
					ss.insert(pos+1);
				}
			}
		}
		ss.clear();
		for (int i = 0; i < n; ++i) {
			if (i == 0 && s[i] == '>') ss.insert(i);
			else if (i == n-1 && s[i-1] == '<') ss.insert(i);
			else if (i > 0 && i < n-1 && s[i] == '>' && s[i-1] == '<') ss.insert(i);
		}
		for (int i = n; i >= 1; --i) {
			int pos = *ss.rbegin();
			ss.erase(pos);
			v2[pos] = i;
			if (pos - 1 >= 0 && ss.find(pos-1) == ss.end()) {
				if (s[pos-1] == '<' && (pos-2 < 0 || s[pos-2] != '>' || v2[pos-2] >= 0)) {
					ss.insert(pos-1);
				}
			}
			if (pos + 1 < n && ss.find(pos+1) == ss.end()) {
				if (s[pos] == '>' && (pos+2 >= n || s[pos+1] != '<' || v2[pos+2] >= 0)) {
					ss.insert(pos+1);
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			cout<<v1[i];
			if (i < n-1) cout<<" ";
			else cout<<endl;
		}
		for (int i = 0; i < n; ++i) {
			cout<<v2[i];
			if (i < n-1) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
