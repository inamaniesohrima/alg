#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    int index;
} ElementStruct;

ElementStruct *elements = NULL;
ElementStruct *temp = NULL;
int array_size = 0;

void createArray(int size)
{
    array_size = size;
    elements = (ElementStruct *)malloc(size * sizeof(ElementStruct));
    temp = (ElementStruct *)malloc(size * sizeof(ElementStruct));
}

void fillArray(int input_values[])
{
    for (int i = 0; i < array_size; i++)
    {
        elements[i].value = input_values[i];
        temp[i].value = input_values[i];
        elements[i].index = i + 1; // Store 1-based index
        temp[i].index = i + 1;     // Store 1-based index
    }
}

// **Final Correct Merge Function**
long long countAndMerge(ElementStruct arr[], ElementStruct temp[], int l, int m, int r)
{
    // int n1 = m - l + 1, n2 = r - m;

    // // Allocate temporary arrays
    // ElementStruct *left = (ElementStruct *)malloc(n1 * sizeof(ElementStruct));
    // ElementStruct *right = (ElementStruct *)malloc(n2 * sizeof(ElementStruct));

    // for (int i = 0; i < n1; i++)
    //     left[i] = arr[l + i];
    // for (int j = 0; j < n2; j++)
    //     right[j] = arr[m + 1 + j];

    // long long res = 0;
    // int i = 0, j = 0, k = l;
    long long res = 0;
    int i = l, j = m + 1, k = l;

    while (i < m && j < r)
    {
        if (arr[i].value <= arr[j].value)
        {
            temp[k++] = arr[i++];
        }
        else
        {
            res += arr[j].index - arr[i].index;
            for (int x = i + 1; x < m; x++)
            {
                res += arr[j].index - arr[x].index;
            }
            temp[k++] = arr[j++];
        }
    }

    while (i < m)
        temp[k++] = arr[i++];
    while (j < r)
        temp[k++] = arr[j++];

    for (int t = l; t < r; t++)
    {
        arr[t] = temp[t];
    }

    return res;
}

// **Final Count Function**
long long countInv(ElementStruct arr[], ElementStruct temp[], int l, int r)
{
    long long res = 0;
    if (l < r)
    {
        int m = (r + l) / 2;
        res += countInv(arr, temp, l, m);
        res += countInv(arr, temp, m + 1, r);
        res += countAndMerge(arr, temp, l, m, r);
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    createArray(n);
    // int *input_values = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        elements[i].value = num;
        temp[i].value = elements[i].value;
        elements[i].index = i; // Store 1-based index
        temp[i].index = i;     // Store 1-based index
        // scanf("%d", &input_values[i]);
    }

    // fillArray(input_values);

    printf("%lld\n", countInv(elements, temp, 0, n - 1)); // Using %lld for large numbers
    free(elements);
    // free(input_values);
    return 0;
}
