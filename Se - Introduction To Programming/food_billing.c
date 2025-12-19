#include <stdio.h>

int main()
{
    int choice, quantity;
    int total_amount = 0;
    int amount = 0;
    char more_order;

    do
    {
        // Display Menu
        printf("\n---------- MENU ----------\n");
        printf("1. Pizza  - 180 Rs/pcs\n");
        printf("2. Burger - 100 Rs/pcs\n");
        printf("3. Dosa   - 120 Rs/pcs\n");
        printf("4. Idli   - 50 Rs/pcs\n");
        printf("--------------------------\n");

        // Take user choice
        printf("Please Enter your choice: ");
        scanf("%d", &choice);

        // Conditional logic for food selection
        if (choice == 1)
        {
            printf("You have selected Pizza.\n");
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            amount = quantity * 180;
        }
        else if (choice == 2)
        {
            printf("You have selected Burger.\n");
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            amount = quantity * 100;
        }
        else if (choice == 3)
        {
            printf("You have selected Dosa.\n");
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            amount = quantity * 120;
        }
        else if (choice == 4)
        {
            printf("You have selected Idli.\n");
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            amount = quantity * 50;
        }
        else
        {
            printf("Invalid choice!\n");
            amount = 0;
        }

        // Calculate total bill
        total_amount = total_amount + amount;

        printf("Amount: %d\n", amount);
        printf("Total Amount is = %d\n", total_amount);

        // Ask for more orders
        printf("Do you want to place more orders? (y/n): ");
        scanf(" %c", &more_order);

    } while (more_order == 'y' || more_order == 'Y');

    // Final bill
    printf("\n===== FINAL BILL =====\n");
    printf("Total Amount to Pay = %d Rs\n", total_amount);
    printf("======================\n");

    return 0;
}
