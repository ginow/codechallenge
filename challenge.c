#include <stdio.h>
#include <string.h>
int main()
{
    // Read the number of test cases.
    int T, K, N;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &N, &K);
        if (K == 0)
        {
            if (N % 4 == 0)
                printf("Off\n");
            else
                printf("On\n");
        }
        else
        {
            if (N % 4 == 0)
                printf("On\n");
            else
                printf("Ambiguous\n");
        }
    }
    return 0;
}
