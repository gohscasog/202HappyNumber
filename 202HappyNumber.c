#include <stdio.h>

int isHappy(int n)
{
    int numsSize = 0;
    int nums[100];

    int sum = 0;
    int dig = 0;

    while(sum >= 0)
    {
        for(int i = 1; i <= n || i == 1; i *= 10)
        {
            dig = (int) (n % (i * 10)) / i;
            sum += dig * dig;
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