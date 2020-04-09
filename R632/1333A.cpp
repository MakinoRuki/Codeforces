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
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n, m;
int t;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>m;
		for (int i = 0; i < n-1; ++i) {
			for (int j = 0; j <m; ++j) {
				cout<<'B';
			}
			cout<<endl;
		}
		cout<<'B';
		for (int j = 1; j < m; ++j) {
			cout<<'W';
		}
		cout<<endl;
	}
	return 0;
}
