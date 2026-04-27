#include <stdio.h>

int main() {
    int n, i, j;
    float capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    float weight[n], profit[n], ratio[n], temp;

    // Input weights and profits
    for(i = 0; i < n; i++) {
        printf("Enter weight and profit of item %d: ", i+1);
        scanf("%f %f", &weight[i], &profit[i]);
        ratio[i] = profit[i] / weight[i]; // profit-to-weight ratio
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    // Sort items by ratio in descending order (Greedy step)
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(ratio[i] < ratio[j]) {
                // Swap ratio
                temp = ratio[i]; ratio[i] = ratio[j]; ratio[j] = temp;
                // Swap profit
                temp = profit[i]; profit[i] = profit[j]; profit[j] = temp;
                // Swap weight
                temp = weight[i]; weight[i] = weight[j]; weight[j] = temp;
            }
        }
    }

    float totalProfit = 0.0;
    for(i = 0; i < n; i++) {
        if(weight[i] <= capacity) {
            capacity -= weight[i];
            totalProfit += profit[i];
        } else {
            totalProfit += profit[i] * (capacity / weight[i]);
            break;
        }
    }

    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}
