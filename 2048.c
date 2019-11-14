#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <conio.h>
#include "Console.h"




#define RIGHT 77
#define LEFT 75
#define UP 72
#define DOWN 80

int broad[4][4]={0,0,0,0,
	             0,0,0,0,
				 0,0,0,0,
				 0,0,0,0};

int score=0;


void Draw(int broad[][4]);
void make_rand(int arr[][4]);
int GameOver(int arr[][4]);


int main(){

	int key;
	int act;
	int i,j,z;
	int is_gameover;

	system("mode con:cols=50 lines=20");

	printf("\n\n\n\n");
	printf("        ����  ����  ��  ��  ����\n"); 
	printf("            ��  ��  ��  ��  ��  ��  ��\n");
	printf("        ����  ��  ��  ����  ����\n");
	printf("        ��      ��  ��      ��  ��  ��\n");
	printf("        ����  ����      ��  ����\n\n\n\n");
	printf("         �����Ϸ��� ���͸� �Է��Ͻÿ�.");

	key=getch();
	if(key==13){
			make_rand(broad);
	        make_rand(broad);

	        Draw(broad);
	}
	//make_rand(broad);
	//make_rand(broad);

	//Draw(broad);

	while(1){
		act=0;
		key=getch();

		if(key==224){

			key=getch();

			switch(key){
			case RIGHT :

					for(i=0; i<3 ; i++){
						for(j=2-i ; j<3 ; j++){
							//if(i==2 && j==2) break;
							for(z=0; z<4 ; z++){

								if(broad[z][j+1]==0 && broad[z][j]!=0){ // ���� ���� �ٿ� �ƹ� �͵� ������,
									broad[z][j+1]=broad[z][j]; // �����ٿ� �� �� �� ���� �־���.
									broad[z][j]=0; // ���ϴ� ���� ���� 0���� �������.
								}

								else if(broad[z][j+1]!=0){// ���� ���� �ٿ� ���� ������,
									if(broad[z][j]==broad[z][j+1] && broad[z][j+1]<10000 ){ // ���� ���� ���� ���� ���� ���� ���ٸ�

									
							            score+=broad[z][j];   
							
										broad[z][j+1]=broad[z][j+1]+broad[z][j]+10000;
										broad[z][j]=0;
									}
								}
							}
						}
					}
				act++;
				break;
			case LEFT :
				

				for(i=0; i<3 ; i++){
					for(j=2-i ; j<3 ; j++){
						//if(i==2 && j==2) break;
						for(z=0; z<4 ; z++){

							if(broad[z][3-j-1]==0 && broad[z][3-j]!=0){ // ���� �� �ٿ� �ƹ� �͵� ������,
								broad[z][3-j-1]=broad[z][3-j]; // ���ٿ� �� �� ���� �־���.
								broad[z][3-j]=0; // ���ϴ� ���� ���� 0���� �������.
							}

							else if(broad[z][3-j-1]!=0){// ���� �� �ٿ� ���� ������,
								if(broad[z][3-j-1]==broad[z][3-j]&& broad[z][3-j-1]<10000){ // ���� ���� ���� �� ���� ���� ���ٸ�
								    
								    score+=broad[z][3-j];

									broad[z][3-j-1]=broad[z][3-j]+broad[z][3-j-1]+10000;
									broad[z][3-j]=0;
								}
							}
						}
					}
				}
				act++;
				break;
			case UP :
				
				for(i=0; i<3 ; i++){
					for(j=2-i ; j<3 ; j++){
						//if(i==2 && j==2) break;
						for(z=0; z<4 ; z++){

							if(broad[3-j-1][z]==0 && broad[3-j][z]!=0){ // ���� �� �ٿ� �ƹ� �͵� ������,
								broad[3-j-1][z]=broad[3-j][z]; // �����ٿ� �� �� �� ���� �־���.
								broad[3-j][z]=0; // ���ϴ� ���� ���� 0���� �������.
							}

							else if(broad[3-j-1][z]!=0){// ���� �� �ٿ� ���� ������,
								if(broad[3-j][z]==broad[3-j-1][z] && broad[3-j-1][z]<10000){ // ���� ���� ���� ���� ���� ���� ���ٸ�
									score+=broad[3-j][z];
									broad[3-j-1][z]=broad[3-j-1][z]+broad[3-j][z]+10000;
									broad[3-j][z]=0;
								}
							}
						}
					}
				}
				act++;
				break;
			case DOWN :
					for(i=0; i<3 ; i++){
						for(j=2-i ; j<3 ; j++){
							//if(i==2 && j==2) break;
							for(z=0; z<4 ; z++){

								if(broad[j+1][z]==0 && broad[j][z]!=0){ // ���� ���� �ٿ� �ƹ� �͵� ������,
									broad[j+1][z]=broad[j][z]; // �����ٿ� �� �� �� ���� �־���.
									broad[j][z]=0; // ���ϴ� ���� ���� 0���� �������.
								}

								else if(broad[j+1][z]!=0){// ���� ���� �ٿ� ���� ������,
									if(broad[j][z]==broad[j+1][z] && broad[j+1][z]<10000){ // ���� ���� ���� ���� ���� ���� ���ٸ�
										score+=broad[j][z];
										broad[j+1][z]=broad[j+1][z]+broad[j][z]+10000;
										broad[j][z]=0;
									}
								}
							}
						}
					}
				act++;
				break;

			}

		}//if(key=224 } �̴�.)
		if(act==1){
			
			//1000�� �� ���ش�.
			for(i=0; i<4 ; i++){
				for(j=0 ; j<4 ; j++){
					if(broad[i][j]>10000)
						broad[i][j]-=10000;
				}
			}
			

			// ���ο� ���� ����.
			make_rand(broad);
			// ���ӿ���üũ(2���� : ���� �ϴ� ���, ���� �ϴ� ���) > break;
			is_gameover=GameOver(broad);
			if(is_gameover==1) return;

			// ���� ���� �׸���.
			Draw(broad);
		}
	}
}



