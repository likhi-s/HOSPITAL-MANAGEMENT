#ifndef BILL_H
#define BILL_H
struct bill
{
    int bill_id;
    int patient_id;
    int treatment_id;
    float consultation_fee;
    float pharmacy_fee;
    float room_fee;
    float total_bill_amount;
    char bill_date[20];
};

int verify_billing_user();
void add_bill(struct bill *b);
void update_bill_details(struct bill *b);
void display_bill_details(struct bill *bills,int total_bills);
void search_bill_by_patient_id(struct bill *bills,int total_bills);
void calculate_bill(struct bill *b);
//file handling
void save_bill_data(struct bill *bills,int total_bills);
int load_bill_data(struct bill **bills);

#endif // BILL_H
