#ifndef DOCTOR_H
#define DOCTOR_H

struct doctor
{
    int doctor_id;
    char doctor_name[100];
    char doctor_specialization[20];
    float doctor_consultation_fee;
    char doctor_contact_number[15];
    int doctor_experience;
    char doctor_qualification[50];
};

int verify_doctor_user();
void add_doctor(struct doctor *d);
void update_doctor_details(struct doctor *d);
void display_doctor_details(struct doctor *doctors, int total_doctors);
void search_by_doctor_id(struct doctor *doctors, int total_doctors);
void search_by_doctor_specialization(struct doctor *doctors, int total_doctors);
//file handling
void save_doctor_data(struct doctor *doctors, int total_doctors);
int load_doctor_data(struct doctor **doctors);

#endif // DOCTOR_H
