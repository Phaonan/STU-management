# include <stdio.h>
# include <stdlib.h>
# include "stu_menu.h"
# include "cou_menu.h"
void home()
{
    int flag=1;
    while(flag)
    {
        int choice;
        system("clear");
        printf("---Welcome---\n");
        printf("1.Student_manage\n");
        printf("2.Course_manage\n");
        printf("3.Quit\n");
        printf("-----End-----\n");


        scanf("%d",&choice);
        switch(choice)
        {
            case 1:stu_menu();break;
            case 2:cou_menu();break;
            case 3:flag=0;break;
            default:printf("Error!\n");
        }
    }
}
