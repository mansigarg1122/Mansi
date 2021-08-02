#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate_demand()
{
    srand(time(0));
    return rand() % 100;
}
int main()
{
    int P, Q, stock, today, dueDt, unitsLeft, startDt, demand, reorderCst;
    float total;

    for (int i = 0; i < 5; i++)
    {
        printf("Input the values for P and Q:\n");
        scanf("%d %d", &P, &Q);
        startDt = 1;
        dueDt = 0;
        today = startDt;
        unitsLeft = 0;
        reorderCst = 10;
        stock = 115;
        total = 0;

        while (today <= 180)
        {
            if (today == dueDt)
            {
                stock += Q;
                unitsLeft = 0;
            }
            demand = generate_demand();
            if (demand <= stock)
            {
                stock -= demand;
                total += stock * 0.75;
            }
            else
            {
                total += (demand - stock) * 18;
                stock = 0;
            }
            if (stock + unitsLeft <= P)
            {
                unitsLeft = Q;
                total += reorderCst * unitsLeft;
                dueDt = today + 3;
            }
            today++;
        }
        printf("Total Cost for P=%d and Q=%d is %.2f\n", P, Q, total);
    }
    return 0;
}
