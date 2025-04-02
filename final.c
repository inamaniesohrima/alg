#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value, index;
} Pair;

long long Merge(Pair arr[], int left, int mid, int right, Pair temp[])
{
    int i = left, j = mid, k = 0;
    long long inv = 0;
    int nL = mid - left;

    int *suff = (int *)malloc((nL + 1) * sizeof(int));
    int s_val = 0;

    for (int p = mid - 1; p >= left; --p)
    {
        s_val += arr[p].index;
        suff[p - left] = s_val;
    }

    while (i < mid && j < right)
    {
        if (arr[i].value <= arr[j].value)
        {
            temp[k++] = arr[i++];
        }
        else
        {
            int count = mid - i;
            inv += arr[j].index * count - suff[i - left];
            temp[k++] = arr[j++];
        }
    }

    while (i < mid)
        temp[k++] = arr[i++];
    while (j < right)
        temp[k++] = arr[j++];

    for (i = left, k = 0; i < right; ++i, ++k)
    {
        arr[i] = temp[k];
    }

    free(suff);
    return inv;
}

long long MergeSort(Pair arr[], int left, int right, Pair temp[])
{
    if (right - left <= 1)
        return 0;
    int mid = (left + right) / 2;
    long long inv = MergeSort(arr, left, mid, temp);
    inv += MergeSort(arr, mid, right, temp);
    inv += Merge(arr, left, mid, right, temp);
    return inv;
}

int main()
{
    int n;
    scanf("%d", &n);
    Pair *arr = (Pair *)malloc(n * sizeof(Pair));
    Pair *temp = (Pair *)malloc(n * sizeof(Pair));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
    }

    printf("%lld\n", MergeSort(arr, 0, n, temp));

    free(arr);
    free(temp);
    return 0;
}
