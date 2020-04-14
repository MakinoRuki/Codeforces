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
#define N 100005
using namespace std;
typedef long long ll;
int t;
int n,a,b;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>a>>b;
		string s = "";
		for (int i = 0; i < b; ++i) {
			s.push_back('a'+i);
		}
		if (a>b) {
			for (int i = 1; i <= a-b; ++i) {
				s = "a" + s;
			}
		}
		for (int i = a+1; i <= n; ++i) {
			s.push_back(s[i-1-a]);
		}
		cout<<s<<endl;
	}
	return 0;
}
