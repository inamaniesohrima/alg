#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    long long total = 0;

    for (int i = 0; i < n; i++)
    {
        int expected = n - arr[i];
        int count = 0;
        for (int j = 0; j < i; j++)
        {
            if (count == expected)
            {
                break;
            }
            if (arr[i] < arr[j])
            {
                count++;
                total += (i - j);
            }
        }
    }

    printf("%lld\n", total);
    free(arr);
    return 0;
}