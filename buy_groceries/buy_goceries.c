#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int buyGroceries(int* stuff, int size) {
    if (stuff == NULL || size <= 0) {
        return 0;
    }

    float totalCost = 0;
    for (int i = 0; i < size; i += 2) {
        int itemNumber = stuff[i];
        int quantity = stuff[i + 1];

        if (itemNumber < 1 || itemNumber > 4 || quantity <= 0) {
            return 0;
        }

        float itemCost = 0;
        switch (itemNumber) {
            case 1:
                itemCost = 3.50;
                break;
            case 2:
                itemCost = 2.25;
                break;
            case 3:
                itemCost = 1.99;
                break;
            case 4:
                itemCost = 4.15;
                break;
        }

        if (quantity >= 5) {
            itemCost = itemCost * 0.95;
        }

        totalCost += itemCost * quantity;
    }

    return round(totalCost);
}

int main(void)
{
    int cart[] = {1, 6, 2, 7, 3, 8, 4, 15};
    int cost = buyGroceries(cart, 8);
    
    printf("%d",cost);
    return 0;
}