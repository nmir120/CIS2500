#ifndef AIM_H
#define AIM_H

struct student_struct {
     char last_name[64];
     char first_name[64];
     char middle_names[64];
     int id;
     char major[64];
};

struct course_struct {
     char code[10];
     char term[6];
     char title[128];
     char instructor[64];
};

struct student_course_struct {
     int student_id;
     char course_code[10];
     char term[6];
     char registration[4];
     int grade;
};

void init_aim();

void register_student();

#endif 
