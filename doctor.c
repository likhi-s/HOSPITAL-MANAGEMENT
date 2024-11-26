#include"doctor.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define USER_ID "doctor_user"
#define USER_PASSWORD "doctor@123"


int verify_doctor_user()
{
    char user_id[15];
    char user_pass[15];
    int option;
    int choice;
    struct doctor *doctors = NULL;
    int total_doctors = load_doctor_data(&doctors);
    printf("user ID:\n");
    scanf(" %[^\n]",user_id);
    printf("User password:\n");
    scanf(" %[^\n]",user_pass);

    if (strcmp(user_id, USER_ID) == 0 && strcmp(user_pass, USER_PASSWORD) == 0)
    {
        while(1)
        {
            printf("enter the option:\n");
            printf("1. Add doctor\n2. Update doctor\n3. Display doctor\n4. Search by ID\n5. Search by specialization\n6. Save data and Exit\n");
            scanf("%d", &option);
            switch(option)
            {
            case 1:
                doctors = realloc (doctors,(total_doctors + 1) * sizeof(struct doctor));
                if(doctors == NULL)
                {
                    printf("memory allocation failed\n");
                    return 1;
                }
                add_doctor(&doctors[total_doctors++]);
                break;
            case 2:
                if(total_doctors > 0)
                {
                    int doctor_id;
                    printf("enter the doctor id to update:");
                    scanf("%d",&doctor_id);
                    int doctor_found =0;
                    for(int doctor_index = 0; doctor_index < total_doctors; doctor_index++)
                    {
                        if(doctors[doctor_index].doctor_id== doctor_id)
                        {
                            update_doctor_details(&doctors[doctor_index]);
                            doctor_found =1;
                            break;
                        }
                    }
                    if(!doctor_found)
                    {
                        printf("doctor id not found\n");
                    }
                }
                else
                {
                    printf("No doctors found.\n");
                }
                break;
            case 3:
                display_doctor_details(doctors,total_doctors);
                break;
            case 4:
                search_by_doctor_id(doctors,total_doctors);
                break;
            case 5:
                search_by_doctor_specialization(doctors,total_doctors);
                break;
            case 6:
                save_doctor_data(doctors,total_doctors);
                printf("saved doctor data and exiting\n");
                free(doctors);
                return 0;
            default:
                printf("invalid option\n");
                break;
            }
        }
    }
    else
    {
        printf("invalid user id or password,select choice:\n");
        printf("1.forgot password.\n2.view doctors\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("contact HR Manager for changes\n");
        }
        else if (choice==2)
        {
            printf("invalid credentials.You can just view doctors.\n");
            display_doctor_details(doctors,total_doctors);;
        }
        else
        {
            printf("invalid choice\n");
        }
    }
    return 1;
}



void add_doctor(struct doctor *d)
{
    printf("Enter Doctor ID:\n");
    scanf("%d",&d->doctor_id);
    printf("Enter Doctor Name:\n");
    scanf(" %[^\n]",d->doctor_name);
    printf("Enter Doctor Specialization:\n");
    scanf(" %[^\n]",d->doctor_specialization);
    printf("Enter doctor Consultation fee:\n");
    scanf("%f",&d->doctor_consultation_fee);
    printf("Enter Doctor contact number:\n");
    scanf(" %[^\n]",d->doctor_contact_number);
    printf("Enter Doctor experience:\n");
    scanf("%d",&d->doctor_experience);
    printf("Enter doctor Qualification:\n");
    scanf(" %[^\n]",d->doctor_qualification);
    printf("doctor added successfully\n");
}



void update_doctor_details(struct doctor *d)
{
    int choice;
    printf("which detials you want to update?\n");
    printf("1.ID\n2.Name\n3.Specialization\n4.consulation fee\n5.contact number\n6.experience\n7.qualification\n");
    printf("enter choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("enter new Doctor Id:");
        scanf("%d",&d->doctor_id);
        break;
    case 2:
        printf("Enter New Doctor Name:");
        scanf(" %[^\n]",d->doctor_name);
        break;
    case 3:
        printf("Enter New Doctor Specialization:");
        scanf(" %[^\n]",d->doctor_specialization);
        break;
    case 4:
        printf("Enter new doctor Consultation fee:\n");
        scanf("%f",&d->doctor_consultation_fee);
        break;
    case 5:
        printf("Enter new Doctor contact number:\n");
        scanf(" %[^\n]",d->doctor_contact_number);
        break;
    case 6:
        printf("Enter new Doctor experience:\n");
        scanf("%d",d->doctor_experience);
        break;
    case 7:
        printf("Enter new doctor Qualification:\n");
        scanf(" %[^\n]",d->doctor_qualification);
        break;
    default:
        printf("invalid choice\n");
        break;
    }
    printf("required doctor details updated\n");
}



