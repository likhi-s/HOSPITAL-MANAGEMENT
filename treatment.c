#include"treatment.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define USER_ID "Treatment_user"
#define USER_PASSWORD "treatment@123"


int verify_treatment_user()
{
    char user_id[15];
    char user_pass[15];
    int option;
    int choice;
    struct treatment *treatments = NULL;
    int total_treatments=load_treatment_data(&treatments);
    printf("user ID:\n");
    scanf(" %[^\n]",user_id);
    printf("User password:\n");
    scanf(" %[^\n]",user_pass);

    if (strcmp(user_id, USER_ID) == 0 && strcmp(user_pass, USER_PASSWORD) == 0)
    {
        while(1)
        {
            printf("enter the option:\n");
            printf("1. Add treatment\n2. Update treatment\n3. Display treatment\n4. Search by ID\n5. Search by name\n6. Save data and Exit\n");
            scanf("%d",&option);
            switch(option)
            {
            case 1:
                treatments = realloc (treatments, (total_treatments +1)* sizeof(struct treatment));
                if(treatments == NULL)
                {
                    printf("Memory allocation failed\n");
                    return 0;
                }
                add_treatment(&treatments[total_treatments++]);

                break;
            case 2:
                if(total_treatments >0)
                {
                    int treatment_id;
                    printf("Enter treatment id to update:");
                    scanf("%d",&treatment_id);
                    int treatment_found =0;
                    for(int treatment_index=0; treatment_index<total_treatments;treatment_index++)
                    {
                        if(treatments[treatment_index].treatment_id==treatment_id)
                        {
                            update_treatment_details(&treatments[treatment_index]);
                            treatment_found=1;
                        }
                    }
                    if(!treatment_found)
                    {
                        printf("treatment id not found.\n");
                    }

                }
                else
                {
                    printf("INvalid Treatment Id.\n");
                }
                break;
            case 3:
                display_treatment_details(treatments,total_treatments);
                break;
            case 4:
                search_by_treatment_id(treatments,total_treatments);
                break;
            case 5:
                search_by_treatment_name(treatments,total_treatments);
                break;
            case 6:
                save_treatment_data(treatments,total_treatments);
                printf("saved the treatment data and existing\n");
                return 0;
                break;
            default:
                printf("Invalid Option.\n");
                break;
            }

        }
    }
    else
    {
        printf("inavlid user ID or Password, select choice:\n");
        printf("1.forgot Password.\n2.View Treatment details\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Contact HR manager for changes\n");
        }
        else if(choice == 2)
        {
            printf("Invalid credentials. you can just view Treatments\n");
            display_treatment_details(treatments,total_treatments);
        }
        else
        {
            printf("Invalid choice\n");
        }
    }
    return 0;
}

void add_treatment(struct treatment *t)
{
    printf("Enter Treatment ID:\n");
    scanf("%d",&t->treatment_id);
    printf("Enter Treatment Name:\n");
    scanf(" %[^\n]",t->treatment_name);
    printf("Enter treatment Cost:\n");
    scanf("%d",&t->treatment_cost);
    printf("Enter Treatment duration in days:\n");
    scanf("%d",&t->treatment_duration);
    printf("Added Treatment successfully\n");
}

void update_treatment_details(struct treatment *t)
{
    int choice;
    printf("which details you want to update?\n");
    printf("1.ID\n2.Name\n3.Cost\n4.duration\n");
    printf("enter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("Enter new Treatment ID:\n");
        scanf("%d",&t->treatment_id);
        break;
    case 2:
        printf("Enter New Treatment Name:\n");
        scanf(" %[^\n]",t->treatment_name);
        break;
    case 3:
        printf("enter New Treatment Cost:\n");
        scanf("%d",&t->treatment_cost);
        break;
    case 4:
        printf("Enter New Treatment Duration:\n");
        scanf("%d",&t->treatment_duration);
        break;
    default:
        printf("Invalid Choice\n");
    }
    printf("Treatment details updated\n");
}

void display_treatment_details(struct treatment *treatments, int total_treatments)
{
    if(total_treatments == 0)
    {
        printf("No Treatments available\n");
    }
    else
    {
        for(int treatment_index =0 ; treatment_index<total_treatments; treatment_index++)
        {
            printf("Treatment ID:%d\n",treatments[treatment_index].treatment_id);
            printf("Treatment Name:%s\n",treatments[treatment_index].treatment_name);
            printf("Treatment Cost:%d\n",treatments[treatment_index].treatment_cost);
            printf("Treatment Duration:%d\n",treatments[treatment_index].treatment_duration);
            printf("\n");
        }
    }
}
void search_by_treatment_id(struct treatment *treatments,int total_treatments)
{
    int search_id;
    printf("Enter Treatment Id to search:\n");
    scanf("%d",&search_id);
    int treatment_found =0;
    for(int treatment_index =0; treatment_index<total_treatments; treatment_index++)
    {
        if(treatments[treatment_index].treatment_id == search_id)
        {
            printf("treatment with %d Id found and details are as follows\n",search_id);
            printf("Treatment ID:%d\n",treatments[treatment_index].treatment_id);
            printf("Treatment Name:%s\n",treatments[treatment_index].treatment_name);
            printf("Treatment Cost:%d\n",treatments[treatment_index].treatment_cost);
            printf("Treatment Duration:%d\n",treatments[treatment_index].treatment_duration);
            printf("\n");
            treatment_found=1;
        }
    }
    if(!treatment_found)
    {
        printf("we couldn't found the entered id %d\n",search_id);
    }
}


void search_by_treatment_name(struct treatment *treatments, int total_treatments)
{
    char search_name[100];
    printf("Enter treatment Name to search:\n");
    scanf(" %[^\n]",&search_name);
    int treatment_found=0;
    for(int treatment_index=0; treatment_index<total_treatments; treatment_index++)
    {
        if(strcasecmp(search_name,treatments[treatment_index].treatment_name)==0)
        {
            printf("treatment with %s Id found and details are as follows\n",search_name);
            printf("Treatment ID:%d\n",treatments[treatment_index].treatment_id);
            printf("Treatment Name:%s\n",treatments[treatment_index].treatment_name);
            printf("Treatment Cost:%d\n",treatments[treatment_index].treatment_cost);
            printf("Treatment Duration:%d\n",treatments[treatment_index].treatment_duration);
            printf("\n");
            treatment_found=1;
        }
    }
    if(!treatment_found)
    {
        printf("we couldn't found the entered treatment name %s\n",search_name);
    }

}

void save_treatment_data(struct treatment *treatments,int total_treatments)
{
    FILE *file;
    file = fopen("Treatment_data.txt","wb");
    if(file == NULL)
    {
        printf("Error in saving Treatment Data");

    }
    fwrite(&total_treatments,sizeof(int),1,file);
    fwrite(treatments,sizeof(struct treatment),total_treatments,file);
    fclose(file);
    printf("Treatment data saved successfully\n");
}

int load_treatment_data(struct treatment **treatments)
{
    FILE *file;
    file =fopen("Treatment_data.txt","rb");
    if(file == NULL)
    {
        printf("no treatment data exists\n");
        return 1;
    }
    int total_treatments;
    fread(&total_treatments,sizeof(int),1,file);
    *treatments = malloc (total_treatments * sizeof(struct treatment));
    if(*treatments == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }
    fread(*treatments,sizeof(struct treatment),total_treatments,file);
    fclose(file);
    printf("Treatment data loaded successfully and  %d Treatment found\n",total_treatments);
    return total_treatments;
}
