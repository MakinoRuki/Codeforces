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
#define N 1000005
using namespace std;
typedef long long ll;
int t, n;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		unordered_set<int> ss;
		ss.clear();
		for (int i = 1; i <= n; ++i) {
			int a;
			scanf("%d", &a);
			ss.insert(a);
		}
		cout<<ss.size()<<endl;
	}
	return 0;
}
