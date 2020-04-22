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
#include <queue>
#define N 5002
using namespace std;
typedef long long ll;
string s, t;
int n;
string getss(string& x) {
	int len=x.size();
	if (len%2) return x;
	string p1 = x.substr(0, len/2);
	string p2 = x.substr(len/2, len/2);
	auto s1 = getss(p1);
	auto s2 = getss(p2);
	if (s1<s2) return s1+s2;
	return s2+s1;
}
int main() {
	cin>>s>>t;
	n = s.size();
	auto s1 = getss(s);
	auto s2 = getss(t);
	if (s1==s2) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
