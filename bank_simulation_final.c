#include <stdio.h>

int main()
{

    printf("\n*********  MINI ATM SYSTEM  *********\n");

    float balance;      // Variable to store account balance
    int choice;         // Variable to store user menu choice

    // Take initial balance from user
    printf("\nEnter Initial Balance: ");
    scanf("%f", &balance);

    /* ---------------- PIN SYSTEM ---------------- */
    int pin = 1234;          // Default PIN
    int enteredPin;          // Variable to store user entered PIN
    int attempts = 0;        // Counter for number of attempts

    // Allow maximum 3 attempts
    while (attempts < 3)
    {
        printf("Enter 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == pin)
        {
            printf("Login Successful!\n");
            break;          // Exit loop if PIN is correct
        }
        else
        {
            printf("Wrong PIN!\n");
            attempts++;     // Increase attempt counter
        }
    }

    // If user enters wrong PIN 3 times
    if (attempts == 3)
    {
        printf("Too many failed attempts. Account Locked!\n");
        return 0;           // Terminate program
    }

    /* -------- Transaction Tracking Variables -------- */
    float totalDeposit = 0;        // Stores total deposited amount
    float totalWithdrawal = 0;     // Stores total withdrawn amount
    float deposit, withdraw, transfer; // Temporary variables
    int transactionCount = 0;      // Counts number of transactions
    float lastTransaction = 0;     // Stores last transaction amount

    /* ------------- MENU DRIVEN LOOP ------------- */
    do
    {
        printf("\n----------------------------------\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transfer Money\n");
        printf("5. Total Deposited\n");
        printf("6. Total Withdrawn\n");
        printf("7. Add 5%% Interest\n");
        printf("8. Last Transaction\n");
        printf("9. Exit\n");
        printf("----------------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Display current balance
            printf("Current Balance: %.2f\n", balance);
            break;

        case 2:
            // Deposit Money
            printf("Enter amount to deposit: ");
            scanf("%f", &deposit);

            if (deposit > 0)   // Validate amount
            {
                balance += deposit;              // Add to balance
                totalDeposit += deposit;         // Update total deposit
                lastTransaction = deposit;       // Store last transaction
                transactionCount++;              // Increase transaction count
                printf("Deposit Successful!\n");
            }
            else
                printf("Invalid amount!\n");
            break;

        case 3:
            // Withdraw Money
            printf("Enter amount to withdraw: ");
            scanf("%f", &withdraw);

            if (withdraw > 0 && withdraw <= balance)  // Check valid amount
            {
                balance -= withdraw;                 // Deduct from balance
                totalWithdrawal += withdraw;         // Update total withdrawal
                lastTransaction = -withdraw;         // Negative for withdrawal
                transactionCount++;                  // Increase transaction count
                printf("Withdrawal Successful!\n");
            }
            else
                printf("Invalid or Insufficient Balance!\n");
            break;

        case 4:
            // Transfer Money
            printf("Enter amount to transfer: ");
            scanf("%f", &transfer);

            if (transfer > 0 && transfer <= balance)
            {
                balance -= transfer;               // Deduct from balance
                lastTransaction = -transfer;       // Store as negative
                transactionCount++;                // Increase count
                printf("Transfer Successful!\n");
            }
            else
                printf("Invalid or Insufficient Balance!\n");
            break;

        case 5:
            // Show total deposited amount
            printf("Total Deposited: %.2f\n", totalDeposit);
            break;

        case 6:
            // Show total withdrawn amount
            printf("Total Withdrawn: %.2f\n", totalWithdrawal);
            break;

        case 7:
            // Add 5% interest to balance
            balance += balance * 0.05;
            printf("5%% Interest Added!\n");
            printf("Updated Balance: %.2f\n", balance);
            break;

        case 8:
            // Show last transaction
            if (transactionCount == 0)
                printf("No transactions yet.\n");
            else
                printf("Last Transaction Amount: %.2f\n", lastTransaction);
            break;

        case 9:
            // Exit option
            printf("\nThank You for Banking With Us!\n");
            break;

        default:
            // Handle invalid input
            printf("Invalid Choice! Select 1-9.\n");
        }

    } while (choice != 9);  // Loop until user chooses Exit

    // Display final summary
    printf("\nTotal Transactions Done: %d\n", transactionCount);
    printf("Final Balance: %.2f\n", balance);

    return 0;  
}
