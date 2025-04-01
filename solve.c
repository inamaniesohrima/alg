#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int s;
    int *c;
    int *sm;
} FT;

FT *makeFT(int sz)
{
    FT *t = (FT *)malloc(sizeof(FT));
    t->s = sz;
    t->c = (int *)calloc(sz + 5, sizeof(int));
    t->sm = (int *)calloc(sz + 5, sizeof(int));
    return t;
}

void upd(FT *t, int x, int idx)
{
    while (x <= t->s)
    {
        t->c[x]++;
        t->sm[x] += idx;
        x += x & -x;
    }
}

void qry(FT *t, int x, int *cnt, int *sm)
{
    *cnt = 0;
    *sm = 0;
    while (x > 0)
    {
        *cnt += t->c[x];
        *sm += t->sm[x];
        x -= x & -x;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    FT *tree = makeFT(n);
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        int ix = n - x + 1;
        int cnt, sm;
        qry(tree, ix - 1, &cnt, &sm);
        ans += (long long)cnt * (i + 1) - sm;
        upd(tree, ix, i + 1);
    }

    printf("%lld\n", ans);

    free(tree->c);
    free(tree->sm);
    free(tree);
    free(arr);

    return 0;
}