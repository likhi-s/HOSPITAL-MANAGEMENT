#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bill.h"
#define USER_ID "Bill_user"
#define USER_PASSWORD "bill@123"

int verify_billing_user()
{
    char user_id[15];
    char user_pass[15];
    int option;
    int choice;
    struct bill *bills = NULL;
    int total_bills = load_bill_data(&bills);
    printf("user ID:\n");
    scanf(" %[^\n]",user_id);
    printf("User password:\n");
    scanf(" %[^\n]",user_pass);

    if (strcmp(user_id, USER_ID) == 0 && strcmp(user_pass, USER_PASSWORD) == 0)
    {
        while(1)
        {
            printf("enter the option:\n");
            printf("1.Add bill\n2.Update bill\n3.Display bill\n4.Search by ID\n5.Save Data and exit\n");
            scanf("%d",&option);
            switch(option)
            {
            case 1:
                bills = realloc(bills, (total_bills +1)*sizeof (struct bill));
                if(bills == NULL)
                {
                    printf("memory allocation failed\n");
                    return 3;
                }
                add_bill(&bills[total_bills++]);
                break;
            case 2:
                if(total_bills >0)
                {
                    int bill_id;
                    printf("Enter bill ID to update:");
                    scanf("%d",&bill_id);
                    int bill_found =0;
                    for(int bill_index = 0; bill_index < total_bills; bill_index++)
                    {
                        if(bills[bill_index].bill_id == bill_id);
                        {
                            update_bill_details(&bills[bill_index]);
                            bill_found=1;
                            break;
                        }
                    }
                    if(!bill_found)
                    {
                        printf("bill id not found.\n");
                    }
                }
                else
                {
                    printf("No bills found.\n");
                }
                break;
            case 3:
                display_bill_details(bills,total_bills);
                break;
            case 4:
                search_bill_by_patient_id(bills,total_bills);
                break;
            case 5:
                save_bill_data(bills,total_bills);
                printf("Saved bill Data and exiting\n");
                free(bills);
                return 0;
            default:
                printf("Invalid option\n");
                break;
            }
        }
    }
    else
    {
        printf("invalid user id or password,select choice:\n");
        printf("1.forgot password.\n2.view bill\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("contact HR Manager for changes\n");
        }
        else if (choice==2)
        {
            printf("invalid credentials.You can just view bill.\n");
            display_bill_details(bills,total_bills);
        }
        else
        {
            printf("invalid choice\n");
        }
    }
    return 1;
}

void add_bill(struct bill *b)
{
    printf("Enter Bill ID:\n");
    scanf("%d",&b->bill_id);
    printf("Enter Patient ID:\n");
    scanf("%d",&b->patient_id);
    printf("Enter Treatment ID:\n");
    scanf("%d",&b->treatment_id);
    printf("Enter Consultation Fee:\n");
    scanf("%f",&b->consultation_fee);
    printf("Enter Pharmacy Fee:\n");
    scanf("%f",&b->pharmacy_fee);
    printf("Enter Room Fee:\n");
    scanf("%f",&b->room_fee);
    printf("Enter Bill Date(DD/MM/YYYY):\n");
    scanf(" %[^\n]",b->bill_date);
    calculate_bill(b);
    printf("Bill added Successfully\n");
}


