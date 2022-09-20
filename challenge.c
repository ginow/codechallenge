#include <stdio.h>
#include <string.h>
void cutSticks(int *a, int N, int H)
{
    for (int i = 0; i < N; ++i)
    {
        a[i] = a[i] - H;
    }
}
int getMax(int *a, int N)
{
    int max = 0;
    for (int i = 0; i < N; ++i)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}
int main()
{
    int T, N, i = 0, count = 1;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        int A[N], max = 0;
        while (i < N)
        {
            scanf("%d", &A[i]);
            if (A[i] > max)
            {
                max = A[i];
            }
            i++;
        }
        int *p = A;
        max--;
        while (max != 0)
        {
            cutSticks(p, N, max);
            max = getMax(p, N);
            count++;
        }
        printf("%d", count);
    }
    return 0;
}
