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
    int P, Q, stock, today, dueDate, unitsDue, startDate, demand, reorderCost;
    float total_cost;

    for (int i = 0; i < 5; i++)
    {
        printf("Input the values for P and Q:\n");
        scanf("%d %d", &P, &Q);
        startDate = 1;
        dueDate = 0;
        today = startDate;
        unitsDue = 0;
        reorderCost = 10;
        stock = 115;
        total_cost = 0;

        while (today <= 180)
        {
            if (today == dueDate)
            {
                stock += Q;
                unitsDue = 0;
            }
            demand = generate_demand();
            if (demand <= stock)
            {
                stock -= demand;
                total_cost += stock * 0.75;
            }
            else
            {
                total_cost += (demand - stock) * 18;
                stock = 0;
            }
            if (stock + unitsDue <= P)
            {
                unitsDue = Q;
                total_cost += reorderCost * unitsDue;
                dueDate = today + 3;
            }
            today++;
        }
        printf("Total Cost for P=%d and Q=%d is %f\n", P, Q, total_cost);
    }
    return 0;
}
