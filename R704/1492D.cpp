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
#define M 52
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int a,b,k;
int cbs(int x) {
	int cnt=0;
	while(x) {
		if (x&1) cnt++;
		x/=2;
	}
	return cnt;
}
int main() {
	cin>>a>>b>>k;
	// for (int a = 0; a <= 5; ++a) {
	// 	for (int b = 1; b <= 5; ++b) {
	// 		for (int k = 0; k <= a+b; ++k) {
	// 			cout<<a<<" "<<b<<" "<<k<<endl;



				if (b == 1) {
					if (k>0) {
						puts("No");
						//continue;
					} else {
						puts("Yes");
						string s,t;
						s.clear();
						t.clear();
						s.push_back('1');
						t.push_back('1');
						for (int i = 1; i <= a; ++i) {
							s.push_back('0');
							t.push_back('0');
						}
						cout<<s<<endl;
						cout<<t<<endl;
					}
					return 0;
				}
				if (k > a+b-2) {
					puts("No");
					return 0;
				}
				if (k <= a) {
					puts("Yes");
					string s,t;
					s.clear();
					t.clear();
					for (int i = 1; i < b; ++i) {
						s.push_back('1');
						t.push_back('1');
					}
					s.push_back('1');
					for (int i = 1; i <= a; ++i) {
						s.push_back('0');
					}
					for (int i = 1; i <= k; ++i) {
						t.push_back('0');
					}
					t.push_back('1');
					while(t.size() < s.size()) {
						t.push_back('0');
					}
					cout<<s<<endl;
					cout<<t<<endl;
				} else {
					if (a == 0) {
						puts("No");
					} else {
						string s,t;
						s.clear();
						t.clear();
						if (k < b) {
							for (int i = 1; i <= b-k; ++i) {
								s.push_back('1');
								t.push_back('1');
							}
							for (int i = 1; i <= k; ++i) {
								s.push_back('1');
							}
							for (int i = 1; i <= a; ++i) {
								s.push_back('0');
							}
							t.push_back('0');
							for (int i = 1; i <= k; ++i) {
								t.push_back('1');
							}
							while(t.size() < s.size()) {
								t.push_back('0');
							}
							puts("Yes");
							cout<<s<<endl;
							cout<<t<<endl;
						} else {
							int det = k-(b-1);
							string s,t;
							s.clear();
							t.clear();
							for (int i = 1; i <= b; ++i) {
								s.push_back('1');
							}
							while(s.size()<a+b) s.push_back('0');
							t.push_back('1');
							t.push_back('0');
							for (int i = 1; i < b-1; ++i) {
								t.push_back('1');
							}
							for (int i = 1; i <= det; ++i) {
								t.push_back('0');
							}
							t.push_back('1');
							while(t.size() < a+b) t.push_back('0');
							puts("Yes");
							cout<<s<<endl;
							cout<<t<<endl;
						}
					}
				}



	// 		}
	// 	}
	// }
	// cin>>a>>b>>k;
	// for (int i = 0; i < (1<<(a+b)); ++i) {
	// 	if (cbs(i) == b && ((1<<(a+b-1))&i)) {
	// 		for (int j = i; j < (1<<(a+b)); ++j) {
	// 			if (cbs(j) == b && ((1<<(a+b-1))&j)) {
	// 				int x = j-i;
	// 			//	cout<<i<<" "<<j<<" "<<x<<endl;
	// 				if (cbs(x) == k) {
	// 					cout<<j<<" "<<i<<endl;
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	
  return 0;
}
