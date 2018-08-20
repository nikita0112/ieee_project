#include<stdio.h>
#include<conio.h>
#include<string.h>
struct contact{
char name[50];
unsigned long long int phno;
char add[50];
};
void appenddata()
{
FILE*fp;
struct contact obj;
fp=fopen("phonebook.txt","a");
printf("\n\n\t\t\tAdd New Record\n");
printf("Enter Name : ");
scanf("%s",&obj.name);
printf("Enter Phone no. : ");
scanf("%llu",&obj.phno);
printf("Enter Address : ");
scanf("%s",&obj.add);
fprintf(fp,"%20s %30llu %20s",obj.name,obj.phno,obj.add);
fclose(fp);
}
void showalldata()
{
	FILE*fp;
	struct contact obj;
	fp=fopen("phonebook.txt","r");
	printf("\n\n\t\t\tAll Records\n");
	while(!feof(fp))
	{
		fscanf(fp,"%20s %30llu %20s",&obj.name,&obj.phno,&obj.add);
		printf("%20s %30llu %20s\n",obj.name,obj.phno,obj.add);
	}
	fclose(fp);
}
void search()
{
	FILE*fp;
	struct contact obj;
	char name[50];
	int temp=0;
	fp=fopen("phonebook.txt","r");
	printf("\n\n\nEnter the name to be searched : ");
	scanf("%s",&name);
	while(!feof(fp))
	{
		fscanf(fp,"%20s %30llu %20s",&obj.name,&obj.phno,&obj.add);
		if(strcmpi(obj.name,name)==0)
		{
			printf("\nName : %s",obj.name);
			printf("\nPhone no. : %llu",obj.phno);
			printf("\nAddress : %s",obj.add);
			temp++;
		}
	}
	if(temp==0)
	printf("\nNo such contact found!!!!");
	else
	printf("\t\t\t%d contacts found\n",temp);
	fclose(fp);
}
void search1()
{
	FILE*fp;
	struct contact obj;
	unsigned long long int n;
	int temp=0;
	fp=fopen("phonebook.txt","r");
	printf("\n\n\nEnter the no to be searched : ");
	scanf("%llu",&n);
	while(!feof(fp))
	{
		fscanf(fp,"%20s %30llu %20s",&obj.name,&obj.phno,&obj.add);
		if(obj.phno==n)
		{
			printf("\n\nName : %s",obj.name);
			printf("\nPhone no. : %llu",obj.phno);
			printf("\nAddress : %s",obj.add);
			temp++;
		}
	}
	if(temp==0)
	printf("\nNo such contact found!!!!");
	else
	printf("\t\t\t%d contacts found\n",temp);
	fclose(fp);
}
void update()
{
	FILE*fp;
	struct contact obj;
	unsigned long long int pno;
	long int location;
	char name[50];
	int temp=0,count=0;
	fp=fopen("phonebook.txt","r+");
	printf("\n\n\nEnter the name to be updated : ");
	scanf("%s",&name);
	while(!feof(fp))
	{
		count++;
		fscanf(fp,"%20s %30llu %20s",&obj.name,&obj.phno,&obj.add);
		if(strcmpi(obj.name,name)==0)
		{
			temp=1;
			break;
		}
	}
	if(temp==0)
	printf("\nNo such contact found!!!!");
	else
	{
		location=(count-1)*72;
		printf("\nENter the new phone no.\t");
		scanf("%llu",&pno);
		obj.phno=pno;
		fseek(fp,location,SEEK_SET);
		fprintf(fp,"%20s %30llu %20s",obj.name,obj.phno,obj.add);
	}
	fclose(fp);
}
main()
{
	int ch;
	char c='y';
	do
	{
	    printf("\t\t\tPHONEBOOK DIRECTORY\n");
	    printf("1.Append records\n");
	    printf("2.Search by name\n");
	    printf("3.Search by phone no.\n");
        printf("4.Display all records\n");
	    printf("5.Update a record\n");
	    printf("6.Exit\n");
		printf("\n\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : appenddata();
			         break;
			case 2 : search();
			         break;
			case 3 : search1();
			         break;
			case 4 : showalldata();
			         break;
			case 5 : update();
			         break;
			case 6 : c='n';
			         break;
			default : printf("WRONG CHOICE!!!!\n");
		}
	}
	while(c=='y');
	printf("YOU HAVE EXITED!!");
}
