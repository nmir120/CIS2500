#include "aim.h"
#include <stdlib.h>
#include <stdio.h>
void init_aim(){

	FILE *fp;
	fp = fopen("students.bin", "w");
	fclose(fp);
	fp = fopen("courses.bin", "w");
	fclose(fp);
	fp = fopen("student_course.bin", "w");
	fclose(fp);

}


void register_student(){
	struct student_struct stud;
	FILE *fp;
	int id = 1;

	fp = fopen("students.bin", "a+");

	while(!feof(fp)){
		fread(&stud, sizeof(stud), 1, fp);
		if(stud.id > id){
			id = stud.id;
		}
	}
	printf("Enter last name: ");
	fgets(stud.last_name, 64, stdin);
	printf("Enter first name: ");
	fgets(stud.first_name, 64, stdin);
	printf("Enter middle name: ");
	fgets(stud.middle_names, 64, stdin);
	printf("Enter major: ");
	fgets(stud.major, 64, stdin);
	stud.id = (id + 1);

	fwrite(&stud, sizeof(stud), 1, fp);
	fclose(fp);
}

