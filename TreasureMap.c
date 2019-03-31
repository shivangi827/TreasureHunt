/*
Author: Shivangi Vyas
Uta Id: 1001570499
Assignment: 10- THE TREASURE MAP GAME
Due: Friday, 5/4/18
*/


#include <stdio.h>
#include <stdlib.h>
#include<errno.h>
#include<string.h>
#define MAPSIZE 10
#define TRUE 1
#define FALSE 0

char DirectionsFilename[20] = { };	//Size??????????
char MapFilename[20] = { };

struct PlayerInfo	
{
  int CurrentRow,CurrentCol;
  char Player1Name[20];
  char Player2Name[20];
  int counter1;
  int counter2;
} ;
//struct PlayerInfo *Pointer;


/***********************************************************************	NORTH	********************************************************************************************************/
int MoveNorth (struct PlayerInfo *PlayerPtr, char Map[10][10])
{
  if (Map[(PlayerPtr->CurrentRow)-1][PlayerPtr->CurrentCol]=='X'||Map[(PlayerPtr->CurrentRow)-1][PlayerPtr->CurrentCol]=='E'||Map[(PlayerPtr->CurrentRow)-1][PlayerPtr->CurrentCol]=='S')
    {
     (PlayerPtr->CurrentRow)--;
	return TRUE;
    }
  else
    {
      printf("North is the wrong move\n");
	    return FALSE;
    }


  //return TRUE;
}

/**************************************************************************		SOUTH	*****************************************************************************************************/ 
/*****************************************************************************************************/
  int MoveSouth (struct PlayerInfo *PlayerPtr, char Map [10][10])
{
  if (Map[(PlayerPtr->CurrentRow)+1][PlayerPtr->CurrentCol]=='X'||Map[(PlayerPtr->CurrentRow)+1][PlayerPtr->CurrentCol]=='E'||Map[(PlayerPtr->CurrentRow)+1][PlayerPtr->CurrentCol]=='S')
    {
       (PlayerPtr->CurrentRow)++;
		return TRUE;
    }
  else
    {
		printf("South is the wrong move\n");
	    return FALSE;
 	  /////Check >10?? or  >9??????
    }

  
}

/***************************************************************************	WEST	****************************************************************************************************/
int MoveWest (struct PlayerInfo *PlayerPtr, char Map [10][10])
{
	if((PlayerPtr->CurrentCol)-1>=0 && (PlayerPtr->CurrentCol)-1<=9)
	{
  if (Map[PlayerPtr->CurrentRow][(PlayerPtr->CurrentCol)-1]=='X'||Map[PlayerPtr->CurrentRow][(PlayerPtr->CurrentCol)-1]=='S'||Map[PlayerPtr->CurrentRow][(PlayerPtr->CurrentCol)-1]=='E')
    {
		(PlayerPtr->CurrentCol)--;
	  return TRUE;
    }
  else
    {
		printf("West is the wrong move\n");
	    return FALSE;
    }
	}
	else
	{
		printf("West is the wrong move\n");
	    return FALSE;
	}

  //return TRUE;
}

/**************************************************************************		EAST	*************************************************************************************************/
int MoveEast (struct PlayerInfo *PlayerPtr, char Map [10][10])
{
	if((PlayerPtr->CurrentCol)+1>=0 && (PlayerPtr->CurrentCol)+1<=9)
	{
  if (Map[PlayerPtr->CurrentRow][(PlayerPtr->CurrentCol)+1]=='X'||Map[PlayerPtr->CurrentRow][(PlayerPtr->CurrentCol)+1]=='S'||Map[PlayerPtr->CurrentRow][(PlayerPtr->CurrentCol)+1]=='E')
    {
       (PlayerPtr->CurrentCol)++;
	   return TRUE;
    }
  else
    {
		printf("East is the wrong move\n");
	    return FALSE;
 
    }
	}
	else
	{
		printf("East is the wrong move\n");
	    return FALSE;
	}
  


 //return TRUE;
}


//****************************************************************************	COMMANDLINE	  ****************************************************************
//***********************************/ ***************************************************************************************************/
  void get_command_line_params (int argc ,char *argv [])
{
  int i;
  for (i = 0; i < argc; i++)
    {
     if (!memcmp (*(argv + i), "MAP=", 4))
	{
	  memcpy (MapFilename, (strchr (*(argv + i), '=') + 1), 19);
	}
    }
  if (MapFilename[0] == '\0' )
    {
      printf ("MAP= must be given on the command line"  );
		exit(0);
	}

return;

}


