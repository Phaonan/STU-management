# include <stdio.h>
# include <stdlib.h>
# include "home.h"
void input_stu()
{
    int stu_num;
    STU stu[N],stu2[N];
    system("clear");   //clear the screen
    printf("---Please input student info---\n");
    printf("Input the number of students\n");
    scanf("%d",&stu_num);
    printf("ID\tName\tCourse_number\tCourse_ID\tScore \n");

    int i,j;
    /*Input student info*/
    for(i=0;i<stu_num;i++)
    {
        scanf("%s %s %d",stu[i].id,stu[i].name,&stu[i].cou_num);
        for(j=0;j<stu[i].cou_num;j++)
        {
            scanf("%d",&stu[i].cou_list[j]);
        }
        scanf("%d",&stu[i].score);
    }

    FILE *fp;
    /*write info to file*/
    if((fp = fopen("data/student.txt","w"))==NULL)
    {
        printf("Open file error!\n");
        exit(1);
    }
    fwrite(stu,sizeof(STU),stu_num,fp);
    fclose(fp);

    /*test write file right*/
    if((fp = fopen("data/student.txt","r"))==NULL)
    {
        printf("Open file error!\n");
        exit(1);
    }
    /*jisuan wenjian you duoda*/
    //int stu_num;
    fseek(fp,0,SEEK_END);
    stu_num = ftell(fp)/sizeof(STU);
    fseek(fp,0,SEEK_SET);

    fread(stu2,sizeof(STU),stu_num,fp);
    fclose(fp);


    printf("---Your input info---\n");
    printf("ID\tName\tCourse_ID\tScore \n");
    for(i=0;i<stu_num;i++)
    {
        printf("%s\t%s\t",stu2[i].id,stu2[i].name);
        for(j=0;j<stu2[i].cou_num;j++)
        {
            printf("%d ",stu2[i].cou_list[j]);
        }
        printf("\t\t%d\n",stu2[i].score);
    }
}

void input_cou()
{
    int cou_num;
    COU cou[N],cou2[N];
    printf("---Please input course info---\n");
    printf("Input the number of course\n");
    scanf("%d",&cou_num);
    printf("ID\tName\tkind\ttime\tScore\talready_stu\tmax_num\n");

    int i;
    for(i=0;i<cou_num;i++)
    {
        scanf("%s %s %c %d %d %d %d",cou[i].id,cou[i].name,&cou[i].kind,
              &cou[i].time,&cou[i].score,&cou[i].already_stu,&cou[i].max_num);
    }

    FILE *fp;
    /*write info to file*/
    if((fp = fopen("data/course.txt","w"))==NULL)
    {
        printf("Open file error!\n");
        exit(1);
    }
    fwrite(cou,sizeof(COU),cou_num,fp);
    fclose(fp);

    /*test write file right*/
    if((fp = fopen("data/course.txt","r"))==NULL)
    {
        printf("Open file error!\n");
        exit(1);
    }
    fseek(fp,0,SEEK_END);
    cou_num = ftell(fp)/sizeof(COU);
    fseek(fp,0,SEEK_SET);

    fread(cou2,sizeof(COU),cou_num,fp);
    fclose(fp);

    printf("---Your input course info---\n");
    printf("ID\tName\tkind\ttime\tScore\talready_stu\tmax_num\n");
    for(i=0;i<cou_num;i++)
    {
        printf("%s\t%s\t%c\t%d\t%d\t%d\t\t%d\n",cou[i].id,cou[i].name,cou[i].kind,
              cou[i].time,cou[i].score,cou[i].already_stu,cou[i].max_num);
    }

}

void myfile()
{
    printf("---Welcome choose file---\n");
    printf("1.Read info from file\n");
    printf("2.Input info from keyboard\n");

    int choice;
    /*judge Read file or Input by keyboard*/
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("Read info from file\n");break;
        case 2:input_stu();input_cou();break;
        default:printf("Error\n");
    }

    printf("Press a key to continue\n");
    getchar();
    getchar();
}
