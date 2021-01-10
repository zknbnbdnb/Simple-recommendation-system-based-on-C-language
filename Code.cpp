#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#define maxid 100000
//每个分块有函数声明，列出要用的函数 
//void feature1()
//void feature2()
//void feature3()
//void feature4()
//void feature5()
void getmenu() /*显示菜单选择*/
{
    printf("             *******************主菜单******************\n\n");    
	printf("             *           欢迎进入电影推荐系统          *\n\n");    
	printf("             *         1、查询用户看过的某电影的评分   *\n\n");    
	printf("             *         2、查询用户看过的电影           *\n\n");    
	printf("             *         3、查询电影被那些用户看过       *\n\n");    
	printf("             *         4、个性化推荐电影               *\n\n");
	printf("             *         5、关键词搜索电影               *\n\n");
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
    	printf("无法打开文件\n");
		exit(1); 
	}
    while(!feof(fp))
    {
    	 
    	fscanf(fp,"%d,%d,%f\n",&USERS[i].user_id,&USERS[i].moive_nameid,&USERS[i].userpoint); 
  		i++; 
    }
    printf("\n请输入你的用户Id（数字）和电影id：\n");
    printf("\n输入-1退出程序\n"); 
    int Nameid;
	int movieid;
	
	int Mname[5];	
	    printf("\n用户ID     电影ID\n");
		
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
				printf("该用户不存在。\n");
				printf("请重新输入.\n");
				printf("\n输入-1退出程序\n");
				printf("\n用户ID     电影ID\n");
				goto loop; 
			}
			if(movieid>9125)
			{
				//system("cls");
				printf("该电影不存在。\n");
				printf("请重新输入.\n"); 
				printf("\n输入-1退出程序\n");
				printf("\n用户ID     电影ID\n");
				goto loop;
			}
			for(int a = 0;a<i;a++)
			{
				if(Nameid == USERS[a].user_id)
				{ 
					if(movieid == USERS[a].moive_nameid)
					{
						printf("\n他给出的评分是 : %.1f\n",USERS[a].userpoint);
						printf("\n请输入你的用户Id（数字）和电影id：\n");
						printf("\n输入-1退出程序\n");
						printf("\n用户ID     电影ID\n");
						break;
					}
				}
				if(USERS[a].user_id!=USERS[a+1].user_id)
				{
					if(Nameid == USERS[a].user_id)
					{
						//system("cls");
						printf("\n该用户还没看过这部电影，重新输入电影和用户的id\n");
						printf("\n输入-1退出程序\n");
						printf("\n");
						printf("\n用户ID     电影ID\n");
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
    	printf("无法打开文件\n");
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
    	printf("无法打开文件\n");
		exit(1); 
	}
    while(!feof(fp))
    {
    	fscanf(fp, "%[^,],%[^,],,,,,,,\r\n", movie[i].num, movie[i].name); 
  		i++; 
    }
    printf("\n请输入你的用户Id（数字）(输入-1退出程序)：");
    //printf("\n输入-1退出程序\n");
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
					printf("\n该用户不存在。\n");
					printf("\n请重新输入.\n");
					printf("\n输入-1退出程序\n"); 
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
    	                        printf("这是他看过的电影名称 : %s\n",movie[a].name);
										
	                        }	 
	                    }                      	
					}	 
				}
				printf("\n");
				printf("\n请输入你的用户Id（数字）(输入-1退出程序)：");
				
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
    	printf("无法打开文件\n");
		exit(1); 
	}
    while(!feof(fp))
    {
    	 
    	fscanf(fp,"%d,%d,%f\n",&user2[i].user_id,&user2[i].moive_nameid,&user2[i].userpoint); 
  		i++; 
   }
   printf("请输入你的电影Id（数字）(输入-1退出程序)：");
   //printf("\n输入-1退出程序\n");
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
					printf("\n该电影不存在。\n");
					printf("\n请重新输入.\n");
					printf("\n输入-1退出程序\n"); 
				}
				
				int a ;
			    for(a =0;a<i;a++)
				{
					if(movieid == user2[a].moive_nameid)
					{
						printf("这个用户看过这个电影 : %d\n",user2[a].user_id);
						count++; 
					}
					if(count == 0&&a == i-1)
					{
						printf("\n该电影没人看过。\n");
					    //printf("\n请重新输入.\n");
					    printf("\n输入-1退出程序\n");
					}
				}
				
				
			printf("\n请输入你的电影Id（数字）(输入-1退出程序)：");
		
		}
}

/*******************************************************************************************************************************/


/*******************************************************************************************************************************/

struct MOVIE
{
	int movieID;//电影id			                         
	char movieName[50];		//电影名称 
	char movietype[200][50];//电影类型	
	float avgRate;		//电影平均分	
	int typeCount;//计数 
};

struct MOVITYPEERATE
{
	char movieType[50];	//电影的一个类型 
	float rate;			//电影类型评分 
	int movieIdCount;	//计数 
	int* pMovieID;		//一个类型下所以的电影 
};
struct  USER
{
	int userID;			//用户id					
	MOVITYPEERATE movieTypeRateList[2000];	//某个类型的电影评分 
	int typeCount;	//计数 
};


