#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>

#include "funcs.h"
#include "error.h"

static int get_file_len(FILE *f)
{
    rewind(f);
    fseek(f, 0, SEEK_END);
    
    int res = ftell(f);
    rewind(f);
    
    return res;
}

static int print_whole_file(FILE *f)
{
    if (f == NULL)
        return INVALID_PATH;
    rewind(f);

    int i = 0;
    student_t s = { 0 };

    #if TESTS
    puts("\t\t  SURNAME\t    NAME\t\tGRADES");
    #endif

    while (!get_student_from_file(f, &s, i++))
        PRINT_STUDENT(s);

    rewind(f);

    return SUCCESS;
}

#if TESTS
static int insert_student(const char *fp)
{
    FILE *f = fopen(fp, "r+b");

    if (f == NULL)
        return INVALID_PATH;

    int len = get_file_len(f) / STUDENT_SIZE;

    student_t s;

    puts("Input surname: ");
    scanf("%s", s.surname);
    puts("Input name: ");
    scanf("%s", s.name);
    puts("Input four grades: ");
    scanf("%ud", s.grades);
    scanf("%ud", s.grades + 1);
    scanf("%ud", s.grades + 2);
    scanf("%ud", s.grades + 3);

    PRINT_STUDENT(s);

    set_student_to_file(f, s, len);

    fclose(f);

    return SUPER_SECRET_SUCCESSED;
}

static void print_help(void)
{
    puts("Program made by Kirill R.");
    puts("sb FILE_PATH - sorting file by surname and name");
    puts("fb FILE_IN_PATH FILE_OUT_PATH NEEDLE - find surnames that starts with");
    puts("db FILE_PATH - delete students by their average points");
}
#endif // TESTS 

static int average_points(FILE *f, double *average)
{
    rewind(f);

    *average = 0;
    student_t student;
    int i = 0;

    while (!get_student_from_file(f, &student, i))
    {
        *average += AVERAGE_GRADE(student.grades);
        i++;
    }

    if (!i)
        return EMPTY_FILE;


    *average /= (double) i;

    rewind(f);

    return SUCCESS;
}

int get_student_from_file(FILE *f, student_t *student, int pos)
{
    int offset = pos * STUDENT_SIZE;
    fseek(f, offset, SEEK_SET);
    return fread(student, STUDENT_SIZE, 1, f) != 1;
}

int set_student_to_file(FILE *f, student_t student, int pos)
{
    int offset = pos * STUDENT_SIZE;
    fseek(f, offset, SEEK_SET);

    return fwrite(&student, STUDENT_SIZE, 1, f) != 1;
}

int parse_args(int argc, char **argv)
{
    int res = UNKNOWN_CMD;

    if (argc == 3)
    {
        if (!strcmp(CMD, SORT))
            res = sort_students(IN_FILE_PATH);
        else if (!strcmp(CMD, DELETE_AVG))
        {
            res = delete_avg(IN_FILE_PATH);
        }
        #if TESTS
        else if (!strcmp(CMD, SUPER_SECRET_COMMAND))
        {
            puts("SUPER SECRET COMMAND INITIALISING");
            FILE *f = fopen(IN_FILE_PATH, "rb");
            res = print_whole_file(f);
            fclose(f);
        }
        else if (!strcmp(CMD, SECRET_INSERT_COMMAND))
            res = insert_student(IN_FILE_PATH);
        #endif // TESTS
    }
    else if (argc == 5)
    {
        if (!strcmp(CMD, FIND_BY_SURNAME))
            res = find_by_surname(IN_FILE_PATH, OUT_FILE_PATH, SUBSTRING);
    }

    #if TESTS
    if (res == UNKNOWN_CMD)
        print_help();
    #endif

    return res;
}

int find_by_surname(const char *fi, const char *fo, const char *needle)
{
    FILE *pfi = fopen(fi, "rb");
    FILE *pfo = fopen(fo, "wb");

    int needle_len = strlen(needle);

    if (pfi == NULL || pfo == NULL)
        return INVALID_PATH;

    int len = get_file_len(pfi);

    if (len % STUDENT_SIZE || !len)
        return EMPTY_FILE;

    student_t student;

    int i = 0;
    int found_stud = 0;

    while (!get_student_from_file(pfi, &student, i++))
        if (!strncmp(student.surname, needle, needle_len))
        {
            #if TESTS
            PRINT_STUDENT(student);
            #endif
            set_student_to_file(pfo, student, found_stud++);
        }
    

    fclose(pfo);
    fclose(pfi);

    return found_stud == 0;
}

int delete_avg(const char *fp)
{
    FILE *f = fopen(fp, "r+b");

    if (f == NULL)
        return INVALID_PATH;

    double avg = 0;
    if (average_points(f, &avg))
        return EMPTY_FILE;

    int len = get_file_len(f);

    if (len % STUDENT_SIZE)
        return EMPTY_FILE;
    
    len /= STUDENT_SIZE;

    int j = 0;
    for (int i = 0; i < len; i++)
    {
        student_t st;
        get_student_from_file(f, &st, i);
        
        if (AVERAGE_GRADE(st.grades) > avg || (fabs((AVERAGE_GRADE(st.grades)) - avg) < PRECISE))
        {
            // PRINT_STUDENT(st);
            set_student_to_file(f, st, j++);
        }
    }

    ftruncate(fileno(f), j * STUDENT_SIZE);

    return fclose(f) == EOF;
}


int sort_students(const char *fp)
{
    FILE *f = fopen(fp, "r+b");

    if (f == NULL)
        return INVALID_PATH;

    int len = get_file_len(f);

    if (len % STUDENT_SIZE || !len)
        return EMPTY_FILE;
    
    len /= STUDENT_SIZE;

    for (int i = 0; i < len; i++)
        for (int j = len - 1; j > i; j--)
        {
            student_t s1;
            student_t s2;
            
            get_student_from_file(f, &s1, j - 1);
            get_student_from_file(f, &s2, j);
            
            int sn_cmp = strcmp(s1.surname, s2.surname);
            
            if (sn_cmp > 0)
            {
                SWAP_STUDENTS(f, j - 1, j);
            }
            else if (!sn_cmp)
            {
                int n_cmp = strcmp(s1.name, s2.name);
                
                if (n_cmp > 0)
                    SWAP_STUDENTS(f, j, j - 1);
            }
        }

    print_whole_file(f);

    return fclose(f) == EOF;
}