void Draw(int broad[][4]){
	int a,b;
	
	clrscr();
	gotoxy(0,0);


	printf("\n  �ѤѤѤѤѤѤѤѤѤѤѤѤѤ�      score :%d\n ",score);

	for(a=0 ; a<4 ; a++){
		
		for(b=0 ; b<4 ; b++){
			
			if(broad[a][b]==0)
				printf("|      ");
			else
			    printf("|%5d ",broad[a][b]);
		}
		printf("|");
		printf("\n");
		printf("  �ѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n ");   
	}
	printf("\n");
	//�۾��� ���ϸ� �̰���.. 
	printf(" ����  ����  ��  ��  ����\n"); 
	printf("     ��  ��  ��  ��  ��  ��  ��\n");
	printf(" ����  ��  ��  ����  ����\n");
	printf(" ��      ��  ��      ��  ��  ��\n");
	printf(" ����  ����      ��  ����\n");
}    

void make_rand(int arr[][4]){
  int a,b;
 
 do{ 
  srand((int)time(NULL));
  a=rand()%4;
  b=rand()%4;
 }while(arr[a][b]!=0);
  
  arr[a][b]=2;
}


int GameOver(int arr[][4]){
  int count=0,a,b;
  for(a=0;a<4;a++){
    for(b=0;b<4;b++){
      if(arr[a][b]==0)
        count++;
    }
  }
  if(count==0){
    clrscr();
	gotoxy(0,0);

    printf("\n\n\n\n\n\n\n\n");
    printf("          Game Over!!");
	printf("\          score : %d\n\n\n\n\n\n\n",score);
    return 1;
  }
  else{
    for(a=0;a<4;a++){
      for(b=0;b<4;b++){
        if(arr[a][b]==2048){
			clrscr();
	        gotoxy(0,0);

			printf("\n\n\n\n\n\n\n\n");
			printf("               Great!!");
			printf("\n               score : %d\n\n\n\n\n\n\n",score);
          return 1;
        }
      }
    }
  }
  return 0;
}
