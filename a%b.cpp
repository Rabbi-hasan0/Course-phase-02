#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;//cin >> t;
    while(t--){
        string a;int b;
        cin >> a >> b;

        int ans = 0;
        for(int i = 0; i < a.size(); i++){
            ans = (ans * 10 + a[i] - '0') % b;
        }
        cout << ans << '\n';
    }
    return 0;
}
