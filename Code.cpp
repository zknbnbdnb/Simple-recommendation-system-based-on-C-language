#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#define maxid 100000
//ÿ���ֿ��к����������г�Ҫ�õĺ��� 
//void feature1()
//void feature2()
//void feature3()
//void feature4()
//void feature5()
void getmenu() /*��ʾ�˵�ѡ��*/
{
    printf("             *******************���˵�******************\n\n");    
	printf("             *           ��ӭ�����Ӱ�Ƽ�ϵͳ          *\n\n");    
	printf("             *         1����ѯ�û�������ĳ��Ӱ������   *\n\n");    
	printf("             *         2����ѯ�û������ĵ�Ӱ           *\n\n");    
	printf("             *         3����ѯ��Ӱ����Щ�û�����       *\n\n");    
	printf("             *         4�����Ի��Ƽ���Ӱ               *\n\n");
	printf("             *         5���ؼ���������Ӱ               *\n\n");
    printf("             *******************************************\n\n"); 
}   
/*******************************************************************************************************************************/
	struct m_check
    {
	
    int user_id;
    int moive_nameid;
    float userpoint;

    }USERS[maxid];
    
    
void feature1()
{

	long i = 0; 
    FILE *fp;
    if((fp = fopen("user_ratings.csv", "r"))==NULL)
    {
    	printf("�޷����ļ�\n");
		exit(1); 
	}
    while(!feof(fp))
    {
    	 
    	fscanf(fp,"%d,%d,%f\n",&USERS[i].user_id,&USERS[i].moive_nameid,&USERS[i].userpoint); 
  		i++; 
    }
    printf("\n����������û�Id�����֣��͵�Ӱid��\n");
    printf("\n����-1�˳�����\n"); 
    int Nameid;
	int movieid;
	
	int Mname[5];	
	    printf("\n�û�ID     ��ӰID\n");
		
  	    loop : while(scanf("%d %d",&Nameid,&movieid) == 2)
		{ 
		    if(Nameid < 0||movieid < 0)
		    {
		    	system("cls");
		    	break;
			}
			if(Nameid>USERS[i-1].user_id)
			{
				//system("cls");
				printf("���û������ڡ�\n");
				printf("����������.\n");
				printf("\n����-1�˳�����\n");
				printf("\n�û�ID     ��ӰID\n");
				goto loop; 
			}
			if(movieid>9125)
			{
				//system("cls");
				printf("�õ�Ӱ�����ڡ�\n");
				printf("����������.\n"); 
				printf("\n����-1�˳�����\n");
				printf("\n�û�ID     ��ӰID\n");
				goto loop;
			}
			for(int a = 0;a<i;a++)
			{
				if(Nameid == USERS[a].user_id)
				{ 
					if(movieid == USERS[a].moive_nameid)
					{
						printf("\n�������������� : %.1f\n",USERS[a].userpoint);
						printf("\n����������û�Id�����֣��͵�Ӱid��\n");
						printf("\n����-1�˳�����\n");
						printf("\n�û�ID     ��ӰID\n");
						break;
					}
				}
				if(USERS[a].user_id!=USERS[a+1].user_id)
				{
					if(Nameid == USERS[a].user_id)
					{
						//system("cls");
						printf("\n���û���û�����ⲿ��Ӱ�����������Ӱ���û���id\n");
						printf("\n����-1�˳�����\n");
						printf("\n");
						printf("\n�û�ID     ��ӰID\n");
						break;
					}
					else
					{
						continue;
					}
				}	 
			}
		}
	}
/*******************************************************************************************************************************/


/*******************************************************************************************************************************/

struct Mcheck
	{
    char user_id[5];
    char moive_nameid[5];
    char userpoint[5];	
    }user1[maxid];

	struct m_n
	{
	char num[5];
	char name[1000];
	}movie[maxid];

