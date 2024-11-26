#include "Patient.h"
#include "doctor.h"
#include "staff.h"
#include "treatment.h"
#include"pharmacy.h"
#include"room.h"
#include "bill.c"

int main_menu()
{
    int choice;
    printf("1.patient_user\n2.doctor_user\n3.Staff_user\n4.Treatment_user\n5.Pharmacy_user\n6.Room management_user\n7.Bill_user\n");
    printf("enter the choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        verify_patient_user();
        break;

    case 2:
        verify_doctor_user();
        break;
    case 3:
        verify_staff_user();
        break;
    case 4:
        verify_treatment_user();
        break;
    case 5:
        verify_pharmacy_user();
        break;
    case 6:
        verify_room_management_user();
        break;
    case 7:
        verify_billing_user();
        break;
    default:
        printf("invalid choice\n");
        break;

    }
}




