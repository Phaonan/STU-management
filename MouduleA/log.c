# include <stdio.h>
# include <stdlib.h>
# include <time.h>
void logged(char op[10],char p[10],char id[10])   //op = operate, p = object , id
{
    time_t t;
	struct tm *timeinfo;  //½á¹¹Ìå
	time(&t);
	timeinfo = localtime(&t);



    FILE *fp;
    if((fp = fopen("data/log.txt","a"))==NULL)
    {
        printf("Open error!\n");
        exit(1);
    }
    fprintf(fp,"%s%s %s ID : %s \n\n",asctime(timeinfo),op,p,id);
    fclose(fp);
}