void feature2()
{
	
	long i = 0;
		


	 
    FILE *fp;
    if((fp = fopen("user_ratings.csv", "r"))==NULL)
    {
    	printf("�޷����ļ�\n");
		exit(1); 
	}
    while(!feof(fp))
    {
    	 
    	fscanf(fp,"%[^,],%[^,],%[^\r\n]\n",&user1[i].user_id,&user1[i].moive_nameid,&user1[i].userpoint); 
  		i++; 
    }
    int j = i;
   
   
    i = 0;
    if((fp = fopen("movie_names.csv", "r"))==NULL)
    {
    	printf("�޷����ļ�\n");
		exit(1); 
	}
    while(!feof(fp))
    {
    	fscanf(fp, "%[^,],%[^,],,,,,,,\r\n", movie[i].num, movie[i].name); 
  		i++; 
    }
    printf("\n����������û�Id�����֣�(����-1�˳�����)��");
    //printf("\n����-1�˳�����\n");
    char Nameid[5];
	int moiveid;
	char mname[5];	
	int count = 0;
		while(scanf("%s",Nameid) ==1)
		{ 
            if(atoi(Nameid) < 0)
            {
            	system("cls");
		    	break;
			}
			if(atoi(Nameid)>atoi(user1[j-1].user_id))
				{
					printf("\n���û������ڡ�\n");
					printf("\n����������.\n");
					printf("\n����-1�˳�����\n"); 
			    }
			    for(int a =0;a<j;a++)
				{	
					if(atoi(Nameid) == atoi(user1[a].user_id))
					{ 
						strcpy(mname,user1[a].moive_nameid);
						for(int a =0;a<i;a++)
	                    {
	                       
	                       if(atoi(mname) == atoi(movie[a].num))
	                        { 
    	                        printf("�����������ĵ�Ӱ���� : %s\n",movie[a].name);
										
	                        }	 
	                    }                      	
					}	 
				}
				printf("\n");
				printf("\n����������û�Id�����֣�(����-1�˳�����)��");
				
		}
	
}

/*******************************************************************************************************************************/


/*******************************************************************************************************************************/

struct mCheck
	{
	int user_id;
	int moive_nameid;
	float userpoint;
	}user2[maxid];

void feature3()
{
	
	long i = 0; 
    FILE *fp;
    if((fp = fopen("user_ratings.csv", "r"))==NULL)
    {
    	printf("�޷����ļ�\n");
		exit(1); 
	}
    while(!feof(fp))
    {
    	 
    	fscanf(fp,"%d,%d,%f\n",&user2[i].user_id,&user2[i].moive_nameid,&user2[i].userpoint); 
  		i++; 
   }
   printf("��������ĵ�ӰId�����֣�(����-1�˳�����)��");
   //printf("\n����-1�˳�����\n");
    int Nameid;
	int movieid;
	int Mname[5];	
	int count = 0;
			
		while(scanf("%d",&movieid) ==1)
		{ 
		    if(movieid < 0)
		    {
		    	system("cls");
		    	break;
			}
			    if(movieid>9125)
				{
					printf("\n�õ�Ӱ�����ڡ�\n");
					printf("\n����������.\n");
					printf("\n����-1�˳�����\n"); 
				}
				
				int a ;
			    for(a =0;a<i;a++)
				{
					if(movieid == user2[a].moive_nameid)
					{
						printf("����û����������Ӱ : %d\n",user2[a].user_id);
						count++; 
					}
					if(count == 0&&a == i-1)
					{
						printf("\n�õ�Ӱû�˿�����\n");
					    //printf("\n����������.\n");
					    printf("\n����-1�˳�����\n");
					}
				}
				
				
			printf("\n��������ĵ�ӰId�����֣�(����-1�˳�����)��");
		
		}
}

/*******************************************************************************************************************************/


/*******************************************************************************************************************************/

struct MOVIE
{
	int movieID;//��Ӱid			                         
	char movieName[50];		//��Ӱ���� 
	char movietype[200][50];//��Ӱ����	
	float avgRate;		//��Ӱƽ����	
	int typeCount;//���� 
};

struct MOVITYPEERATE
{
	char movieType[50];	//��Ӱ��һ������ 
	float rate;			//��Ӱ�������� 
	int movieIdCount;	//���� 
	int* pMovieID;		//һ�����������Եĵ�Ӱ 
};
struct  USER
{
	int userID;			//�û�id					
	MOVITYPEERATE movieTypeRateList[2000];	//ĳ�����͵ĵ�Ӱ���� 
	int typeCount;	//���� 
};


MOVIE movieList[10000]; 
USER g_userList[10000];

int movieCount = 0;//����ȫ�ֱ��� 
int userCount = 0;


