# include <stdio.h>
# include <stdlib.h>
# include "cou_manage.h"
void cou_menu()
{
    int flag=1;
    system("clear");
    printf("---Welcome Course management---\n");

    while(flag)
    {
        printf("\n-------------------\n");
        printf("1.Add \n");
        printf("2.Del \n");
        printf("3.Change \n");
        printf("4.Search \n");
        printf("5.Print all info\n");
        printf("6.Quit\n");
        printf("-------------------\n");

        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:cou_add();break;
            case 2:cou_del();break;
            case 3:cou_change();break;
            case 4:cou_search();break;
            case 5:print_cou_info();break;
            case 6:flag=0;break;
            default:printf("error\n");
        }
    }
}
