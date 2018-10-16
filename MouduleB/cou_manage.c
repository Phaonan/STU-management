# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "home.h"
# include "rw_file.h"
# include "log.h"

void print_cou_info()    //print all course' info
{
    COU cou[N];
    int cou_num,i;
    cou_num = read_cou_file(cou);

    printf("---Your input course info---\n");
    printf("ID\tName\tkind\ttime\tScore\talready_stu\tmax_num\n");
    for(i=0;i<cou_num;i++)
    {
        printf("%s\t%s\t%c\t%d\t%d\t%d\t\t%d\n",cou[i].id,cou[i].name,cou[i].kind,
              cou[i].time,cou[i].score,cou[i].already_stu,cou[i].max_num);
    }
}



void cou_search()    /*search course info*/
{

    COU cou[N];
    int cou_num;
    cou_num = read_cou_file(cou);

    /*------search---------*/

    int i;
    printf("---Course info---\n");
    printf("ID \tName \n");
    for(i=0;i<cou_num;i++)    //stu_num = 0
    {
        printf("%s \t%s \n",cou[i].id,cou[i].name);
    }
    printf("Input ID to see more info\n");

    char id[10];
    scanf("%s",id);
    for(i=0;i<cou_num;i++)
    {
        if(strcmp(cou[i].id,id)==0)  //find the course
        {
            printf("ID\tName\tkind\ttime\tScore\talready_stu\tmax_num\n");

            printf("%s\t%s\t%c\t%d\t%d\t%d\t\t%d\n",cou[i].id,cou[i].name,cou[i].kind,
                cou[i].time,cou[i].score,cou[i].already_stu,cou[i].max_num);

            break;
        }
    }
    if(i==cou_num)
        printf("Not found\n");

}



void cou_add()      //add stu info
{
    STU stu[N];
    COU cou[N];
    int cou_num;
    int stu_num,add_num;
    stu_num = read_stu_file(stu);
    cou_num = read_cou_file(cou);

    printf("---Please input course info---\n");
    printf("Input the number of courses\n");
    scanf("%d",&add_num);   //the num you want to add
    printf("ID\tName\tkind\ttime\tScore\talready_stu\tmax_num\n");

    int i;
     char log_id[10]={0};
    /*Input course info*/
    for(i=cou_num;i<cou_num+add_num;i++)
    {
         scanf("%s %s %c %d %d %d %d",cou[i].id,cou[i].name,&cou[i].kind,
              &cou[i].time,&cou[i].score,&cou[i].already_stu,&cou[i].max_num);
         strcpy(log_id,cou[i].id);

    }


    /*print after add*/
    printf("---After add info---\n");
    printf("ID\tName\tkind\ttime\tScore\talready_stu\tmax_num\n");
    for(i=0;i<cou_num+add_num;i++)
    {
        printf("%s\t%s\t%c\t%d\t%d\t%d\t\t%d\n",cou[i].id,cou[i].name,cou[i].kind,
              cou[i].time,cou[i].score,cou[i].already_stu,cou[i].max_num);
    }

    /*write into file*/
    //write_stu_file(stu,stu_num+add_num);
    write_cou_file(cou,cou_num+add_num);

    logged("ADD","Course",log_id);   //log
}


void cou_del()      //del course
{
    STU stu[N];
    COU cou[N];
    int cou_num;
    int stu_num;
    char id[10];   //del student id
    stu_num = read_stu_file(stu);
    cou_num = read_cou_file(cou);

    int i,j;
    printf("Input Course ID to del\n");
    scanf("%s",id);
    /*log*/
    char log_id[10]={0};
    strcpy(log_id,id);

    for(i=0;i<cou_num;i++)
    {
        if(strcmp(cou[i].id,id)==0)  //find the course
        {

            for(j=i;j<=cou_num-2;j++)
            {
                cou[j] = cou[j+1];
            }
            cou_num--;
            printf("DEL Success\n");
            break;
        }
    }
     if(i==cou_num+1)   //becase del one ,so stu_num+1
        printf("Not found\n");

     /*write into file*/
    write_stu_file(stu,stu_num);
    write_cou_file(cou,cou_num);

    logged("DEL","Course",log_id);   //log

}



void cou_change()   //change course
{
    STU stu[N];
    COU cou[N],new_cou;
    int cou_num;
    int stu_num;
    /*read file*/
    stu_num = read_stu_file(stu);
    cou_num = read_cou_file(cou);

    int i;
    printf("Input a new info\n");
    printf("ID\tName\tkind\ttime\tScore\talready_stu\tmax_num\n");

    /*Input course info*/
    scanf("%s %s %c %d %d %d %d",new_cou.id,new_cou.name,&new_cou.kind,
              &new_cou.time,&new_cou.score,&new_cou.already_stu,&new_cou.max_num);

    char log_id[10]={0};
    strcpy(log_id,new_cou.id);

    /*change stu info*/
    for(i=0;i<cou_num;i++)
    {
        if(strcmp(new_cou.id,cou[i].id)==0)
        {
            cou[i] = new_cou;           //change
            printf("Change succes\n");
        }
    }
    if(i==cou_num)  printf("Not found! Change faild\n");

    /*write into file*/
    write_stu_file(stu,stu_num);
    write_cou_file(cou,cou_num);

    logged("Change","Course",log_id);   //log

}
