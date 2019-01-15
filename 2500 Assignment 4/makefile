add: add.c aim.o aim.h
	gcc -Wall -ansi -pedantic add.c aim.o -o add

class_list: class_list.c  aim.o aim.h
	gcc -Wall -ansi -pedantic class_list.c aim.o -o class_list

class_schedule: class_schedule.c  aim.o aim.h
	gcc -Wall -ansi -pedantic class_schedule.c aim.o -o class_schedule

grade: grade.c aim.o aim.h
	gcc -Wall -ansi -pedantic grade.c aim.o -o grade

init_aim: init_aim.c aim.o aim.h
	gcc -Wall -ansi -pedantic init_aim.c aim.o -o init_aim

register: register.c aim.o aim.h
	gcc -Wall -ansi -pedantic register.c aim.o -o register

report: report.c aim.o aim.h
	gcc -Wall -ansi -pedantic report.c aim.o -o report

schedule: schedule.c aim.o aim.h
	gcc -Wall -ansi -pedantic schedule.c aim.o -o schedule

sort: sort.c aim.o aim.h
	gcc -Wall -ansi -pedantic sort.c aim.o -o sort

aim.o: aim.c aim.h
	gcc -Wall -ansi -pedantic -c aim.c -o aim.o

all: add class_list class_schedule grade init_aim register report schedule sort aim.o

