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
#define N 200005
using namespace std;
typedef long long ll;
int t;
vector<string> g;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		g.clear();
		for (int i = 0; i < 9; ++i) {
			string s;
			cin>>s;
			g.push_back(s);
		}
		for (int i = 0; i < 9; ++i) {
		    int j = i/3+(i%3)*3;
			g[i][j] = g[i][(j+1)%9];
		}
		for (int i = 0; i < 9; ++i) {
			cout<<g[i]<<endl;
		}
	}
	return 0;
}
