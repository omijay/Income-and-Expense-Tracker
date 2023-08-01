#include <stdio.h>
#include <string.h>

typedef struct {
    char description[100];
    float amount;
} Transaction;
void addTransaction(Transaction *transactions, int *transactionCount, char *description, float amount) {
    Transaction newTransaction;
    strcpy(newTransaction.description, description);
    newTransaction.amount = amount;

    transactions[*transactionCount] = newTransaction;
    (*transactionCount)++;
}
float calculateTotal(Transaction *transactions, int transactionCount) {
    float total = 0.0;
    for (int i = 0; i < transactionCount; i++) {
        total += transactions[i].amount;
    }
    return total;
}
int main() {
    Transaction transactions[100];
    int transactionCount = 0;

    printf("Enter income transactions (enter '0' in description to stop):\n");
    char description[100];
    float amount;
    do {
        printf("Description: ");
        scanf(" %[^\n]s", description);
        if (strcmp(description, "0") == 0) {
            break;
        }
        printf("Amount: ");
        scanf("%f", &amount);
        addTransaction(transactions, &transactionCount, description, amount);
    } while (1);

    printf("\nEnter expense transactions (enter '0' in description to stop):\n");
    do {
        printf("Description: ");
        scanf(" %[^\n]s", description);
        if (strcmp(description, "0") == 0) {
            break;
        }
        printf("Amount: ");
        scanf("%f", &amount);
        addTransaction(transactions, &transactionCount, description, -amount);
    } while (1);

    float totalIncome = calculateTotal(transactions, transactionCount);
    float totalExpense = calculateTotal(transactions + transactionCount / 2, transactionCount / 2);
    printf("\nTotal Income: %.2f\n", totalIncome);
    printf("Total Expense: %.2f\n", totalExpense);

    float netSavings = totalIncome - totalExpense;
    printf("Net Savings: %.2f\n", netSavings);

    return 0;
}
