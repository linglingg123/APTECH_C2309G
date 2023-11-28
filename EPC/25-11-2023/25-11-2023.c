#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Student{
	char name[50];
	int age;
	float GPA;
};

void inputStudent(int numberOfStudents, struct Student students[]){
	int i;
//	printf("%d", sizeof(students));
	for(i=0; i<numberOfStudents; i++){
		printf("Enter name:");
		scanf("%s", &students[i].name);
		printf("Enter age:");
		scanf("%d", &students[i].age);
		printf("Enter GPA:");
		scanf("%f", &students[i].GPA);
	}
	printf("Done \n");
}

void displayStudent(int numberOfStudents, struct Student students[]){
	int i;
	for(i=0; i<numberOfStudents; i++){
		printf("students[%d]: \n", i);
		printf("%s \n", students[i].name);
		printf("%d \n", students[i].age);
		printf("%f \n \n", students[i].GPA);
	}
}

float calculateAverageGPA(int numberOfStudents, struct Student students[]){
	int i; float totalGPA;
	for(i=0; i<numberOfStudents; i++){
		totalGPA += students[i].GPA;
	}
	float average = totalGPA/numberOfStudents;
	return average;
}

void findOldestStudent(int numberOfStudents, struct Student students[]){
	int i, j;
	struct Student s;
	
	for(i=0; i<numberOfStudents; i++){
		for(j=1; j<numberOfStudents; j++){
			if(students[j].age>students[i].age){
				s=students[j];
				students[j]=students[i];
				students[i]=s;
			}
		}
	}
	
	printf("Oldest: %s with %d years old \n", students[0].name, students[0].age);

	for(i=0; i<numberOfStudents; i++){
		printf("students[%d]: \n", i);
		printf("%s \n", students[i].name);
		printf("%d \n", students[i].age);
		printf("%f \n \n", students[i].GPA);
	}
}

void sortGPA(int numberOfStudents, struct Student students[]){
	int i, j;
	struct Student s;
	
	for(i=0; i<numberOfStudents; i++){
		for(j=1; j<numberOfStudents; j++){
			if(students[j].GPA > students[i].GPA){
				s=students[j];
				students[j]=students[i];
				students[i]=s;
			}
		}
	}
	
	for(i=0; i<numberOfStudents; i++){
		printf("students[%d]: \n", i);
		printf("%s \n", students[i].name);
		printf("%d \n", students[i].age);
		printf("%f \n \n", students[i].GPA);
	}
}

void searchByName(int numberOfStudents, struct Student students[], char search[50]){
	int i;
	for(i=0; i<numberOfStudents; i++){
		if(strcmp(search,students[i].name)==0){
			printf("students[%d]: \n", i);
			printf("%s \n", students[i].name);
			printf("%d \n", students[i].age);
			printf("%f \n \n", students[i].GPA);
		}else{
			printf("Cannot find name \n");
		}
	}
}

int main(int argc, char *argv[]) {
	struct Student students[5];
	int choice, numberOfStudents;
	char searchName[50];
	
	do{
		printf("Enter choice:");
		scanf("%d", &choice);
		switch(choice){
		case 1:
			printf("Enter number of students:");
			scanf("%d", &numberOfStudents);
			students[numberOfStudents-1];
			inputStudent(numberOfStudents ,students);
			break;
		case 2:
			displayStudent(numberOfStudents, students);
			break;
		case 3:
			findOldestStudent(numberOfStudents, students);
			break;
		case 4:
			printf("Average GPA: %.2f \n", calculateAverageGPA(numberOfStudents, students));
			break;
		case 5:
			sortGPA(numberOfStudents, students);
			break;
		case 6:
			printf("Enter search: ");
			scanf("%s", &searchName);
			searchByName(numberOfStudents, students, searchName);
			break;
		default:
			break;
		}
	}while(choice >= 1 && choice <= 6);
	
	
	
	return 0;
}
