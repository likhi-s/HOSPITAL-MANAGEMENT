#ifndef PATIENT_H
#define PATIENT_H


struct patient
{
    int  patient_id;
    char patient_name[100];
    char patient_gender[10];
    int  patient_age;
    char patient_address[200];
    char patient_contact_number[15];
    char patient_emergency_contact_number[15];
};
int verify_patient_user();
void register_patient(struct patient *p);
void update_patient_details(struct patient *p);
void display_patient_details(struct patient *patients, int total_patients);
void search_by_patient_id(struct patient *patients, int total_patients);
void search_by_patient_name(struct patient *patients, int total_patients);
void save_patient_data(struct patient *patients, int total_patients);
int load_patient_data(struct patient **patients);





#endif // PATIENT_H
