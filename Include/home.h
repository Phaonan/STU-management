#ifndef HOME_H_INCLUDED
#define HOME_H_INCLUDED

# define N 10
void home();


/*student struct*/
typedef struct student_info
{
    char id[10];
    char name[10];
    int cou_num;
    int cou_list[10];
    int score;
}STU;

/*course struct*/
typedef struct course_info
{
    char id[10];
    char name[10];
    char kind;
    int time;
    int score;
    int already_stu;
    int max_num;
}COU;
#endif // HOME_H_INCLUDED
