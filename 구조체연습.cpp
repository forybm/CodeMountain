#include <stdio.h>
#include <stdlib.h>

typedef struct student{
	char name[30];
	int student_id;
	char major[30];
};


int main()
{
	struct student *std;
	int num;
	int a;
	FILE *file;
	file = fopen("studentID.txt","r");
	fscanf(file,"%d",&num);
	
	std=(struct student*)malloc(sizeof(struct student)*num);
	
	for(int i=0;i<num;i++)
	{
		fscanf(file,"%s",&std[i].name);
		fscanf(file,"%d",&std[i].student_id);
		fscanf(file,"%s",&std[i].major);
	}
	
	for(int i=0;i<num;i++)
	{
		printf("%s ",std[i].name);
		printf("%d ",std[i].student_id);
		printf("%s\n",std[i].major);	
	}
		
	return 0;
}

	
	