MOVIE movieList[10000]; 
USER g_userList[10000];

int movieCount = 0;//定义全局变量 
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
		    break; //空字符不计算 
		}
		if (strcmp(list[i].movieType, movieType) == 0) 
		{
			return i;//看过返回i 
		}
	}
	return -1;//没看过返回-1 
}


void feature4()
{
	
	FILE* fp = fopen("movie_names.csv", "rb");//读电影名称文件，rb以二进制方式打开 
	if (fp == NULL)
	{
	    printf("读取文件失败\n");   
	}

	while (fscanf(fp, "%d,%[^,],,,,,,,\r\n", &movieList[movieCount].movieID, movieList[movieCount].movieName) != EOF)//%[^,]匹配，以外的任意的数据 
	{
		movieCount++;
	}
	fclose(fp);

	
	fp = fopen("movie_genres.csv", "rb"); //读电影类型文件
	if (fp == NULL)
	{
	    printf("读取文件失败\n");   
	}
	int movieID;
	char movieTypeStr[100];
	movieCount = 0;//重新初始化 
	while (fscanf(fp, "%d,%[^\r\n]", &movieID, movieTypeStr) != EOF)// [^\r\n]匹配换行以外的任意的数据   
	{
		char* movieType = strtok(movieTypeStr, "|");//将得到的大类型字符串分割成单个类型字符串 
		for (int i = 0;; i++)
		{
			if (movieType == NULL)
			{
			    break;
			}
			strcpy(movieList[movieCount].movietype[i], movieType);
			movieList[movieCount].typeCount++;//所有电影的所有类型的总和 
			movieType = strtok(NULL, "|");
		}
		movieCount++;
	}

	
	fp = fopen("average_ratings.csv", "rb");//读电影平均分文件
	if (fp == NULL)
	{
	    printf("读取文件失败\n");   
	}
	movieCount = 0;
	char rateStr[10];
	while (fscanf(fp, "%d,%[^,],,,,\r\n", &movieID, rateStr) != EOF)
	{
		movieList[movieCount++].avgRate = atof(rateStr);
	}	
	movieCount += 1;

	
	fp = fopen("user_ratings.csv", "rb");//读用户评分文件 
	if (fp == NULL)
	{
	    printf("读取文件失败\n");   
	}
	int userID;
	while (fscanf(fp, "%d,%d,%[^\r\n]", &userID, &movieID, rateStr) != EOF)
	{
		
		USER* user = FindUser(g_userList, userID);
		if (user == NULL)//查找有多少用户，将用户分块处理 
		{
			user = &g_userList[userCount];
			user->userID = userID;
			userCount++;//计算有多少个用户评了分 
		}
		
		float rate = atof(rateStr);//将字符串转换单精度浮点数 
		
		MOVIE* movie = FindMovie(movieList, movieID);//找到看过的电影 
		
 		for (int i = 0; i < movie->typeCount; i++)
		{
			
			int index = FindTypeRate(user->movieTypeRateList, movie->movietype[i]);//找看过的电影类型和没看过的 
 			if (index == -1)//没看过的电影新建评分 
			{
				
				MOVITYPEERATE typeRate;//类型评分结构体 
				strcpy(typeRate.movieType, movie->movietype[i]);//将类型赋值到结构体内 
				typeRate.rate = rate;//将这类电影的评分等于这个类型的评分 
				
				user->movieTypeRateList[user->typeCount] = typeRate;
				user->movieTypeRateList[user->typeCount].pMovieID = (int*)malloc(300 * sizeof(int));
				if (user->movieTypeRateList[user->typeCount].pMovieID == NULL)
				{
				    printf("申请内存失败\n"); 
				}
			    //memset(user->movieTypeRateList[user->typeCount].pMovieID, 0, 300 * sizeof(int));
 				user->movieTypeRateList[user->typeCount].movieIdCount = 0;
 				user->typeCount++;
			}
			else//看过的电影累加评分，在原本此类型上的电影的用户评分继续加 
			{
				user->movieTypeRateList[index].pMovieID[user->movieTypeRateList[index].movieIdCount] = movie->movieID;
				user->movieTypeRateList[index].movieIdCount++;
				user->movieTypeRateList[index].rate += rate;//累加评分 
			}

		}

	}


	MOVIE* loveMovieList=NULL;
	loop : while (true) 
	{
		int destUserID;
		printf("\n请输入被推荐电影的用户ID (输入-1退出程序)：");
		//printf("\n输入-1退出程序\n");
 		scanf("%d", &destUserID);
		if(destUserID < 0)
		{
		    system("cls");
		    break;
		}
		if(destUserID >= 550)
		{
			printf("\n该用户不存在\n");
			printf("\n请重新输入\n");
			printf("\n输入-1退出程序\n");
			goto loop;
		}
		USER* user = FindUser(g_userList, destUserID);//找到目标用户 

		char favorateType[50];
		float maxRate = 0;
		
		for (int i = 0; i < user->typeCount; i++)
		{
			if (user->movieTypeRateList[i].rate > maxRate)
			{
				maxRate = user->movieTypeRateList[i].rate;//将类型评分赋值给maxRate 
				strcpy(favorateType, user->movieTypeRateList[i].movieType);//将最喜欢的类型copy给favorateType 
			}
		}
		
		printf("\n您最喜欢的movietype是：%s  您对此类型电影的累计评分是：%.1f\n", favorateType, maxRate);

		MOVITYPEERATE* userMovieType = NULL;// 定义喜好电影类型结构体 
		for (int i = 0; i < user->typeCount; i++)
		{
			if (strcmp(user->movieTypeRateList[i].movieType, favorateType) == 0)//从用户看过的电影类型找出来最喜欢的类型 
			{
				userMovieType = &user->movieTypeRateList[i];//将最喜欢的电影存入定义的喜好电影结构体 
				break;
			}
		}

		
		int loveCount = 0;
		
		if (loveMovieList != NULL) 
		{ 
		    free(loveMovieList); //清理内存区 
		}
		
		loveMovieList = (MOVIE*)malloc(sizeof(MOVIE) * 10000);//给喜爱电影列表分配内存 

		
		for (int i = 0; i < movieCount; i++)//在电影表中找到喜爱的类型和电影，并且分类看过和没看的 
		{
			for (int k = 0; k < movieList[i].typeCount; k++) 
			{
				if (strcmp(movieList[i].movietype[k], favorateType) == 0)//总类型表查找喜爱类型
				{
					bool noSee = true;//将没看过先设为真值
					for (int j = 0; j < userMovieType->movieIdCount; j++) 
					{
						if (userMovieType->pMovieID[j] == movieList[i].movieID)//看过了就把noSee插假旗子
						{
							noSee = false;
							break;
						}
					}

					if (noSee)//如果没看过就就在列表加一 
					{ 
					    loveMovieList[loveCount++] = movieList[i]; 
					}
					break;
				}
			}
		}

		//冒泡排序 
		//在没看的最喜欢类型的影片按照从大到小排序 
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

		
		printf("\n为您推荐最多十部同类型的电影：\n");
		for (int i = 0; i < 10; i++)
		{
			printf("\n电影ID：%d\t电影名：%s\t平均评分：%.1f\n", loveMovieList[i].movieID, loveMovieList[i].movieName, loveMovieList[i].avgRate);
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
    	printf("无法打开文件\n");
		exit(1); 
	}
    while(fscanf(fp, "%d,%[^,],,,,,,,\r\n", &Kword[i].num, Kword[i].name) != EOF)
    {
        //printf( "%d,%s\n", movie[i].num, movie[i].name); 
  		i++; 
    }
    int k = i;
    printf("请输入你想查询的电影的关键词(输入-1退出程序)：");
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
					printf("\n这是含有关键词的电影:%s\n",Kword[i].name);
					count++;
				}
				if(count == 0&&ret == NULL&&i == k-1)
				{
					printf("\n找不到含有输入的关键词的电影\n");
				}
			}
			printf("\n请输入你想查询的电影的关键词(输入-1退出程序)：");
					
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
		printf(" 请输入相应数字(输入-1退出程序):");
		scanf("%s",&s_choice);
		choice = atoi(s_choice);
		if(choice>5)
		{
		    system("cls");
            printf(" 输入无效,重新输入!\n"); 
			goto loop;	
		}
		system("cls");
		switch(choice)
		{
			case 0:
				
			system("cls");
            printf(" 输入无效,重新输入!\n");         
		    break;
				
			case 1:
			
			if(choice>5)
			{
				system("cls");
                printf(" 输入无效,重新输入!\n");         
		        break;
			}
			printf("             *         1、查询用户是否看过某电影       *\n\n\n");
			feature1();
			break;
			
			case 2:	
			
			if(choice>5)
			{
				system("cls");
                printf(" 输入无效,重新输入!\n");         
		        break;
			}
			printf("             *         2、查询用户看过的电影           *\n\n\n");
			feature2();
			break;
			
			case 3:
				
			if(choice>5)
			{
				system("cls");
                printf(" 输入无效,重新输入!\n");         
		        break;
			}
			printf("             *         3、查询电影被那些用户看过       *\n\n\n");
			feature3();
			
			break;
			
			case 4:
				
			if(choice>5)
			{
				system("cls");
                printf(" 输入无效,重新输入!\n");         
		        break;
			}
			printf("             *         4、个性化推荐电影               *\n\n\n");
			feature4();
			break;
			
			case 5:
				
			if(choice>5)
			{
				system("cls");
                printf(" 输入无效,重新输入!\n");         
		        break;
			}
			printf("             *         5、关键词搜索电影               *\n\n\n");
			feature5();
			break;
				
			
			default:
			system("cls");
            printf("欢迎下次使用\n");
            printf("\n按任意键退出"); 
			exit(1);
			
	    }	
	}
	
}


/*******************************************************************************************************************************/
