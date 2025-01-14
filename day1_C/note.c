#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50

//typedef : struct Appointment 변수이름 -> Appointment 변수이름
typedef struct Appointment {
    int id; //고유한 데이터를 나타내기 위해서 사용
    char date[20];
    char time[10];
    struct Appointment *next; // 포인터를 통해서 다음 약속의 구조체의 주소를 저장장
} Appointment;

typedef struct Patient {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    Appointment *appointments;
    struct Patient *next;
} Patient;

typedef struct Doctor {
    int id;
    char name[MAX_NAME_LENGTH];
    char specialization[MAX_NAME_LENGTH];
    Patient *patients;
    struct Doctor *next;
} Doctor;

Doctor *headDoctor = NULL;

// Function to create a new doctor
//char 문자형 -> 1개의 문자, 아 배열이구나
Doctor *createDoctor(int id, const char *name, const char *specialization) {
    Doctor *newDoctor = (Doctor *)malloc(sizeof(Doctor));
    (*newDoctor).id = id;
    newDoctor->id = id;
    strncpy(newDoctor->name, name, MAX_NAME_LENGTH);
    strncpy(newDoctor->specialization, specialization, MAX_NAME_LENGTH);
    newDoctor->patients = NULL;
    newDoctor->next = NULL;
    return newDoctor;
}

// Function to create a new patient
Patient *createPatient(int id, const char *name, int age) {
    Patient *newPatient = (Patient *)malloc(sizeof(Patient));
    newPatient->id = id;
    strncpy(newPatient->name, name, MAX_NAME_LENGTH);
    newPatient->age = age;
    newPatient->appointments = NULL;
    newPatient->next = NULL;
    return newPatient;
}

// Function to create a new appointment
Appointment *createAppointment(int id, const char *date, const char *time) {
    Appointment *newAppointment = (Appointment *)malloc(sizeof(Appointment));
    newAppointment->id = id;
    strncpy(newAppointment->date, date, 20);
    strncpy(newAppointment->time, time, 10);
    newAppointment->next = NULL;
    return newAppointment;
}

// Function to add a doctor to the list
void addDoctor(Doctor *doctor) {
    (*doctor).next = headDoctor; // head : null
    headDoctor = doctor;    // head = doctor
    // 1 -> 2 -> 3  (1)head add 4
/*
1) 4 -> head(1)
2) head(4)
3) 4 -> 1 -> 2 -> 3
*/

    // 4 -> 1 -> 2-> 3
    doctor->next = headDoctor;
    headDoctor = doctor;
}

// Function to add a patient to a specific doctor
void addPatientToDoctor(int doctorId, Patient *patient) {
    Doctor *current = headDoctor;
    while (current != NULL && current->id != doctorId) {
        current = current->next;
    }
    if (current != NULL) {
        patient->next = current->patients;
        current->patients = patient;
    } else {
        printf("Doctor with ID %d not found.\n", doctorId);
    }
}

// Function to add an appointment to a patient
void addAppointmentToPatient(int doctorId, int patientId, Appointment *appointment) {
    Doctor *currentDoctor = headDoctor;
    while (currentDoctor != NULL && currentDoctor->id != doctorId) {
        currentDoctor = currentDoctor->next;
    }
    if (currentDoctor != NULL) {
        Patient *currentPatient = currentDoctor->patients;
        while (currentPatient != NULL && currentPatient->id != patientId) {
            currentPatient = currentPatient->next;
        }
        if (currentPatient != NULL) {
            appointment->next = currentPatient->appointments;
            currentPatient->appointments = appointment;
        } else {
            printf("Patient with ID %d not found under Doctor ID %d.\n", patientId, doctorId);
        }
    } else {
        printf("Doctor with ID %d not found.\n", doctorId);
    }
}

typedef struct Doctor {
    int id;
    struct Doctor *next;
} Doctor;

Doctor *headDoctor = NULL;

void addDoctor(Doctor *doctor) {
    doctor->next = headDoctor;
    headDoctor = doctor;
}

void displayDoctors() {
    Doctor *currentDoctor = headDoctor; //current : 4
    while (currentDoctor != NULL) {
        // printf("Doctor ID: %d\n", currentDoctor->id);
        currentDoctor = currentDoctor->next; // 4 -> cur(1)
    }
}
1) head = NULL
2) Doctor d = {3, NULL};addDoctor(&d);
3) Doctor *d = (Doctor *)malloc(sizeof(Doctor)); d->id = 3;addDoctor(d);
3 -> NULL, head(3)
1->2->3->NULL, head(1)
4) displayDoctors(), head(1) , cur(1);
5) Doctor ID : 1 \n
6)cur = (cur(1->) == 2) , cur(2)

cur(2)-> 3

// Function to free all allocated memory
// 4->1->2->3->NULL
void freeAll() {
    Doctor *currentDoctor = headDoctor;
    while (currentDoctor != NULL) {
        Doctor *tempDoctor = currentDoctor;
        // Patient *currentPatient = currentDoctor->patients;
        // while (currentPatient != NULL) {
        //     Patient *tempPatient = currentPatient;
        //     Appointment *currentAppointment = currentPatient->appointments;
        //     while (currentAppointment != NULL) {
        //         Appointment *tempAppointment = currentAppointment;
        //         currentAppointment = currentAppointment->next;
        //         free(tempAppointment);
        //     }
        //     currentPatient = currentPatient->next;
        //     free(tempPatient);
        // }
        currentDoctor = currentDoctor->next;
        free(tempDoctor);
    }
}

int main() {
    Doctor *doc1 = createDoctor(1, "Dr. Smith", "Cardiology");
    Doctor *doc2 = createDoctor(2, "Dr. Brown", "Neurology");

    addDoctor(doc1);
    addDoctor(doc2);

    Patient *pat1 = createPatient(101, "Alice", 30);
    Patient *pat2 = createPatient(102, "Bob", 40);
    Patient *pat3 = createPatient(103, "Charlie", 25);

    addPatientToDoctor(1, pat1);
    addPatientToDoctor(1, pat2);
    addPatientToDoctor(2, pat3);

    Appointment *app1 = createAppointment(201, "2025-01-15", "10:00 AM");
    Appointment *app2 = createAppointment(202, "2025-01-16", "11:30 AM");
    Appointment *app3 = createAppointment(203, "2025-01-17", "09:00 AM");

    addAppointmentToPatient(1, 101, app1);
    addAppointmentToPatient(1, 102, app2);
    addAppointmentToPatient(2, 103, app3);

    displayDoctors();

    freeAll();
    return 0;
}