//**********************************************************************		MAIN		*********************************************************************************************************/	*********************************************************************************************************//
int main (int argc, char *argv [])
{
	FILE  *TreasureMap;
	char MapList[500];
	char Map[MAPSIZE][MAPSIZE];
	char PlayerPath[MAPSIZE][MAPSIZE];
	char PlayerMove;
	int i,j,k,MakeMove;
	int m=0;
	struct PlayerInfo Player;
	struct PlayerInfo *PlayerPtr = &Player;
	//PlayerPtr= &Position;
	get_command_line_params(argc,argv);
	TreasureMap=fopen(MapFilename,"r+");
	Player.counter1=0;
	Player.counter2=0;

	
	if(TreasureMap == NULL)
	{
		perror("TreasureMap did not open" );
		exit(0);
	}
	system("clear");
	printf("Please enter your name, Player1: ");
	scanf(	"%s",&(Player.Player1Name));
	getchar();
	printf("Please enter your name, Player2: ");
	scanf(	"%s",&(Player.Player2Name));
	getchar();
	fgets(MapList,500,TreasureMap);
	
	
	
	
	do{
	
	system("clear");
	
	
	Player.CurrentCol=0;
	Player.CurrentRow=0;
	
	
	i=0;
	for(j=0;j<MAPSIZE;j++)
	{
	    for(k=0;k<MAPSIZE;k++)
	    {
	       
			Map[j][k]=MapList[i];
			printf("%c  ",Map[j][k]);
			 PlayerPath[j][k]='-';
			i++;
			
	    }
		printf("\n\n");
			
	}
	
		printf("Press <ENTER> when you are ready to start ");
		getchar();
		system("clear");
		PlayerPath[0][0]=Map[0][0];
	
	do{
		printf("Enter a direction (NSEW) or 'Q' to quit ");
		scanf("%c",&PlayerMove);
		//getchar(); 
		if(m==0)
		{
			Player.counter1++;
		}
		else if (m==1)
		{
			Player.counter2++;
		}
		getchar();
		PlayerMove= toupper(PlayerMove);
		
		system("clear");

	
	    if(PlayerMove=='N')
	    {
	       MakeMove= MoveNorth(PlayerPtr,Map);
	       
	    }
	    else if(PlayerMove=='S')
	    {
	        MakeMove=MoveSouth(PlayerPtr,Map);
	        
	    }
	    else if(PlayerMove=='W')
	    {
	        MakeMove=MoveWest(PlayerPtr,Map);
	        
	    }
	    else  if(PlayerMove=='E')
	    {
	       MakeMove= MoveEast(PlayerPtr,Map);
		}
		else if(PlayerMove=='Q')
		{
			printf(" You chose to end the game in the middle.\n");
			exit(0);
		}
		else
		{
			printf( "Invalid move - must be NSEW\n");
			
			MakeMove=0;
		}
	    
		if(MakeMove)
		{
			
			if(Map[PlayerPtr->CurrentRow][PlayerPtr->CurrentCol]=='S')
			{
				if(m==0)
				{
				printf( "Player %s is back at start\n",Player.Player1Name);
				}
				else if(m==1)
				{
					printf( "Player %s is back at start\n",Player.Player2Name);
				}
			
			}
			else if(Map[PlayerPtr->CurrentRow][PlayerPtr->CurrentCol]=='X')
			{	
		
				PlayerPath[PlayerPtr->CurrentRow][PlayerPtr->CurrentCol]='X';
			}
			else if(Map[PlayerPtr->CurrentRow][PlayerPtr->CurrentCol]=='E')
			{
				
				if(m==0)
				{
					printf( "Player %s has made it to the end - WINNER!!\n",Player.Player1Name);
				}
				else if(m==1)
				{
					printf( "Player %s has made it to the end - WINNER!!\n",Player.Player2Name);
				}			
					PlayerPath[PlayerPtr->CurrentCol][PlayerPtr->CurrentRow]='E';
					PlayerMove='Q';
			}
			
		}
	
	
	for(j=0;j<MAPSIZE;j++)
	{
	    for(k=0;k<MAPSIZE;k++)
	    {
	        
			printf("%c  ",PlayerPath[j][k]);
	        
	    }
		printf("\n\n");
	}
	}while(PlayerMove != 'Q');
	
	
	
	m++;
	}while(m<2);
		
		system("clear");
		
		printf("%s took %d steps and %s took %d steps to reach to the finish line.\nThus,",Player.Player1Name,Player.counter1,Player.Player2Name,Player.counter2);
		if((Player.counter1)>(Player.counter2))
		{
			printf("%s :) won by %d steps.\n",Player.Player2Name,(Player.counter1)-(Player.counter2));
		}
		else if (Player.counter2>Player.counter1)
		{
			printf("%s :) won by %d step/s.\n",(Player.Player1Name),(Player.counter2)-(Player.counter1));
		}
		else
		{
			printf("there's a tie....\n");
		}
		fclose(TreasureMap);
		
	return 0;
}




