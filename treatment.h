#ifndef TREATMENT_H
#define TREATMENT_H
struct treatment
{
    int treatment_id;
    char treatment_name[100];
    int treatment_cost;
    int treatment_duration;//in days
};
int verify_treatment_user();
void add_treatment(struct treatment *t);
void update_treatment_details(struct treatment *t);
void display_treatment(struct treatment *treatments,int total_treatments);
void search_by_treatment_id(struct treatment *treatments,int total_treatments);
void search_by_treatment_name(struct treatment *treatments,int total_treatments);
//file handling
void save_treatment_data(struct treatment *treatments,int total_treatments);
int load_treatment_data(struct treatment **treatments);

#endif // TREATMENT_H
