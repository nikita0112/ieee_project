#include<stdio.h>
#include<conio.h>
#include<string.h>
struct contact{
char name[50];
unsigned long long phno;
char add[50];
};
void appenddata()
{
FILE*fp;
struct contact obj;
fp=fopen("phonebook1.txt","a");
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
	fp=fopen("phonebook1.txt","r");
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
	fp=fopen("phonebook1.txt","r");
	printf("\n\n\nEnter the name to be searched : ");
	scanf("%s",&name);
	while(!feof(fp))
	{
		fscanf(fp,"%20s %30llu %20s",&obj.name,&obj.phno,&obj.add);
		if(strcmp(obj.name,name)==0)
		{
			printf("\nName : %s",obj.name);
			printf("\nPhone no. : %llu",obj.phno);
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
	fp=fopen("phonebook1.txt","r");
	printf("\n\n\nEnter the no to be searched : ");
	scanf("%llu",&n);
	while(!feof(fp))
	{
		fscanf(fp,"%20s %30llu %20s",&obj.name,&obj.phno,&obj.add);
		if(obj.phno==n)
		{
			printf("\nName : %s",obj.name);
			printf("\nPhone no. : %llu",obj.phno);
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
	char name[50];
	int temp=0,count=0;
	fp=fopen("phonebook1.txt","r+");
	printf("\n\n\nEnter the name to be searched : ");
	scanf("%s",&name);
	while(!feof(fp))
	{
		count++;
		fscanf(fp,"%20s %30llu %20s",&obj.name,&obj.phno,&obj.add);
		if(strcmp(obj.name,name)==0)
		{
			temp=1;
			break;
		}
	}
	if(temp==0)
	printf("\nNo such contact found!!!!");
	else
	{
		int location=(count-1)*72;
		printf("\nENter the new phone no.\t");
		scanf("%llu",&pno);
		obj.phno=pno;
		fseek(fp,location,SEEK_SET);
		fprintf(fp,"%20s %30llu %20s",obj.name,obj.phno,obj.add);
	}
	fclose(fp);
}

void del()
{
	FILE*fp;
	struct contact obj;
	unsigned long long int pno;
	char name[50];
	int temp=0,count=0;
	fp=fopen("phonebook1.txt","r+");
	printf("\n\n\nEnter the name to be searched : ");
	scanf("%s",&name);
	while(!feof(fp))
	{
		count++;
		fscanf(fp,"%20s %30llu %20s",&obj.name,&obj.phno,&obj.add);
		if(strcmp(obj.name,name)==0)
		{
			temp=1;
			break;
		}
	}
	if(temp==0)
	printf("\nNo such contact found!!!!");
	else
	{
		int location=(count-1)*72;
		int location1=(count)*72;
		fseek(fp,location,SEEK_SET);
		long int i=ftell(fp);
		while(i!=location1)
		{
		    i++;

			fprintf(fp," ");

	    }
	}
	fclose(fp);
}
main()
{
	int ch;
	char c='y';
	printf("\t\t\tPHONEBOOK DIRECTORY\n");
	printf("1.Append records\n");
	printf("2.Search\n");
	printf("3.Display all records\n");
	printf("4.Exit\n");
	do
	{
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : appenddata();
			         break;
			case 2 : search1();
			         break;
			case 3 : showalldata();
			         break;
			case 4 : c='n';
			         break;
			case 5 : del();
			         break;
			default : printf("WRONG CHOICE!!!!\n");
		}
	}
	while(c=='y');
	printf("YOU HAVE EXITED!!");
}
