#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct goRating{
	char *name;
	int Elo;
};
/*

goRating* makeRank(int num)
{
	goRating* rank;
	
	for(int i=0;i<num;i++)
	{
		
	}
	
	
	
	return rank;
}
*/
void swap(int *a,int *b)
{
	int temp;
	
	temp=*a;
	*a=*b;
	*b=temp;
}

int main(){
	
	struct goRating *ptr;
	int num,n;
	int what;
	int change_elo; 
	char abc[30];
	 
	FILE *file;
	file = fopen("Rank.txt","r");
	fscanf(file,"%d",&num);
	
	ptr=(struct goRating*)malloc(sizeof(struct goRating)*num);
	for(int i=0;i<num;i++)
	{
		ptr[i].name=(char*)malloc(sizeof(char)*30);
	}
	
		
	for(int i=0;i<num;i++)
	{
		fscanf(file,"%s",ptr[i].name);
		fscanf(file,"%d",&ptr[i].Elo);
	}
	
	printf("1: �ȳ�\n2: ���\n3: �̸�����\n4: Elo ����\n5: ����\n"); 
	while(1){
	
	scanf("%d",&what);
	if(what==5) {
	free(ptr);
	break;
	}switch(what)
	{
		case 1: 
				printf("\n1: �ȳ�\n2: ���\n3: �̸�����\n4: Elo ����\n5: ����\n\n"); 
				break;
		case 2: 
				for(int i=0;i<num;i++)
				{
				printf("%d : %s %d\n",i+1,ptr[i].name,ptr[i].Elo);
				}
				printf("\n1: �ȳ�\n2: ���\n3: �̸�����\n4: Elo ����\n5: ����\n\n"); 
				break;
		case 3:
				printf("������ ������ �Է��ϼ���.\n");
				scanf("%d",&n);
				printf("������ �̸��� �Է��ϼ���.\n");
				scanf("%s",abc);
				strcpy(ptr[n-1].name,abc);
				for(int i=0;i<num;i++)
				{
				printf("%d : %s %d\n",i+1,ptr[i].name,ptr[i].Elo);
				}
				printf("\n1: �ȳ�\n2: ���\n3: �̸�����\n4: Elo ����\n5: ����\n\n"); 
				break;
		case 4:
				printf("������ ������ �Է��ϼ���.\n");
				scanf("%d",&n);
				printf("������ ������ �Է��ϼ���.\n");
				scanf("%d",&change_elo);
				swap(&ptr[n-1].Elo,&change_elo);
				for(int i=0;i<num;i++)
				{
				printf("%d : %s %d\n",i+1,ptr[i].name,ptr[i].Elo);
				}
				printf("\n1: �ȳ�\n2: ���\n3: �̸�����\n4: Elo ����\n5: ����\n\n"); 
				break;
		
	}
	
	}
	return 0;
	



}
