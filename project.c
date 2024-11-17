#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient 
{
    int patient_id;
    char name[50];
    int age;
    char gender[10];
    char condition[100];
    struct Patient* next;
};



struct Patient* createPatient(int patient_id, char name[], int age, char gender[], char condition[]) 
{
    struct Patient* newPatient = (struct Patient*)malloc(sizeof(struct Patient));
    newPatient->patient_id = patient_id;
    strcpy(newPatient->name, name);
    newPatient->age = age;
    strcpy(newPatient->gender, gender);
    strcpy(newPatient->condition, condition);
    newPatient->next = NULL;
    return newPatient;
}



void addPatient(struct Patient** head, int patient_id, char name[], int age, char gender[], char condition[]) 
{
    struct Patient* newPatient = createPatient(patient_id, name, age, gender, condition);
    if (*head == NULL) 
    {
        *head = newPatient;
    } 
    else 
    {
        struct Patient* current = *head;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = newPatient;
    }
}



void savePatientsToFile(struct Patient* head) 
{
    FILE* file = fopen("patients.txt", "w");
    if (file == NULL) 
    {
        printf("Error opening file\n");
        return;
    }
    struct Patient* current = head;
    while (current != NULL) 
    {
        fprintf(file, "%d;%s;%d;%s;%s;\n", current->patient_id, current->name, current->age, current->gender, current->condition);
        current = current->next;
    }
    fclose(file);
}



struct Patient* searchPatient(struct Patient* head, int patient_id) 
{
    struct Patient* current = head;
    while (current != NULL) 
    {
        if (current->patient_id == patient_id) 
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}




void removePatient(struct Patient** head, int patient_id) 
{
    if (*head == NULL) 
    {
        return;
    }
    struct Patient* current = *head;
    struct Patient* prev = NULL;
    if (current->patient_id == patient_id)
     {
        *head = current->next;
        free(current);
        return;
    }
    while (current != NULL) 
    {
        if (current->patient_id == patient_id) 
        {
            prev->next = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}





void displayPatients(struct Patient* head) 
{
    struct Patient* current = head;
    while (current != NULL) 
    {
        printf("Patient ID: %d\n", current->patient_id);
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("Gender: %s\n", current->gender);
        printf("Medical Problems: %s\n", current->condition);
        printf("-----------------\n");
        current = current->next;
    }
}





void freePatients(struct Patient* head) 
{
    struct Patient* current = head;
    
    while (current != NULL)
     {
        struct Patient* temp = current;
        current = current->next;
        free(temp);
    }
}


void loadPatientsFromFile(struct Patient** head) 
{
    FILE* file = fopen("patients.txt", "r");
    if (file == NULL) 
    {
        printf("Error opening file\n");

        
        return;
    }
    int patient_id, age;
    char name[50], gender[10], condition[100];
    while (fscanf(file, "%d;%[^;];%d;%[^;];%[^;];\n", &patient_id, name, &age, gender, condition) == 5) 
    {
        addPatient(head, patient_id, name, age, gender, condition);
    }
    fclose(file);
}

int main() 
{
    struct Patient* head = NULL;

    
    loadPatientsFromFile(&head);

    addPatient(&head, 1, "Brown", 30, "Male", "Back pain");
    addPatient(&head, 2, "Johnson", 36, "Male", "Diabeties");
    addPatient(&head, 3, "David Brown", 50, "Male", "High blood pressure");
    addPatient(&head, 4, "Emily Johnson", 30, "Female", "Back pain");
    addPatient(&head, 5, "Emi", 32, "Female", "pain");
    
    printf("Patients:\n");
    displayPatients(head);

    
    savePatientsToFile(head);
    printf("Patients saved to file.\n");

    
    int search_id = 2;
    struct Patient* found_patient = searchPatient(head, search_id);
    if (found_patient != NULL) 
    {
        printf("\nPatient with ID %d found:\n", search_id);
        printf("Name: %s\n", found_patient->name);
        printf("Age: %d\n", found_patient->age);
        printf("Gender: %s\n", found_patient->gender);
        printf("Medical Problems: %s\n", found_patient->condition);
    } 
    else 
    {
        printf("\nPatient with ID %d not found.\n", search_id);
    }

    
    int remove_id = 1;
    removePatient(&head, remove_id);
    printf("\nPatient with ID %d removed.\n", remove_id);

    printf("\nPatients after removal:\n");
    displayPatients(head);

    freePatients(head);

    return 0;
}