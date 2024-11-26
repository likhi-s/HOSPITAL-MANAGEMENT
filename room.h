#ifndef ROOM_H
#define ROOM_H

struct room_management
{
    int room_id;
    char room_type[10]; //icu/general/private
    int bed_count;
    int available_beds;
    char bed_status[10];// occupied/vacant
    float room_fee;
};
int verify_room_management_user();
void add_room(struct room_management *r);
void update_room_details(struct room_management *r);
void display_room_details(struct room_management *rooms, int total_rooms);
void search_by_room_id(struct room_management *rooms, int total_rooms);
void search_by_room_type(struct room_management *rooms, int total_rooms);
void check_availability(struct room_management *rooms, int total_rooms);
//file handling
void save_room_data(struct room_management *rooms, int total_rooms);
int load_room_data(struct room_management **rooms);

#endif // ROOM_H
