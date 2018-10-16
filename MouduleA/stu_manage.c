# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "home.h"
# include "rw_file.h"
# include "log.h"

void print_stu_info()    //print all students' info
{
    STU stu[N];
    int stu_num,i,j;
    stu_num = read_stu_file(stu);

    printf("\n---Students Info---\n");
    printf("ID\tName\tCourse_ID\tScore \n");
    for(i=0;i<stu_num;i++)
    {

        printf("%s \t%s \t",stu[i].id,stu[i].name);
        for(j=0;j<stu[i].cou_num;j++)
        {
            printf("%d ",stu[i].cou_list[j]);
        }
        printf("\t\t%d\n",stu[i].score);

    }
}


void stu_search()    /*search stu info*/
{

    STU stu[N];
    int stu_num;
    stu_num = read_stu_file(stu);

    /*------search---------*/

    int i,j;
    printf("---Student info---\n");
    printf("ID \tName \n");
    for(i=0;i<stu_num;i++)    //stu_num = 0
    {
        printf("%s \t%s \n",stu[i].id,stu[i].name);
    }
    printf("Input ID to see more info\n");

    char id[10];
    scanf("%s",id);
    printf("ID\tName\tCourse_ID\tScore \n");
    for(i=0;i<stu_num;i++)
    {
        if(strcmp(stu[i].id,id)==0)  //find the student
        {
            printf("%s \t%s \t",stu[i].id,stu[i].name);
            for(j=0;j<stu[i].cou_num;j++)
            {
                printf("%d ",stu[i].cou_list[j]);
            }
            printf("\t\t%d\n",stu[i].score);

            break;
        }
    }
    if(i==stu_num)
        printf("Not found\n");

}


void stu_add()      //add stu info
{
    STU stu[N];
    COU cou[N];
    int cou_num;
    int stu_num,add_num;
    stu_num = read_stu_file(stu);
    cou_num = read_cou_file(cou);

    printf("---Please input student info---\n");
    printf("Input the number of students\n");
    scanf("%d",&add_num);   //the num you want to add
    printf("ID\tName\tCourse_number\tCourse_ID\tScore \n");

    int i,j;
    char log_id[10]={0};
    /*Input student info*/
    for(i=stu_num;i<stu_num+add_num;i++)
    {
        scanf("%s %s %d",stu[i].id,stu[i].name,&stu[i].cou_num);
        strcpy(log_id,stu[i].id);
        for(j=0;j<stu[i].cou_num;j++)
        {
            scanf("%d",&stu[i].cou_list[j]);
            cou[stu[i].cou_list[j]-1].already_stu++;   //add course already_stu
        }
        scanf("%d",&stu[i].score);
    }


    /*print after add*/
    printf("---After add info---\n");
    printf("ID\tName\tCourse_ID\tScore \n");
    for(i=0;i<stu_num+add_num;i++)
    {
        printf("%s\t%s\t",stu[i].id,stu[i].name);
        for(j=0;j<stu[i].cou_num;j++)
        {
            printf("%d ",stu[i].cou_list[j]);
        }
        printf("\t\t%d\n",stu[i].score);
    }

    /*write into file*/
    write_stu_file(stu,stu_num+add_num);
    write_cou_file(cou,cou_num);

    logged("ADD","student",log_id);   //log
}


void stu_del()      //del stu
{
    STU stu[N];
    COU cou[N];
    int cou_num;
    int stu_num;
    char id[10];   //del student id
    stu_num = read_stu_file(stu);
    cou_num = read_cou_file(cou);

    int i,j;
    printf("Input ID to del\n");
    scanf("%s",id);

    char log_id[10]={0};
    strcpy(log_id,id);
    for(i=0;i<stu_num;i++)
    {
        if(strcmp(stu[i].id,id)==0)  //find the student
        {
            for(j=0;j<stu[i].cou_num;j++)
            {
                cou[stu[i].cou_list[j] - 1].already_stu--;
            }

            for(j=i;j<=stu_num-2;j++)
            {
                stu[j] = stu[j+1];
            }
            stu_num--;
            printf("DEL Success\n");
            break;
        }
    }
     if(i==stu_num+1)   //becase del one ,so stu_num+1
        printf("Not found\n");

     /*write into file*/
    write_stu_file(stu,stu_num);
    write_cou_file(cou,cou_num);

    logged("DEL","student",log_id);   //log
}


void stu_change()   //change stu
{
    STU stu[N],new_stu;
    COU cou[N];
    int cou_num;
    int stu_num;
    /*read file*/
    stu_num = read_stu_file(stu);
    cou_num = read_cou_file(cou);

    int i;
    printf("Input a new info\n");
    printf("ID\tName\tCourse_number\tCourse_ID\tScore \n");

    /*Input student info*/
    scanf("%s %s %d",new_stu.id,new_stu.name,&new_stu.cou_num);
    for(i=0;i<new_stu.cou_num;i++)
    {
        scanf("%d",&new_stu.cou_list[i]);
    }
    scanf("%d",&new_stu.score);

    char log_id[10]={0};
    strcpy(log_id,new_stu.id);

    /*change stu info*/
    for(i=0;i<stu_num;i++)
    {
        if(strcmp(new_stu.id,stu[i].id)==0)
        {
            stu[i] = new_stu;           //change
        }
    }

    /*write into file*/
    write_stu_file(stu,stu_num);
    write_cou_file(cou,cou_num);

    logged("Change","student",log_id);   //log

}