USER* FindUser(USER* userList, int userID)
{
	for (int i = 0; i < userCount; i++)
	{
		if (userList[i].userID == userID)
		{
			return &userList[i];
		}
	}	 
	return NULL;
}


MOVIE* FindMovie(MOVIE* movieList, int movieID)
{
	for (int i = 0; i < movieCount; i++)
	{
		if (movieList[i].movieID == movieID)
		{
		    return &movieList[i];	
		}
	}	 
	return NULL;
}



int FindTypeRate(MOVITYPEERATE* list, char* movieType)
{
	for (int i = 0;; i++)
	{
		if (strcmp(list[i].movieType, "") == 0)
		{
		    break; //���ַ������� 
		}
		if (strcmp(list[i].movieType, movieType) == 0) 
		{
			return i;//��������i 
		}
	}
	return -1;//û��������-1 
}


void feature4()
{
	
	FILE* fp = fopen("movie_names.csv", "rb");//����Ӱ�����ļ���rb�Զ����Ʒ�ʽ�� 
	if (fp == NULL)
	{
	    printf("��ȡ�ļ�ʧ��\n");   
	}

	while (fscanf(fp, "%d,%[^,],,,,,,,\r\n", &movieList[movieCount].movieID, movieList[movieCount].movieName) != EOF)//%[^,]ƥ�䣬�������������� 
	{
		movieCount++;
	}
	fclose(fp);

	
	fp = fopen("movie_genres.csv", "rb"); //����Ӱ�����ļ�
	if (fp == NULL)
	{
	    printf("��ȡ�ļ�ʧ��\n");   
	}
	int movieID;
	char movieTypeStr[100];
	movieCount = 0;//���³�ʼ�� 
	while (fscanf(fp, "%d,%[^\r\n]", &movieID, movieTypeStr) != EOF)// [^\r\n]ƥ�任����������������   
	{
		char* movieType = strtok(movieTypeStr, "|");//���õ��Ĵ������ַ����ָ�ɵ��������ַ��� 
		for (int i = 0;; i++)
		{
			if (movieType == NULL)
			{
			    break;
			}
			strcpy(movieList[movieCount].movietype[i], movieType);
			movieList[movieCount].typeCount++;//���е�Ӱ���������͵��ܺ� 
			movieType = strtok(NULL, "|");
		}
		movieCount++;
	}

	
	fp = fopen("average_ratings.csv", "rb");//����Ӱƽ�����ļ�
	if (fp == NULL)
	{
	    printf("��ȡ�ļ�ʧ��\n");   
	}
	movieCount = 0;
	char rateStr[10];
	while (fscanf(fp, "%d,%[^,],,,,\r\n", &movieID, rateStr) != EOF)
	{
		movieList[movieCount++].avgRate = atof(rateStr);
	}	
	movieCount += 1;

	
	fp = fopen("user_ratings.csv", "rb");//���û������ļ� 
	if (fp == NULL)
	{
	    printf("��ȡ�ļ�ʧ��\n");   
	}
	int userID;
	while (fscanf(fp, "%d,%d,%[^\r\n]", &userID, &movieID, rateStr) != EOF)
	{
		
		USER* user = FindUser(g_userList, userID);
		if (user == NULL)//�����ж����û������û��ֿ鴦�� 
		{
			user = &g_userList[userCount];
			user->userID = userID;
			userCount++;//�����ж��ٸ��û����˷� 
		}
		
		float rate = atof(rateStr);//���ַ���ת�������ȸ����� 
		
		MOVIE* movie = FindMovie(movieList, movieID);//�ҵ������ĵ�Ӱ 
		
 		for (int i = 0; i < movie->typeCount; i++)
		{
			
			int index = FindTypeRate(user->movieTypeRateList, movie->movietype[i]);//�ҿ����ĵ�Ӱ���ͺ�û������ 
 			if (index == -1)//û�����ĵ�Ӱ�½����� 
			{
				
				MOVITYPEERATE typeRate;//�������ֽṹ�� 
				strcpy(typeRate.movieType, movie->movietype[i]);//�����͸�ֵ���ṹ���� 
				typeRate.rate = rate;//�������Ӱ�����ֵ���������͵����� 
				
				user->movieTypeRateList[user->typeCount] = typeRate;
				user->movieTypeRateList[user->typeCount].pMovieID = (int*)malloc(300 * sizeof(int));
				if (user->movieTypeRateList[user->typeCount].pMovieID == NULL)
				{
				    printf("�����ڴ�ʧ��\n"); 
				}
			    //memset(user->movieTypeRateList[user->typeCount].pMovieID, 0, 300 * sizeof(int));
 				user->movieTypeRateList[user->typeCount].movieIdCount = 0;
 				user->typeCount++;
			}
			else//�����ĵ�Ӱ�ۼ����֣���ԭ���������ϵĵ�Ӱ���û����ּ����� 
			{
				user->movieTypeRateList[index].pMovieID[user->movieTypeRateList[index].movieIdCount] = movie->movieID;
				user->movieTypeRateList[index].movieIdCount++;
				user->movieTypeRateList[index].rate += rate;//�ۼ����� 
			}

		}

	}


	MOVIE* loveMovieList=NULL;
	loop : while (true) 
	{
		int destUserID;
		printf("\n�����뱻�Ƽ���Ӱ���û�ID (����-1�˳�����)��");
		//printf("\n����-1�˳�����\n");
 		scanf("%d", &destUserID);
		if(destUserID < 0)
		{
		    system("cls");
		    break;
		}
		if(destUserID >= 550)
		{
			printf("\n���û�������\n");
			printf("\n����������\n");
			printf("\n����-1�˳�����\n");
			goto loop;
		}
		USER* user = FindUser(g_userList, destUserID);//�ҵ�Ŀ���û� 

		char favorateType[50];
		float maxRate = 0;
		
		for (int i = 0; i < user->typeCount; i++)
		{
			if (user->movieTypeRateList[i].rate > maxRate)
			{
				maxRate = user->movieTypeRateList[i].rate;//���������ָ�ֵ��maxRate 
				strcpy(favorateType, user->movieTypeRateList[i].movieType);//����ϲ��������copy��favorateType 
			}
		}
		
		printf("\n����ϲ����movietype�ǣ�%s  ���Դ����͵�Ӱ���ۼ������ǣ�%.1f\n", favorateType, maxRate);

		MOVITYPEERATE* userMovieType = NULL;// ����ϲ�õ�Ӱ���ͽṹ�� 
		for (int i = 0; i < user->typeCount; i++)
		{
			if (strcmp(user->movieTypeRateList[i].movieType, favorateType) == 0)//���û������ĵ�Ӱ�����ҳ�����ϲ�������� 
			{
				userMovieType = &user->movieTypeRateList[i];//����ϲ���ĵ�Ӱ���붨���ϲ�õ�Ӱ�ṹ�� 
				break;
			}
		}

		
		int loveCount = 0;
		
		if (loveMovieList != NULL) 
		{ 
		    free(loveMovieList); //�����ڴ��� 
		}
		
		loveMovieList = (MOVIE*)malloc(sizeof(MOVIE) * 10000);//��ϲ����Ӱ�б�����ڴ� 

		
		for (int i = 0; i < movieCount; i++)//�ڵ�Ӱ�����ҵ�ϲ�������ͺ͵�Ӱ�����ҷ��࿴����û���� 
		{
			for (int k = 0; k < movieList[i].typeCount; k++) 
			{
				if (strcmp(movieList[i].movietype[k], favorateType) == 0)//�����ͱ����ϲ������
				{
					bool noSee = true;//��û��������Ϊ��ֵ
					for (int j = 0; j < userMovieType->movieIdCount; j++) 
					{
						if (userMovieType->pMovieID[j] == movieList[i].movieID)//�����˾Ͱ�noSee�������
						{
							noSee = false;
							break;
						}
					}

					if (noSee)//���û�����;����б��һ 
					{ 
					    loveMovieList[loveCount++] = movieList[i]; 
					}
					break;
				}
			}
		}

		//ð������ 
		//��û������ϲ�����͵�ӰƬ���մӴ�С���� 
		for (int i = 0; i < loveCount - 1; i++)
		{
			for (int k = 0; k < loveCount - 1 - i; k++)
			{
				if (loveMovieList[k].avgRate < loveMovieList[k + 1].avgRate)
				{
					MOVIE temp = loveMovieList[k];
					loveMovieList[k] = loveMovieList[k + 1];
					loveMovieList[k + 1] = temp;
				}
			}
		}

		
		printf("\nΪ���Ƽ����ʮ��ͬ���͵ĵ�Ӱ��\n");
		for (int i = 0; i < 10; i++)
		{
			printf("\n��ӰID��%d\t��Ӱ����%s\tƽ�����֣�%.1f\n", loveMovieList[i].movieID, loveMovieList[i].movieName, loveMovieList[i].avgRate);
		}
		printf("\n\n");
		
	}
	
}

