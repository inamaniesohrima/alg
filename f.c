#include <stdio.h>
#include <stdlib.h>

#define MXN 300010

typedef long long ll;
typedef struct
{
    ll first, second;
} pll;

ll n, ans;
pll A[MXN], B[MXN];

ll Sum(ll x)
{
    return x * (x + 1) / 2;
}

ll SumRange(ll l, ll r)
{
    return (r - l + 1) * (l - 1) + Sum(r - l + 1);
}

void MergeSort(ll l, ll r)
{
    if (l == r)
        return;
    ll mid = (l + r) / 2;
    MergeSort(l, mid);
    MergeSort(mid + 1, r);

    ll pl = l, pr = mid + 1, sl = 0, sr = 0;
    for (ll i = l; i <= r; i++)
    {
        int fl = 0, fr = 0;
        if (pl > mid)
            fr = 1;
        else if (pr > r)
            fl = 1;
        else
        {
            if (A[pl].first < A[pr].first)
                fl = 1;
            else
                fr = 1;
        }
        if (fl)
        {
            sl += A[pl].second;
            B[i] = A[pl++];
        }
        else
        {
            ans += (mid - pl + 1) * A[pr].second - (SumRange(l, mid) - sl);
            sr += A[pr].second;
            B[i] = A[pr++];
        }
    }
    for (ll i = l; i <= r; i++)
        A[i] = B[i];
}

int main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &A[i].first);
        A[i].second = i;
    }
    MergeSort(1, n);
    printf("%lld\n", ans);
    return 0;
}
