#include <iostream>
#include <string.h>
using namespace std;

void solve()
{
    int n;cin >> n;
    int *coin = new int[n];
    for (int i = 0; i < n;i++)cin >> coin[i];
    
    int target;cin >> target;
    int *d = new int[target+1];
    memset(d, 0, sizeof(int) * (target + 1));
    d[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= target; j++) {
            d[j] += d[j - coin[i]];
        }
    }
    cout << d[target] << '\n';
		
}

int main()
{
	int N;
	cin >> N;
	while (N--)solve();
}
