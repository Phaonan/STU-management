# include <stdio.h>
# include <stdlib.h>
# include "home.h"
int read_stu_file(STU stu[])  //read file to stu
{
    FILE *fp;
    int stu_num;

    if((fp = fopen("data/student.txt","r"))==NULL)
    {
        printf("Open error!\n");
        exit(1);
    }

    fseek(fp,0,SEEK_END);
    stu_num = ftell(fp)/sizeof(STU);
    fseek(fp,0,SEEK_SET);

    fread(stu,sizeof(STU),stu_num,fp);
    fclose(fp);

    return stu_num;
}

void write_stu_file(STU stu[],int num)   //write file to stu
{
    FILE *fp;
    if((fp = fopen("data/student.txt","w"))==NULL)
    {
        printf("Open error!\n");
        exit(1);
    }
    fwrite(stu,sizeof(STU),num,fp);
    fclose(fp);
}


int read_cou_file(COU cou[])  //read file to course
{
    FILE *fp;
    int cou_num;

    if((fp = fopen("data/course.txt","r"))==NULL)
    {
        printf("Open error!\n");
        exit(1);
    }

    fseek(fp,0,SEEK_END);
    cou_num = ftell(fp)/sizeof(COU);
    fseek(fp,0,SEEK_SET);

    fread(cou,sizeof(COU),cou_num,fp);
    fclose(fp);

    return cou_num;
}


void write_cou_file(COU cou[],int num)   //write file to course
{
    FILE *fp;
    if((fp = fopen("data/course.txt","w"))==NULL)
    {
        printf("Open error!\n");
        exit(1);
    }
    fwrite(cou,sizeof(COU),num,fp);
    fclose(fp);
}

