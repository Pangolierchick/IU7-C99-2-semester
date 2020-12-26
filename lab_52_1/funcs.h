#ifndef __FUNCS_H__ 
#define __FUNCS_H__

#include <stdint.h>

#define SUCCESS                 0

#define PRECISE              0.001

#define TESTS                   0
#define FUNC_TESTS              0

#if TESTS
#pragma message "Test mode is on"
#endif


#define CMD                argv[1]
#define IN_FILE_PATH       argv[2]
#define OUT_FILE_PATH      argv[3]
#define SUBSTRING          argv[4]


#define SORT                    "sb"
#define FIND_BY_SURNAME         "fb"
#define DELETE_AVG              "db"
#if TESTS
#define SUPER_SECRET_COMMAND   "spb"
#define SECRET_INSERT_COMMAND  "sib"
#endif

#define SURNAME_LENGTH          26
#define NAME_LENGTH             11
#define NUMBER_OF_SUBJECTS       4

#define STUDENT_SIZE sizeof(student_t)

#define SWAP_STUDENTS(f, i, j) {student_t s1;\
                                         student_t s2;\
                        get_student_from_file(f, &s1, i);\
                        get_student_from_file(f, &s2, j);\
                        set_student_to_file(f, s1, j);\
                        set_student_to_file(f, s2, i);}

#define AVERAGE_GRADE(arr) ((arr[0] + arr[1] + arr[2] + arr[3]) / 4.0)



typedef uint32_t grade_t;

#if TESTS
#define PRINT_STUDENT(student) printf("%25s %15s\t | %d | %d | %d | %d |\n", student.surname,\
                                            student.name,\
                                            student.grades[0],\
                                            student.grades[1],\
                                            student.grades[2],\
                                            student.grades[3])
#else
#define PRINT_STUDENT(student) printf("%s\n%s\n%d %d %d %d\n", student.surname,\
                                            student.name,\
                                            student.grades[0],\
                                            student.grades[1],\
                                            student.grades[2],\
                                            student.grades[3])
#endif // TESTS




typedef struct student_s
{
    char surname[SURNAME_LENGTH];
    char name[NAME_LENGTH];
    grade_t grades[NUMBER_OF_SUBJECTS];
} student_t;

int get_student_from_file(FILE *f, student_t *student, int pos);
int set_student_to_file(FILE *f, student_t student, int pos);
int parse_args(int argc, char **argv);
int sort(const char *fp);
int find_by_surname(const char *fi, const char *fo, const char *needle);
int sort_students(const char *fp);
int delete_avg(const char *fp);

#endif // __FUNCS_H__ 
