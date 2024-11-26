#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "room.h"
#define USER_ID "room_user"
#define USER_PASSWORD "room@123"

int verify_room_management_user()
{
    char user_id[15];
    char user_pass[15];
    int option;
    int choice;

    struct room_management *rooms = NULL;
    int total_rooms = load_room_data(&rooms);

    printf("User Id:\n");
    scanf(" %[^\n]", user_id);
    printf("User Password:\n");
    scanf(" %[^\n]", user_pass);

    if (strcmp(user_id, USER_ID) == 0 && strcmp(user_pass, USER_PASSWORD) == 0)
    {
        while(1)
        {
            printf("Enter the option:\n");
            printf("1.add\n2.update\n3.display\n4.search by id\n5.search by type\n6.check availability\n7.save and exit\n");
            scanf("%d",&option);
            switch(option)
            {
            case 1:
                rooms = realloc(rooms, (total_rooms + 1)* sizeof(struct room_management));
                if(rooms == NULL)
                {
                    printf("Memory allocation failed\n");
                    return 1;
                }
                add_room(&rooms[total_rooms++]);
                break;
            case 2:
                if(total_rooms> 0)
                {
                    int room_id;
                    printf("enter the room id to update:");
                    scanf("%d",&room_id);
                    int room_found = 0;
                    for(int room_index = 0; room_index < total_rooms; room_index++)
                    {
                        if(rooms[room_index].room_id== room_id)
                        {
                            update_room_details(&rooms[room_index]);
                            room_found = 1;

                        }
                    }
                    if(!room_found)
                    {
                        printf("room id not found.\n");
                    }

                }
                else
                {
                    printf("No rooms found.\n");
                }
                break;
            case 3:
                display_room_details(rooms,total_rooms);
                break;
            case 4:
                search_by_room_id(rooms,total_rooms);
                break;
            case 5:
                search_by_room_type(rooms,total_rooms);
                break;
            case 6:
                check_availability(rooms,total_rooms);
                break;
            case 7:
                save_room_data(rooms,total_rooms);
                free(rooms);
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
        printf("1.forgot password.\n2.view rooms\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("contact HR Manager for changes\n");
        }
        else if (choice==2)
        {
            printf("invalid credentials.You can just view rooms.\n");
            display_room_details(rooms,total_rooms);
        }
        else
        {
            printf("invalid choice\n");
        }
    }
    return 1;
}

void add_room(struct room_management *r)
{
    printf("Enter room ID:\n");
    scanf("%d",&r->room_id);
    printf("Enter room Type:\n");
    scanf(" %[^\n]",r->room_type);
    printf("Enter Bed Count:\n");
    scanf("%d",&r->bed_count);
    printf("Enter Available Beds:\n");
    scanf("%d",&r->available_beds);
    printf("Enter bed status(occupied /vaccant)\n");
    scanf(" %[^\n]",r->bed_status);
    printf("Enter room Fee\n");
    scanf("%f",&r->room_fee);
    printf("Room added Successfully\n");
}

void update_room_details(struct room_management *r)
{
    int choice;
    printf("which details you want to update?\n");
    printf("1.ID\n2.type\n3.bed count\n4.available beds\n5.bed status\n6.fee\n");
    printf("Enter Choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("Enter new room ID:\n");
        scanf("%d",&r->room_id);
        break;
    case 2:
        printf("Enter new room Type:\n");
        scanf(" %[^\n]",r->room_type);
        break;
    case 3:
        printf("Enter new Bed Count:\n");
        scanf("%d",&r->bed_count);
        break;
    case 4:
        printf("Enter new Available Beds:\n");
        scanf("%d",&r->available_beds);
        break;
    case 5:
        printf("Enter new bed status(occupied /vaccant)\n");
        scanf(" %[^\n]",r->bed_status);
        break;
    case 6:
        printf("Enter room Fee\n");
        scanf("%f",&r->room_fee);
        break;
    }
    printf("Room updated Successfully\n");
}

void display_room_details(struct room_management *rooms, int total_rooms)
{
    if(total_rooms == 0)
    {
        printf("No rooms Available\n");
    }
    else
    {
        for(int room_index =0; room_index <total_rooms; room_index++)
        {
            printf("Room ID:%d\n", rooms[room_index].room_id);
            printf("Room Type:%s\n", rooms[room_index].room_type);
            printf("Bed Count:%d\n", rooms[room_index].bed_count);
            printf("Available beds:%d\n", rooms[room_index].available_beds);
            printf("Bed Status:%s\n", rooms[room_index].bed_status);
            printf("Room Fee:%f\n", rooms[room_index].room_fee);
            printf("\n");
        }
    }
}

void search_by_room_id(struct room_management *rooms, int total_rooms)
{
    int search_id;
    printf("Enter room Id to search:");
    scanf("%d",&search_id);
    int room_found =0;
    for(int room_index =0; room_index <total_rooms; room_index++)
    {
        if(rooms[room_index].room_id == search_id)
        {
            printf("Room with %d ID found and details are as follows\n",search_id);
            printf("Room ID:%d\n", rooms[room_index].room_id);
            printf("Room Type:%s\n", rooms[room_index].room_type);
            printf("Bed Count:%d\n", rooms[room_index].bed_count);
            printf("Available beds:%d\n", rooms[room_index].available_beds);
            printf("Bed Status:%s\n", rooms[room_index].bed_status);
            printf("Room Fee:%f\n", rooms[room_index].room_fee);
            printf("\n");
            room_found=1;
        }
    }
    if(!room_found)
    {
        printf("We could'nt found the entered id %d\n",search_id);
    }
}

void search_by_room_type(struct room_management *rooms, int total_rooms)
{
    char search_type[10];
    printf("enter room type to search:\n");
    scanf(" %[^\n]",search_type);
    int room_found =0;
    for(int room_index =0; room_index <total_rooms; room_index++)
    {
        if(strcasecmp(search_type,rooms[room_index].room_type)==0)
        {
            printf("Room with %s type found and details are as follows\n",search_type);
            printf("Room ID:%d\n", rooms[room_index].room_id);
            printf("Room Type:%s\n", rooms[room_index].room_type);
            printf("Bed Count:%d\n", rooms[room_index].bed_count);
            printf("Available beds:%d\n", rooms[room_index].available_beds);
            printf("Bed Status:%s\n", rooms[room_index].bed_status);
            printf("Room Fee:%d\n", rooms[room_index].room_fee);
            printf("\n");
            room_found=1;

        }
    }
    if(!room_found)
    {
        printf("We could'nt found the entered type %s\n",search_type);
    }
}
void check_availability(struct room_management *rooms, int total_rooms)
{
    int available_bed_count = 0;

    printf("Checking room availability\n");
    for (int room_index = 0; room_index < total_rooms; room_index++)
    {

        if (strcasecmp(rooms[room_index].bed_status, "vacant") == 0)
        {
            available_bed_count++;
            printf("Room ID: %d\n", rooms[room_index].room_id);
            printf("Room Type: %s\n", rooms[room_index].room_type);
            printf("Available Beds: %d\n", rooms[room_index].available_beds);
            printf("Room Fee: %f\n", rooms[room_index].room_fee);
            printf("\n");

        }
    }
    if (available_bed_count == 0)
    {
        printf("No vacant rooms are available.\n");
    }
    else
    {
        printf("Total number of vacant rooms: %d\n", available_bed_count);
    }
}


void save_room_data(struct room_management *rooms, int total_rooms)
{
    FILE *file;
    file=fopen("Room_data.txt","wb");
    if(file == NULL)
    {
        printf("error in opening file\n");
    }
    fwrite(&total_rooms, sizeof(int),1,file);
    fwrite(rooms,sizeof(struct room_management),total_rooms,file);
    fclose(file);
    printf("room data saved successfully\n");
}
int load_room_data(struct room_management **rooms)
{
    FILE *file;
    file = fopen("Room_data.txt","rb");
    if(file == NULL)
    {
        printf("no room data exists\n");
        return 0;
    }
    int total_rooms =0;
    fread(&total_rooms, sizeof(int),1,file);
    *rooms =  malloc(total_rooms * sizeof(struct room_management));
    if(*rooms == NULL)
    {
        printf("Memory allocation Failed\n");
        fclose(file);
        return 0;
    }
    fread(*rooms, sizeof(struct room_management),total_rooms,file);
    fclose(file);
    printf("room data loaded sucessfully %d rooms found.\n",total_rooms);
    return total_rooms;
}

