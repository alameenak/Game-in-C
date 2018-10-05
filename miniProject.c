 #include<stdio.h>
 #include<graphics.h>
 #include<dos.h>
 #include<string.h>
 #include<conio.h>
 #include<process.h>
 #include<stdlib.h>
 
 void game(void);
 void gamer(void);
 void start(void);
 void marks(int,int);
 void scorecard(void);

 
 char name[50];

 
 struct scard
	{
		char name[20];
		int words;
		int mark;
	}sc[5];
 
int main()
{
	
	start();
    return 0;
	 
}

void start()
{
	int choice;
	clrscr();
	while(1)
	{
		printf("\n1-start");
		//printf("\n2-score card");
		printf("\n3-exit");
		printf("\nenter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					gamer();
					break;
			/*case 2:
					scorecard();
					break;*/
			case 3:
					exit(0);
					break;
			default:
					printf("something wrong");
		}
	}
}

void gamer()
{
	printf("enter your name:");
	scanf("%s",&name);
	//getch();
	game();
	
}



void scorecard()
{
	int i,limit;

	FILE *scfp=fopen("score.txt","r+");//opeing a file in drive D
	if(scfp!=NULL)
	{
	i=0;
	while(!feof(scfp))

		{


			fscanf( scfp, "%s%d%d",sc[i].name,&sc[i].words,&sc[i].mark);
			limit=i;
			i++;

		}

		fclose(scfp);
    }
	clrscr();
	puts("POSITION\tNAME\tWORDS\tMARKS");
	puts("---------\t-----\t-----\t-----");
	for(i=0;i<=limit;i++)
		printf("\n%d\t\t%s\t%d\t%d",i+1,sc[i].name,sc[i].words,sc[i].mark);
	
	getch();
	start();
	
}

void game()
{
	int gdrive=DETECT,gmode,midx,midy;
	int i,x,j,k,co=0,n,ii;
	//int a[]={50,100,200,300,400};
	char str[20];
	char c;
	int len=0;
	//char sample_words[][10]={"hello","animation","World"};
	char arr[100][25];
	FILE *fp=fopen("eg.txt","r");//opeing a file in drive D
	char ch[20];
	int del=600;
	int word=0,mark=0,ij;
	
	
	for(i=0; i<20; i++)
	{
		for(j=0; j<20; j++)
			arr[i][j] = '\0';
	}
	
	/*for(i=0; i<5; i++)
		ch[i] = '\0';*/

	
	
	
	if(fp!=NULL)
	{
	i=0;
	while(!feof(fp))

		{


			fgets ( ch, sizeof ch, fp);

			n=strlen(ch);
			for(ii=0;ii<(n-1);ii++)
				arr[i][ii]=ch[ii];
			//strcpy(arr[i], ch);
			i++;

		}

		fclose(fp);
    }

	initgraph(&gdrive,&gmode,"C:\\TC\\BGI");
	if(graphresult()!=grOk)
	{
		printf("Graphics Eror\n");
		getch();
		//return 0;
    }

    //=getmaxx()/2;
    line(0,200,getmaxx(),200);
    for(i=0;i<50;i++)
	{

		k=random(450);
		ij=random(20);
		len=0;
		str[len]='\0';
		for(j=0;j<=400;j+=10)
		{

			clrscr();
			if(kbhit())
			{

				c=getch();
				str[len++]=c;
				str[len]='\0';


				if(!(strcmp(str,arr[ij])))
				{
					mark+=strlen(str);
					++word;
					break;
				}
					
				else if(str[len-1]!=arr[ij][len-1])
				{
					len=0;
					str[len]='\0';
				}
			}
			setcolor(ij);
			outtextxy(k,j,arr[ij]);

			delay(del);
			if(j==400)
				marks(word,mark);
		}
		co++;
		del-=20;
    }
}

void marks(int w,int m)
{
	/*int i;
	FILE *scfp=fopen("score.txt","r+");//opeing a file in drive D

	
	
	if(scfp!=NULL)
	{
	i=0;
	while(!feof(scfp))

		{


			fscanf( scfp, "%s%d%d",sc[i].name,&sc[i].words,&sc[i].mark);
			if(sc[i].words<w)
				fprintf( scfp, "%s %d %d",name,w,m);
			i++;

		}

		fclose(scfp);
		fprintf(stdout);
    }*/
	
	clrscr();
	printf("congradulation %s",name);
	printf("\nnumber of words cleard=%d",w);
	printf("\nmarks=%d",m);
	
	getch();
	start();
	
}