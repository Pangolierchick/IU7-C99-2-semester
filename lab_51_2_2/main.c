#include <stdio.h>
#include "funcs.h"
#include "error.h"

#define BAD_FILE_PATH 1

int main(int argc, char **argv)
{  
    char fpath[PATH_LEN];

    int parse_status = parse_args(argc, argv, fpath);

    if (parse_status)
    {
        // PRINT_ERROR(parse_status);
        return parse_status;
    }

    FILE *file = fopen(fpath, "r");

    if (file == NULL)
    {
        // PRINT_ERROR(INVALID_PATH);
        return BAD_FILE_PATH;
    }

    int len;
    double avg;
    double disp;

    int file_avg_status = file_average(file, &avg, &len);

    if (file_avg_status)
    {
        // PRINT_ERROR(file_avg_status);
        return file_avg_status;
    }

    int file_disp_status = file_dispersion(file, avg, &disp, len);

    if (file_disp_status)
    {
        // PRINT_ERROR(file_disp_status);
        return file_disp_status;
    }

    if (fclose(file))
        return FILE_READING_FAILED;

    printf("%lf\n", disp);
    return SUCCESS;
}
