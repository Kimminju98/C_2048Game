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
	printf("        □□□  □□□  □  □  □□□\n"); 
	printf("            □  □  □  □  □  □  □\n");
	printf("        □□□  □  □  □□□  □□□\n");
	printf("        □      □  □      □  □  □\n");
	printf("        □□□  □□□      □  □□□\n\n\n\n");
	printf("         시작하려면 엔터를 입력하시오.");

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

								if(broad[z][j+1]==0 && broad[z][j]!=0){ // 비교할 다음 줄에 아무 것도 없으면,
									broad[z][j+1]=broad[z][j]; // 다음줄에 그 전 줄 값을 넣어줌.
									broad[z][j]=0; // 비교하는 줄의 값을 0으로 만들어줌.
								}

								else if(broad[z][j+1]!=0){// 비교할 다음 줄에 무언가 있으면,
									if(broad[z][j]==broad[z][j+1] && broad[z][j+1]<10000 ){ // 현재 값과 비교할 다음 줄의 값이 같다면

									
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

							if(broad[z][3-j-1]==0 && broad[z][3-j]!=0){ // 비교할 전 줄에 아무 것도 없으면,
								broad[z][3-j-1]=broad[z][3-j]; // 전줄에 그 줄 값을 넣어줌.
								broad[z][3-j]=0; // 비교하는 줄의 값을 0으로 만들어줌.
							}

							else if(broad[z][3-j-1]!=0){// 비교할 전 줄에 무언가 있으면,
								if(broad[z][3-j-1]==broad[z][3-j]&& broad[z][3-j-1]<10000){ // 현재 값과 비교할 전 줄의 값이 같다면
								    
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

							if(broad[3-j-1][z]==0 && broad[3-j][z]!=0){ // 비교할 전 줄에 아무 것도 없으면,
								broad[3-j-1][z]=broad[3-j][z]; // 다음줄에 그 전 줄 값을 넣어줌.
								broad[3-j][z]=0; // 비교하는 줄의 값을 0으로 만들어줌.
							}

							else if(broad[3-j-1][z]!=0){// 비교할 전 줄에 무언가 있으면,
								if(broad[3-j][z]==broad[3-j-1][z] && broad[3-j-1][z]<10000){ // 현재 값과 비교할 다음 줄의 값이 같다면
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

								if(broad[j+1][z]==0 && broad[j][z]!=0){ // 비교할 다음 줄에 아무 것도 없으면,
									broad[j+1][z]=broad[j][z]; // 다음줄에 그 전 줄 값을 넣어줌.
									broad[j][z]=0; // 비교하는 줄의 값을 0으로 만들어줌.
								}

								else if(broad[j+1][z]!=0){// 비교할 다음 줄에 무언가 있으면,
									if(broad[j][z]==broad[j+1][z] && broad[j+1][z]<10000){ // 현재 값과 비교할 다음 줄의 값이 같다면
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

		}//if(key=224 } 이다.)
		if(act==1){
			
			//1000을 다 빼준다.
			for(i=0; i<4 ; i++){
				for(j=0 ; j<4 ; j++){
					if(broad[i][j]>10000)
						broad[i][j]-=10000;
				}
			}
			

			// 새로운 숫자 생성.
			make_rand(broad);
			// 게임오버체크(2가지 : 실패 하는 경우, 성공 하는 경우) > break;
			is_gameover=GameOver(broad);
			if(is_gameover==1) return;

			// 판을 새로 그리기.
			Draw(broad);
		}
	}
}



void Draw(int broad[][4]){
	int a,b;
	
	clrscr();
	gotoxy(0,0);


	printf("\n  ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ      score :%d\n ",score);

	for(a=0 ; a<4 ; a++){
		
		for(b=0 ; b<4 ; b++){
			
			if(broad[a][b]==0)
				printf("|      ");
			else
			    printf("|%5d ",broad[a][b]);
		}
		printf("|");
		printf("\n");
		printf("  ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n ");   
	}
	printf("\n");
	//글씨를 원하면 이곳에.. 
	printf(" □□□  □□□  □  □  □□□\n"); 
	printf("     □  □  □  □  □  □  □\n");
	printf(" □□□  □  □  □□□  □□□\n");
	printf(" □      □  □      □  □  □\n");
	printf(" □□□  □□□      □  □□□\n");
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
