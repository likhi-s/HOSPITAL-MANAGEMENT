#ifndef STAFF_H
#define STAFF_H
struct staff
{
    int staff_id;
    char staff_name[100];
    char staff_role[50];      //eg:nurse,technician,receptionist
    char staff_shift[10];    //day or night
    float staff_salary;
    char staff_contact_number[15];
};

int verify_staff_user();
void add_staff(struct staff *s);
void update_staff_details(struct staff *s);
void display_staff_details(struct staff *Staff,int total_staff);
void search_by_staff_id(struct staff *Staff, int total_staff);
void search_by_staff_role(struct staff *Staff, int total_staff);
//file handling
void save_staff_data(struct staff *Staff, int total_staff);
int load_staff_data(struct staff **Staff);


#endif // STAFF_H