/*******************************************************************************************************************************/


/*******************************************************************************************************************************/
struct Keywords
	{
	int num;
	char name[1000];
	}Kword[maxid];

void feature5()
{
	
	long i = 0;
    FILE* fp;
    if((fp = fopen("movie_names.csv", "r"))==NULL)
    {
    	printf("�޷����ļ�\n");
		exit(1); 
	}
    while(fscanf(fp, "%d,%[^,],,,,,,,\r\n", &Kword[i].num, Kword[i].name) != EOF)
    {
        //printf( "%d,%s\n", movie[i].num, movie[i].name); 
  		i++; 
    }
    int k = i;
    printf("�����������ѯ�ĵ�Ӱ�Ĺؼ���(����-1�˳�����)��");
    char needle[50];
	char* ret = NULL;
		while(scanf("%s",needle) == 1)
		{ 
		    if(atoi(needle) < 0)
            {
            	system("cls");
		    	break;
			}
			int count = 0;
			for(i = 0;i<k;i++)
			{
				ret = strstr(Kword[i].name,needle);
				if(ret != NULL)
				{
					printf("\n���Ǻ��йؼ��ʵĵ�Ӱ:%s\n",Kword[i].name);
					count++;
				}
				if(count == 0&&ret == NULL&&i == k-1)
				{
					printf("\n�Ҳ�����������Ĺؼ��ʵĵ�Ӱ\n");
				}
			}
			printf("\n�����������ѯ�ĵ�Ӱ�Ĺؼ���(����-1�˳�����)��");
					
		}
	
}


