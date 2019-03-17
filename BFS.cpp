#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define all(v)          ((v).begin()), ((v).end())
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define clr(v,d)		memset(v, d, sizeof(v))
const double EPS = 1e-8;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int>P;
const ll mod = 1000000007;
int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
const int N = 500001;
#define endl '\n'
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
void stop(){
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
struct point{
	double x, y;
};
ll gcd(ll a, ll b){ if (a < 0)a *= -1; if (b< 0)b *= -1; return !b ? a : gcd(b, a % b); }
ll fixMod(ll a, ll b){ return ((a%b) + b) % b; }
double triangle_area(int x1, int y1, int x2, int y2, int x3, int y3) {
	return abs((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)) / 2.;
};
ll dis(point a, point b) {
	ll x = a.x - b.x, y = a.y - b.y;
	return x * x + y * y;
}
double traingleArea(double a, double b, double c) {
	double s = (a + b + c) / 2.0;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}
double circleArea(double r) {
	return acos(-1) * r * r;
}
ll power(ll x, ll y)
{
	if (y == 0)return 1;
	if (y == 1)return x;
	ll r = power(x, y / 2) % mod;
	return r%mod*r%mod*power(x, y % 2) % mod;
}
vector<vector<int>>adj;
void bfs(int s){
	queue<int>q;
	q.push(s);
	vis[s] = 1;
	int dep = 0;
	while (q.size()){
		int sz = q.size();
		int cur = q.front();
		q.pop();
		while (sz--){
			for (auto ch : adj[cur]){
				if (!vis[ch]){
					q.push(ch);
					vis[ch] = 1;
				}
			}
		}
		dep++;
	}
}

int main(){
	fast
		cin >> n;
	v.resize(n);
	stop();
	
	return 0;
}