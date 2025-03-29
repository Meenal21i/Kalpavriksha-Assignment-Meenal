#include <stdio.h>
#include <stdlib.h>

long long powerMod(long long base, long long powerComponent, long long MOD)
{

    if (powerComponent == 0)
    {
        return 1;
    }
    if (powerComponent == 1)
    {
        return base % MOD;
    }
    long long res = powerMod(base, powerComponent / 2, MOD);
    if (powerComponent % 2 == 0)
    {
        return (res * res) % MOD;
    }
    else
    {
        return ((res * res % MOD) * base) % MOD;
    }
}

int main()
{

    long long base, powerComponent, MOD;
    printf("Enter base: ");
    scanf("%lld", &base);
    printf("Enter power: ");
    scanf("%lld", &powerComponent);
    printf("Enter MOD value: ");
    scanf("%lld", &MOD);
    if (base < 0 || powerComponent < 0 || MOD <= 1)
    {
        printf("Invalid Input");
        return 0;
    }
    printf("%lld\n", powerMod(base, powerComponent, MOD));
    return 0;
}