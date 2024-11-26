#include"staff.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define USER_ID "Staff_user"
#define USER_PASSWORD "staff@123"

int verify_staff_user()
{
    char user_id[15];
    char user_pass[15];
    int option;
    int choice;
    struct staff *Staff = NULL;
    int total_staff = load_staff_data (&Staff);
    printf("user ID:\n");
    scanf(" %[^\n]",user_id);
    printf("User password:\n");
    scanf(" %[^\n]",user_pass);

    if (strcmp(user_id, USER_ID) == 0 && strcmp(user_pass, USER_PASSWORD) == 0)
    {
        while(1)
        {
            printf("enter the option:\n");
            printf("1. Add staff\n2. Update staff\n3. Display staff\n4. Search by ID\n5. Search by role\n6. Save data and Exit\n");
            scanf("%d", &option);
            switch(option)
            {
            case 1:
                Staff = realloc(Staff, (total_staff+1) * sizeof(struct staff));
                if(Staff == NULL)
                {
                    printf("Memory Allocation failed\n");
                    return 1;
                }
                add_staff(&Staff[total_staff++]);

                break;
            case 2:
                if(total_staff > 0)
                {
                    int staff_id;
                    printf("enter the staff id to update:");
                    scanf("%d",&staff_id);
                    int staff_found = 0;
                    for(int staff_index = 0; staff_index < total_staff; staff_index++)
                    {
                        if(Staff[staff_index].staff_id== staff_id)
                        {
                            update_staff_details(&Staff[staff_index]);
                            staff_found = 1;
                            break;
                        }
                    }
                    if(!staff_found)
                    {
                        printf("staff id not found.\n");
                    }

                }
                else
                {
                    printf("No staff Available.\n");
                }
                break;
            case 3:
                display_staff_details(Staff,total_staff);
                break;
            case 4:
                search_by_staff_id(Staff,total_staff);
                break;
            case 5:
                search_by_staff_role(Staff,total_staff);
                break;
            case 6:
                save_staff_data(Staff,total_staff);
                printf("saved staff data and exiting\n");
                free(Staff);
                return 0;
                break;
            default:
                printf("invalid option\n");
                break;
            }
        }
    }
    else
    {
        printf("invalid user id or password,select choice:\n");
        printf("1.forgot password.\n2.view staff\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("contact HR Manager for changes\n");
        }
        else if (choice==2)
        {
            printf("invalid credentials.You can just view Staff.\n");
            display_staff_details(Staff,total_staff);
        }
        else
        {
            printf("invalid choice\n");
        }
    }
    return 1;
}

