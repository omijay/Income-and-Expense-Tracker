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
