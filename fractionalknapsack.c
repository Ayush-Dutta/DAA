#include <stdio.h>
#include <stdlib.h>

struct item {
    int weight;
    int value;
    float value_per_weight;
};

int cmp(const void *a, const void *b) {
    struct item *a1 = (struct item *)a;
    struct item *b1 = (struct item *)b;
    return (int)(b1->value_per_weight * 100) - (int)(a1->value_per_weight * 100);
}

int main() {
    int n, capacity, i;
    float max_value = 0.0;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    struct item items[n];
    printf("Enter the weights and values of each item: \n");
    for (i = 0; i < n; i++) {
        scanf("%d%d", &items[i].weight, &items[i].value);
        items[i].value_per_weight = (float) items[i].value / items[i].weight;
    }
    qsort(items, n, sizeof(struct item), cmp);
    i = 0;
    while (capacity > 0 && i < n) {
        if (items[i].weight <= capacity) {
            max_value += items[i].value;
            capacity -= items[i].weight;
        } else {
            max_value += capacity * items[i].value_per_weight;
            capacity = 0;
        }
        i++;
    }
    printf("Maximum value: %f\n", max_value);
    return 0;
}