void display_doctor_details(struct doctor *doctors, int total_doctors)
{
    if(total_doctors ==0)
    {
        printf("No doctors Available\n");
    }
    else
    {
        for(int doctor_index =0 ; doctor_index < total_doctors; doctor_index++)
        {
            printf("Doctor ID:%d\n", doctors[doctor_index].doctor_id);
            printf("Doctor Name:%s\n",doctors[doctor_index].doctor_name);
            printf("Doctor Specialization:%s\n",doctors[doctor_index].doctor_specialization);
            printf("Doctor Consultation Fee:%f\n",doctors[doctor_index].doctor_consultation_fee);
            printf("Doctor Contact Number:%s\n",doctors[doctor_index].doctor_contact_number);
            printf("Doctor Experience:%d\n",doctors[doctor_index].doctor_experience);
            printf("Doctor Qualification:%s\n",doctors[doctor_index].doctor_qualification);
            printf("\n");
        }
    }
}



void search_by_doctor_id(struct doctor *doctors, int total_doctors)
{
    int search_id;
    printf("Enter doctor Id to search:");
    scanf("%d",&search_id);
    int doctor_found=0;
    for (int doctor_index = 0; doctor_index < total_doctors; doctor_index++)
    {
        if(doctors[doctor_index].doctor_id == search_id)
        {
            printf("doctor with %d ID found and details are as follows\n",search_id);
            printf("Doctor ID:%d\n", doctors[doctor_index].doctor_id);
            printf("Doctor Name:%s\n",doctors[doctor_index].doctor_name);
            printf("Doctor Specialization:%s\n",doctors[doctor_index].doctor_specialization);
            printf("Doctor Consultation Fee:%f\n",doctors[doctor_index].doctor_consultation_fee);
            printf("Doctor Contact Number:%s\n",doctors[doctor_index].doctor_contact_number);
            printf("Doctor Experience:%d\n",doctors[doctor_index].doctor_experience);
            printf("Doctor Qualification:%s\n",doctors[doctor_index].doctor_qualification);
            printf("\n");
            doctor_found=1;

        }
    }
    if(!doctor_found)
    {
        printf("doctor id %d not available\n",search_id);
    }

}


void search_by_doctor_specialization(struct doctor *doctors, int total_doctors)
{
    char search_specialization[200];
    printf("enter doctor specialization to search:");
    scanf(" %[^\n]",search_specialization);
    int doctor_found =0;
    for (int doctor_index = 0; doctor_index < total_doctors; doctor_index++)
    {
        if(strcasecmp(search_specialization,doctors[doctor_index].doctor_specialization)==0)
        {
            printf("doctor with %s specialization found and details are as follows:\n",search_specialization);
            printf("Doctor ID:%d\n", doctors[doctor_index].doctor_id);
            printf("Doctor Name:%s\n",doctors[doctor_index].doctor_name);
            printf("Doctor Specialization:%s\n",doctors[doctor_index].doctor_specialization);
            printf("Doctor Consultation Fee:%f\n",doctors[doctor_index].doctor_consultation_fee);
            printf("Doctor Contact Number:%s\n",doctors[doctor_index].doctor_contact_number);
            printf("Doctor Experience:%d\n",doctors[doctor_index].doctor_experience);
            printf("Doctor Qualification:%s\n",doctors[doctor_index].doctor_qualification);
            printf("\n");
            doctor_found=1;

        }
    }
    if(!doctor_found)
    {
        printf("patient with name %s not found\n",search_specialization);
    }
}


void save_doctor_data(struct doctor *doctors, int total_doctors)
{
    FILE *file;
    file=fopen("Doctor_data.txt","wb");
    if(file == NULL)
    {
        printf("error in saving doctor data to file\n");
    }
    fwrite(&total_doctors, sizeof(int),1,file);
    fwrite(doctors,sizeof(struct doctor),total_doctors,file);
    fclose(file);
    printf("doctor data saved successfully\n");
}
int load_doctor_data(struct doctor **doctors)
{
    FILE *file;
    file = fopen("Doctor_data.txt","rb");
    if(file == NULL)
    {
        printf("no doctor data exists\n");
        return 0;
    }
    int total_doctors =0;
    fread(&total_doctors, sizeof(int),1,file);
    *doctors = malloc(total_doctors * sizeof(struct doctor));
    if (*doctors == NULL)
    {
        printf("Memory allocation failed\n");
        fclose(file);
        return 0;
    }
    fread(*doctors, sizeof(struct doctor),total_doctors,file);
    fclose(file);
    printf("doctor data loaded sucessfully %d doctors found.\n",total_doctors);
    return total_doctors;
}




