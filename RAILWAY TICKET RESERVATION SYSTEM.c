#include <stdio.h>
#include <string.h>

int main()
{
    int seats[5][4];
    char names[20][50];
    int ages[20];
    int i, j,choice,row, seat,position,count,found, age;
    char name[50];
    char searchName[50];
    /* Initialize all seats as available */
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 4; j++)
        {
            seats[i][j] = 0;
        }
    }
    while(1)
    {
        printf("\n=====================================\n");
        printf("      RAILWAY RESERVATION SYSTEM\n");
        printf("=====================================\n");
        printf("\n1. Display Seat Availability\n");
        printf("2. Book a Ticket\n");
        printf("3. Cancel a Ticket\n");
        printf("4. Search Passenger\n");
        printf("5. Display Reservation Details\n");
        printf("6. Display Available Seats\n");
        printf("7. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        /* 1. Display Seat Availability */
        if(choice == 1)
        {
            printf("\n        1   2   3   4\n");
            for(i = 0; i < 5; i++)
            {
                printf("Row %d   ", i + 1);

                for(j = 0; j < 4; j++)
                {
                    if(seats[i][j] == 0)
                    {
                        printf("O   ");
                    }
                    else
                    {
                        printf("X   ");
                    }
                }

                printf("\n");
            }
            printf("\nO -> Available\n");
            printf("X -> Booked\n");
        }
        /* 2. Book a Ticket */
        else if(choice == 2)
        {
            printf("\nEnter passenger name: ");
            scanf(" %[^\n]", name);
            printf("Enter age: ");
            scanf("%d", &age);
            printf("Enter row number: ");
            scanf("%d", &row);
            printf("Enter seat number: ");
            scanf("%d", &seat);
            if(row < 1 || row > 5 || seat < 1 || seat > 4)
            {
                printf("\nInvalid row or seat number!\n");
            }
            else if(seats[row - 1][seat - 1] == 1)
            {
                printf("\nSorry! This seat is already booked.\n");
            }
            else
            {
                position = (row - 1) * 4 + (seat - 1);
                seats[row - 1][seat - 1] = 1;
                strcpy(names[position], name);
                ages[position] = age;
                printf("\n================================\n");
                printf("       TICKET BOOKED\n");
                printf("================================\n");
                printf("\nPassenger : %s\n", names[position]);
                printf("Age       : %d\n", ages[position]);
                printf("Seat      : %d-%d\n", row, seat);
                printf("\nBooking successful!\n");
            }
        }

        /* 3. Cancel a Ticket */
        else if(choice == 3)
        {
            printf("\nEnter row number: ");
            scanf("%d", &row);

            printf("Enter seat number: ");
            scanf("%d", &seat);
            if(row < 1 || row > 5 || seat < 1 || seat > 4)
            {
                printf("\nInvalid row or seat number!\n");
            }
            else if(seats[row - 1][seat - 1] == 0)
            {
                printf("\nNo booking found for this seat.\n");
            }
            else
            {
                position = (row - 1) * 4 + (seat - 1);
                seats[row - 1][seat - 1] = 0;
                names[position][0] = '\0';
                ages[position] = 0;
                printf("\nTicket cancelled successfully!\n");
                printf("Seat %d-%d is now available.\n", row, seat);
            }
        }

        /* 4. Search Passenger */
        else if(choice == 4)
        {
            printf("\nEnter passenger name: ");
            scanf(" %[^\n]", searchName);
            found = 0;
            for(i = 0; i < 20; i++)
            {
                if(strcmp(names[i], searchName) == 0)
                {
                    if(seats[i / 4][i % 4] == 1)
                    {
                        row = i / 4 + 1;
                        seat = i % 4 + 1;

                        printf("\n================================\n");
                        printf("       PASSENGER FOUND\n");
                        printf("================================\n");
                        printf("\nName : %s\n", names[i]);
                        printf("Age  : %d\n", ages[i]);
                        printf("Seat : %d-%d\n", row, seat);
                        found = 1;
                        break;
                    }
                }
            }

            if(found == 0)
            {
                printf("\nPassenger not found.\n");
            }
        }

        /* 5. Display Reservation Details */
        else if(choice == 5)
        {
            printf("\n========================================\n");
            printf("        RESERVATION DETAILS\n");
            printf("========================================\n");
            printf("\nPassenger       Age       Seat\n");
            printf("----------------------------------------\n");
            found = 0;
            for(i = 0; i < 20; i++)
            {
                if(seats[i / 4][i % 4] == 1)
                {
                    row = i / 4 + 1;
                    seat = i % 4 + 1;
                    printf("%-15s %-9d %d-%d\n",
                           names[i], ages[i], row, seat);
                    found = 1;
                }
            }
            if(found == 0)
            {
                printf("No reservations found.\n");
            }
        }

        /* 6. Display Available Seats */
        else if(choice == 6)
        {
            printf("\n================================\n");
            printf("       AVAILABLE SEATS\n");
            printf("================================\n");
            count = 0;
            for(i = 0; i < 20; i++)
            {
                if(seats[i / 4][i % 4] == 0)
                {
                    row = i / 4 + 1;
                    seat = i % 4 + 1;
                    printf("%d-%d  ", row, seat);
                    count++;
                }
            }
            printf("\n\nTotal Available Seats : %d\n", count);
        }

        /* 7. Exit */
        else if(choice == 7)
        {
            printf("\nThank you for using Railway Reservation System!\n");
            break;
        }
        else
        {
            printf("\nInvalid choice! Please enter 1 to 7.\n");
        }
    }
    return 0;
}