void update_bill_details(struct bill *b)
{
    int choice;
    printf("which details you want to update?\n");
    printf("1.Bill ID\n2.Patient ID\n3.Treatment ID\n4.consultation fee\n5.pharmacy fee\n6.room fee\n7.Bill date\n");
    printf("Enter Choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("Enter New Bill ID:\n");
        scanf("%d",&b->bill_id);
        break;
    case 2:
        printf("Enter New Patient ID:\n");
        scanf("%d",&b->patient_id);
        break;
    case 3:
        printf("Enter New Treatment ID:\n");
        scanf("%d",&b->treatment_id);
        break;
    case 4:
        printf("Enter New Consulation fee:\n");
        scanf("%f",&b->consultation_fee);
        break;
    case 5:
        printf("Enter New Pharmacy Fee:\n");
        scanf("%f",&b->pharmacy_fee);
        break;
    case 6:
        printf("Enter new Room fee:\n");
        scanf("%f",&b->room_fee);
        break;
    case 7:
        printf("Enter new Bill Date:\n");
        scanf(" %[^\n]",b->bill_date);
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
    calculate_bill(b);
    printf("Updated bill Successfully\n");
}

void display_bill_details(struct bill *bills,int total_bills)
{
    if(total_bills ==0)
    {
        printf("no bills Available\n");
    }
    else
    {
        for(int bill_index =0; bill_index < total_bills;bill_index++)
        {
            printf("Bill Id:%d\n", bills[bill_index].bill_id);
            printf("Patient ID:%d\n",bills[bill_index].patient_id);
            printf("Treatment Id:%d\n",bills[bill_index].treatment_id);
            printf("Consultation Fee:%f\n",bills[bill_index].consultation_fee);
            printf("Pharmacy fee:%f\n",bills[bill_index].pharmacy_fee);
            printf("Room Fee:%f\n",bills[bill_index].room_fee);
            printf("Total Bill Amount:%f\n",bills[bill_index].total_bill_amount);
            printf("Bill date:%s\n",bills[bill_index].bill_date);
            printf("\n");
        }
    }
}



void search_bill_by_patient_id(struct bill *bills, int total_bills)
{
    int search_id;
    printf("Enter Patient Id to search:");
    scanf("%d",&search_id);
    int bill_found =0;
    for(int bill_index =0; bill_index > total_bills;bill_index++)
    {
        if(bills[bill_index].patient_id == search_id)
        {
            printf("bill with Patient Id %d found and details are as follows\n",search_id);
            printf("Bill Id:%d\n", bills[bill_index].bill_id);
            printf("Patient ID:%d\n",bills[bill_index].patient_id);
            printf("Treatment Id:%d\n",bills[bill_index].treatment_id);
            printf("Consultation Fee:%f\n",bills[bill_index].consultation_fee);
            printf("Pharmacy fee:%f\n",bills[bill_index].pharmacy_fee);
            printf("Room Fee:%f\n",bills[bill_index].room_fee);
            printf("Total Bill Amount:%f\n",bills[bill_index].total_bill_amount);
            printf("Bill date:%s\n",bills[bill_index].bill_date);
            bill_found = 1;

        }
    }
    if(!bill_found)
    {
        printf("No bill found with patient iD %d\n",search_id);
    }
}
void calculate_bill(struct bill *b)
{
    b->total_bill_amount = b->consultation_fee + b->pharmacy_fee + b->room_fee;
}

void save_bill_data(struct bill *bills,int total_bills)
{
    FILE *file;
    file = fopen("Bill_data.txt","wb");
    if(file == NULL)
    {
        printf("error in opening bill data file\n");
    }
    fwrite(&total_bills,sizeof(int),1,file);
    fwrite(bills,sizeof(struct bill),total_bills,file);
    fclose(file);
    printf("Bill Data saved Succeddfully\n");
}


int load_bill_data(struct bill **bills)
{
    FILE *file;
    file = fopen("Bill_data.txt","rb");
    if(file == NULL)
    {
        printf("No bill data exits\n");
    }
    int total_bills;
    fread(&total_bills,sizeof(int),1,file);
    *bills = malloc (total_bills * sizeof(struct bill));
    if (*bills == NULL)
    {
        printf("Memory allocation failed\n");
        fclose(file);
        return 0;
    }
    fread(*bills,sizeof(struct bill),total_bills,file);
    fclose(file);
    printf("Bill data loaded Succeddfully %d bills found\n",total_bills);
    return total_bills;
}