/*******************************************************************************************************************************/


/*******************************************************************************************************************************/

int main()
{
	char s_choice[50];
	int choice;
	while(1)
	{
		loop : getmenu();
		printf(" ��������Ӧ����(����-1�˳�����):");
		scanf("%s",&s_choice);
		choice = atoi(s_choice);
		if(choice>5)
		{
		    system("cls");
            printf(" ������Ч,��������!\n"); 
			goto loop;	
		}
		system("cls");
		switch(choice)
		{
			case 0:
				
			system("cls");
            printf(" ������Ч,��������!\n");         
		    break;
				
			case 1:
			
			if(choice>5)
			{
				system("cls");
                printf(" ������Ч,��������!\n");         
		        break;
			}
			printf("             *         1����ѯ�û��Ƿ񿴹�ĳ��Ӱ       *\n\n\n");
			feature1();
			break;
			
			case 2:	
			
			if(choice>5)
			{
				system("cls");
                printf(" ������Ч,��������!\n");         
		        break;
			}
			printf("             *         2����ѯ�û������ĵ�Ӱ           *\n\n\n");
			feature2();
			break;
			
			case 3:
				
			if(choice>5)
			{
				system("cls");
                printf(" ������Ч,��������!\n");         
		        break;
			}
			printf("             *         3����ѯ��Ӱ����Щ�û�����       *\n\n\n");
			feature3();
			
			break;
			
			case 4:
				
			if(choice>5)
			{
				system("cls");
                printf(" ������Ч,��������!\n");         
		        break;
			}
			printf("             *         4�����Ի��Ƽ���Ӱ               *\n\n\n");
			feature4();
			break;
			
			case 5:
				
			if(choice>5)
			{
				system("cls");
                printf(" ������Ч,��������!\n");         
		        break;
			}
			printf("             *         5���ؼ���������Ӱ               *\n\n\n");
			feature5();
			break;
				
			
			default:
			system("cls");
            printf("��ӭ�´�ʹ��\n");
            printf("\n��������˳�"); 
			exit(1);
			
	    }	
	}
	
}


/*******************************************************************************************************************************/
