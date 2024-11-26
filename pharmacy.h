#ifndef PHARMACY_H
#define PHARMACY_H
struct pharmacy
{
    int medicine_id;
    char medicine_name[100];
    float medicine_cost;
    int medicine_stock_quantity;
    char medicine_type[20];// tablet/injection
    char medicine_dosage[100];
};

int verify_pharmacy_user();
void add_medicine(struct pharmacy *m);
void update_medicine_details(struct pharmacy *m);
void display_medicine_details(struct pharmacy *medicines,int total_medicine);
void search_by_medicine_id(struct pharmacy *medicines,int total_medicine);
void search_by_medicine_name(struct pharmacy *medicines,int total_medicine);
void check_stock(struct pharmacy *medicines,int total_medicine);
//file handling
void save_medicine_data(struct pharmacy *medicines,int total_medicine);
int load_medicine_data(struct pharmacy **medicines);
#endif // PHARMACY_H
