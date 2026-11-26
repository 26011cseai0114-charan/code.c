#include <stdio.h>
#define max 5

int main() {
    int ids[max];
    char names[max][20];
    float prices[max];
    int quantity[max];
    int count = 0;
    int choice;
    int id;
    int pos;
    int nq;
    int ch;

    do {
        printf("===========================\n");
        printf("     product inventory system \n");
        printf("=============================\n");
        printf("1.add product\n");
        printf("2.search product \n");
        printf("3.display all products\n");
        printf("4.updtaer quantity\n");
        printf("5.exit\n");
        printf("=============================\n");
        printf("enter your choice (1-5):");

        if (scanf("%d", &choice) != 1) {
            while ((ch = getchar()) != '\n' && ch != EOF) {
            }
            if (ch == EOF) {
                break;
            }
            printf("invalid choice\n");
            continue;
        }

        switch (choice) {
            case 1:
                if (count == max) {
                    printf("inventory is full!\n");
                } else {
                    printf("enter the product id:");
                    scanf("%d", &ids[count]);
                    printf("enter the name :");
                    scanf(" %19[^\n]", names[count]);
                    printf("enter the price:");
                    scanf("%f", &prices[count]);
                    printf("enter the product quantity :");
                    scanf("%d", &quantity[count]);
                    count++;
                    printf("product addded sucessfully !\n");
                }
                break;

            case 2:
                if (count == 0) {
                    printf("\ninventoruy is empty!\n");
                } else {
                    printf("enter the product id to search:\n");
                    scanf("%d", &id);
                    pos = -1;
                    for (int i = 0; i < count; i++) {
                        if (ids[i] == id) {
                            pos = i;
                            break;
                        }
                    }
                    if (pos == -1) {
                        printf("\n product of not found\n");
                    } else {
                        printf("\n product found\n");
                        printf("----------------------\n");
                        printf("id:%d\n", ids[pos]);
                        printf("name:%s\n", names[pos]);
                        printf("price:%.2f\n", prices[pos]);
                        printf("quantity:%d\n", quantity[pos]);
                        printf("=======================\n");
                    }
                }
                break;

            case 3:
                if (count == 0) {
                    printf("inventory is empty :\n");
                } else {
                    printf("\n%-8s%-25s%-12s%s\n", "id", "name", "price", "quantities");
                    printf("=================================\n");
                    for (int i = 0; i < count; i++) {
                        printf("%-8d%-25s%-12.2f%d\n", ids[i], names[i], prices[i], quantity[i]);
                    }
                }
                break;

            case 4:
                if (count == 0) {
                    printf("inventory is empty\n");
                } else {
                    printf("enter the product id to updtae:");
                    scanf("%d", &id);
                    pos = -1;
                    for (int i = 0; i < count; i++) {
                        if (ids[i] == id) {
                            pos = i;
                            break;
                        }
                    }
                    if (pos == -1) {
                        printf("\n product not found!\n");
                    } else {
                        printf("current quntity :%d\n", quantity[pos]);
                        printf("enter new quantity: ");
                        scanf("%d", &nq);
                        quantity[pos] = nq;
                        printf("\n quantity upadted\n");
                    }
                }
                break;

            case 5:
                printf("\n exitibng the program\n");
                break;

            default:
                printf("invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
