#include <stdio.h>

#define MAX_STUDENTS 50

typedef struct {
    int roll;
    char name[50];
    float marks;
} Student;

void add_student(Student list[], int *count) {
    if (*count >= MAX_STUDENTS) { printf("Storage full.\n"); return; }
    Student s;
    printf("Roll number: "); scanf("%d", &s.roll);
    printf("Name (no spaces): "); scanf("%49s", s.name);
    printf("Marks: "); scanf("%f", &s.marks);
    list[(*count)++] = s;
    printf("Student added.\n");
}

void list_students(const Student list[], int count) {
    if (count == 0) { printf("No records found.\n"); return; }
    float sum = 0.0f;
    printf("\nRoll\tName\t\tMarks\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-15s\t%.2f\n", list[i].roll, list[i].name, list[i].marks);
        sum += list[i].marks;
    }
    printf("Average Marks: %.2f\n", sum / count);
}

void search_student(const Student list[], int count, int roll) {
    for (int i = 0; i < count; i++) {
        if (list[i].roll == roll) {
            printf("Found -> Roll: %d | Name: %s | Marks: %.2f\n", list[i].roll, list[i].name, list[i].marks);
            return;
        }
    }
    printf("Student not found.\n");
}

int main(void) {
    Student records[MAX_STUDENTS];
    int count = 0, choice, roll;
    do {
        printf("\n1. Add Student\n2. View All & Average\n3. Search by Roll\n4. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) add_student(records, &count);
        else if (choice == 2) list_students(records, count);
        else if (choice == 3) { printf("Roll: "); scanf("%d", &roll); search_student(records, count, roll); }
    } while (choice != 4);
    return 0;
}