void add_staff(struct staff *s)
{
    printf("Enter Staff ID:\n");
    scanf("%d",&s->staff_id);
    printf("Enter Staff Name:\n");
    scanf(" %[^\n]",s->staff_name);
    printf("Enter Staff role:\n");
    scanf(" %[^\n]",s->staff_role);
    printf("Enter staff Shift:\n");
    scanf(" %[^\n]",s->staff_shift);
    printf("Enter Staff Salary:\n");
    scanf("%f",&s->staff_salary);
    printf("Enter staff contact number:\n");
    scanf(" %[^\n]",s->staff_contact_number);
    printf("staff added successfully\n");

}
void update_staff_details(struct staff *s)
{
    int choice;
    printf("which details you want to update?\n");
    printf("1.ID\n2.Name\n3.role\n4.shift\n5.Salary\n6.Contact number\n");
    printf("Enter choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("Enter new Staff ID:\n");
        scanf("%d",&s->staff_id);
        break;
    case 2:
        printf("Enter new Staff name:\n");
        scanf(" %[^\n]",s->staff_name);
        break;
    case 3:
        printf("Enter new Staff role:\n");
        scanf(" %[^\n]",s->staff_role);
        break;
    case 4:
        printf("Enter new Staff Shift:\n");
        scanf(" %[^\n]",s->staff_shift);
        break;
    case 5:
        printf("enter new Staff Salary:\n");
        scanf("%f",&s->staff_salary);
        break;
    case 6:
        printf("Enter new staff Contact Number:\n");
        scanf(" %[^\n]",s->staff_contact_number);
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
    printf("Required Staff Details Updated\n");
}

void display_staff_details(struct staff *Staff,int total_staff)
{
    if(total_staff ==0)
    {
        printf("No Staff Available\n");
    }
    else
    {
        for(int staff_index = 0; staff_index < total_staff; staff_index++)
        {
            printf("Staff ID:%d\n",Staff[staff_index].staff_id);
            printf("Staff Name:%s\n",Staff[staff_index].staff_name);
            printf("Staff Role:%s\n",Staff[staff_index].staff_role);
            printf("Staff Shift:%s\n",Staff[staff_index].staff_shift);
            printf("Staff Salary:%f\n",Staff[staff_index].staff_salary);
            printf("Staff Contact Number:%s\n",Staff[staff_index].staff_contact_number);
            printf("\n");
        }
    }
}

void search_by_staff_id(struct staff *Staff,int total_staff)
{
    int search_id;
    printf("enter staff ID to search:");
    scanf("%d",&search_id);
    int staff_found =0;
    for (int staff_index = 0; staff_index < total_staff; staff_index++)
    {
        if(Staff[staff_index].staff_id == search_id)
        {
            printf("Staff with %d ID found and details are as follows\n",search_id);
            printf("Staff ID:%d\n",Staff[staff_index].staff_id);
            printf("Staff Name:%s\n",Staff[staff_index].staff_name);
            printf("Staff Role:%s\n",Staff[staff_index].staff_role);
            printf("Staff Shift:%s\n",Staff[staff_index].staff_shift);
            printf("Staff Salary:%f\n",Staff[staff_index].staff_salary);
            printf("Staff Contact Number:%s\n",Staff[staff_index].staff_contact_number);
            printf("\n");
            staff_found =1;

        }
    }
    if(!staff_found)
    {
        printf("we could'nt found the entered id %d\n",search_id);

    }
}
void search_by_staff_role(struct staff *Staff,int total_staff)
{
    char search_role[30];
    printf("enter staff role to search:");
    scanf(" %[^\n]",search_role);
    int staff_found =0;
    for (int staff_index = 0; staff_index < total_staff; staff_index++)
    {
        if(strcasecmp(search_role,Staff[staff_index].staff_role) == 0)
        {
            printf("Staff with %s role found and details are as follows\n",search_role);
            printf("Staff ID:%d\n",Staff[staff_index].staff_id);
            printf("Staff Name:%s\n",Staff[staff_index].staff_name);
            printf("Staff Role:%s\n",Staff[staff_index].staff_role);
            printf("Staff Shift:%s\n",Staff[staff_index].staff_shift);
            printf("Staff Salary:%f\n",Staff[staff_index].staff_salary);
            printf("Staff Contact Number:%s\n",Staff[staff_index].staff_contact_number);
            printf("\n");
            staff_found =1;

        }
    }
    if(!staff_found)
    {
        printf("we could'nt found the entered role %s\n",search_role);

    }

}
void save_staff_data( struct staff *Staff,int total_staff)
{
    FILE *file;
    file = fopen ("Staff_data.txt","wb");
    if (file == NULL)
    {
        printf("Error in Saving staff data\n");
    }
    fwrite(&total_staff,sizeof (int),1,file);
    fwrite(Staff,sizeof (struct staff),total_staff,file);
    fclose(file);
    printf("Staff Data Saved Successfully\n");
}

int load_staff_data(struct staff **Staff)
{
    FILE * file;
    file = fopen("Staff_data.txt","rb");
    if(file == NULL)
    {
        printf("Error in loading staff data\n");
        return 0;
    }
    int total_staff =0;
    fread(&total_staff,sizeof(int),1,file);
    *Staff = malloc (total_staff * sizeof(struct staff));
    if(*Staff== NULL)
    {
        printf("memory allocation failed\n");
        fclose(file);
        return 0;
    }
    fread(*Staff,sizeof(struct staff),total_staff,file);
    fclose(file);
    printf("Staff data loaded successfully %d staff Available.\n",total_staff);
    return total_staff;
}



