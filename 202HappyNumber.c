#include <stdio.h>

int isHappy(int n)
{
    int numsSize = 0;
    int nums[100];

    int sum = 0;
    long long dig;

    while(sum >= 0)
    {
        for(long long i = 1LL; i <= n || i == 1LL; i *= 10LL)
        {
            dig = (long long) (n % (i * 10LL)) / i;
            sum += (int) dig * dig;
        }

        if(sum == 1)
        {
            return 1;
        }

        if(numsSize > 0)
        {
            for(int i = 0; i < numsSize; i++)
            {
                if(nums[i] == sum)
                {
                    return 0;
                }
            }
        }

        nums[numsSize] = sum;
        numsSize++;

        n = sum;
        sum = 0;
    }

    return 0;
}

int main()
{
    printf("%d\n", isHappy(1999999999));
    printf("%d\n", isHappy(19));
    printf("%d\n", isHappy(2));
    printf("%d\n", isHappy(69));

    return 0;
}