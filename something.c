#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    int index;
} ElementStruct;

ElementStruct *elements = NULL;
int array_size = 0;

void createArray(int size)
{
    array_size = size;
    elements = (ElementStruct *)malloc(size * sizeof(ElementStruct));
}

void fillArray(int input_values[])
{
    for (int i = 0; i < array_size; i++)
    {
        elements[i].value = input_values[i];
        elements[i].index = i + 1; // Store 1-based index
    }
}

// **Final Correct Merge Function**
long long countAndMerge(ElementStruct arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;

    // Allocate temporary arrays
    ElementStruct *left = (ElementStruct *)malloc(n1 * sizeof(ElementStruct));
    ElementStruct *right = (ElementStruct *)malloc(n2 * sizeof(ElementStruct));

    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    long long res = 0;
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (left[i].value <= right[j].value)
        {
            arr[k++] = left[i++];
        }
        else
        {
            res += right[j].index - left[i].index;
            for (int x = i + 1; x < n1; x++)
            {
                res += right[j].index - left[x].index;
            }
            arr[k++] = right[j++];
        }
    }

    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    free(left);
    free(right);
    return res;
}

// **Final Count Function**
long long countInv(ElementStruct arr[], int l, int r)
{
    long long res = 0;
    if (l < r)
    {
        int m = (r + l) / 2;
        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    createArray(n);
    int *input_values = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input_values[i]);
    }
    fillArray(input_values);
    printf("%lld\n", countInv(elements, 0, n - 1)); // Using %lld for large numbers
    free(elements);
    free(input_values);
    return 0;
}
