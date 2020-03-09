#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#define N 200005
using namespace std;
typedef long long ll;
int t;
int a,b,c;
unordered_map<int, vector<int>> ds;
int main() {
	for (int i = 1; i <= 2*10000; ++i) {
		for (int j = 1; j * j <= i; ++j) {
			if (i%j==0){
				ds[i].push_back(j);
				if (i/j != j) {
					ds[i].push_back(i/j);
				}
			}
		}
		sort(ds[i].begin(), ds[i].end());
	}
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>a>>b>>c;
		int ans = 1000000000;
		int A1=a, B1=b, C1=c;
		for (int B = 1; B <= 2*10000; ++B) {
			for (int i = 0; i < ds[B].size(); ++i) {
				int A = ds[B][i];
				int C;
				if (c < B) C = B;
				else {
					int r1 = c/B*B;
					int r2 = (c/B+1)*B;
					if (abs(r1-c) < abs(r2-c)) C = r1;
					else C = r2;
				}
				if (abs(a-A)+abs(b-B)+abs(c-C) < ans) {
					ans = abs(a-A)+abs(b-B)+abs(c-C);
					A1=A;
					B1=B;
					C1=C;
				}
			}
		}
		cout<<ans<<endl;
		cout<<A1<<" "<<B1<<" "<<C1<<endl;
	}
	return 0;
}
