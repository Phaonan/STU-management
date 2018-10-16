# include <stdio.h>
# include <stdlib.h>
# include "stu_manage.h"
void stu_menu()
{
    int flag=1;
    system("clear");  //windows: cls  linux: clear
    printf("---Welcome Student management---\n");
    while(flag)
    {
        printf("\n-------------------\n");
        printf("1.Add a student\n");
        printf("2.Del \n");
        printf("3.Change \n");
        printf("4.Search \n");
        printf("5.Print all students info\n");
        printf("6.quit\n");
        printf("-------------------\n");

        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:stu_add();break;
            case 2:stu_del();break;
            case 3:stu_change();break;
            case 4:stu_search();break;
            case 5:print_stu_info();break;
            case 6:flag=0;break;
            default:printf("error\n");
        }
    }
}
