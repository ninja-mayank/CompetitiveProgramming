#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define input(x) for(auto &a:x)cin>>a
#define print(x) for(auto &a:x){cout<<a<<' ';}cout<<nline
#define ppcl(x) __builtin_popcountll(x)
#define ppc(x) __builtin_popcount(x)
#define all(x) x.begin(), x.end()
#define ll long long int
#define pb push_back
#define nline "\n"
#define INF LLONG_MAX
#define NINF LLONG_MIN
#define pii pair<int,int> 
#define fr first
#define sc second 
using namespace std;
using namespace __gnu_pbds;
#define precision(x) fixed << setprecision(x)
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod = 1e9 + 7;
const int N = 200001;

void ninjamayank(){
    ll n;cin >> n;
    ll first = 5*(n/5);
    ll second = 5*(n/5 + 1);
    cout << (n - first < second - n ? first : second);
}
int main(){
    // #ifndef ONLINE_JUDGE
    //     //for getting input from input1.txt
    //     freopen("input1.txt", "r", stdin);
    //     //for getting output from output1.txt
    //     freopen("output1.txt", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // remove in problems with online query
    int testcase = 1;
    // cin >> testcase;
    int gtc = 1;
    while(testcase--){
        //cout << "Case #" << gtc << ": ";
        ninjamayank();
        gtc++;
    }
}