#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <assert.h>
 
using namespace std;
 
#define endl '\n'
#define MOD 1000000007ULL
#define INF 1000000000
#define eps 1e-8
#define ll long long
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(X) cerr << " --> " << #X << " = " << X << endl
#define sd(x) scanf("%d",&(x))
#define slld(x) scanf("%lld",&(x))
#define pd(x) printf("%d\n",(x))
#define plld(x) printf("%lld\n",(x))
#define gcd __gcd
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
 
typedef vector< vector<int> > vvi;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int N, M;   // Number of vertices and edges
vector<pair<pii,int> > al;  // List of all the edges
int dst[100005];    // Storing minimum distance to all vertices

void shortestPath(int source)
{
    for (int i = 0; i < N; i++)
        dst[i] = INF;
    dst[source] = 0;
 
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int u = al[j].F.F;
            int v = al[j].F.S;
            int cost = al[j].S;
            if (dst[u] != INF && dst[u] + cost < dst[v])
                dst[v] = dst[u] + cost;
        }
    }

    for (int i = 0; i < M; i++) {
        int u = al[i].F.F;
        int v = al[i].F.S;
        int cost = al[i].S;
        if (dst[u] != INF && dst[u] + cost < dst[v])
            cout << "Graph contains negative cycle" << endl;
    }
 
    cout << "Minimum distances:" << endl;
    for (int i = 0; i < N; ++i)
        cout << i << ": " << dst[i] << endl;
}

int main()
{
    N = 5;
    M = 8;
 
    al.pb(mp(mp(0,1),-1));
    al.pb(mp(mp(0,2),4));
    al.pb(mp(mp(1,2),3));
    al.pb(mp(mp(1,3),2));
    al.pb(mp(mp(1,4),2));
    al.pb(mp(mp(3,2),5));
    al.pb(mp(mp(3,1),1));
    al.pb(mp(mp(4,3),-3));
 
    shortestPath(0);
 
    return 0;
}
