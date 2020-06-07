#include<iostream>
#include <cstdlib>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameover;
const int height=20;
const int width=20;
int x,y,fruitx,fruity,score;
int tailx[100],taily[100];
int ntail;
enum eDirection {LEFT,RIGHT,UP,DOWN,STOP=0};
eDirection dir;
void setup() {
	gameover=false;
	dir=STOP;
	x=width/2;
	y=height/2;
	fruitx = rand()%width;
	fruity = rand()%height;
	score=0;
}
void draw() {
	system("cls");
	for(int i=0; i<width+2; i++)
		cout<<"$";
	cout<<endl;

	for (int i =0; i<height; i++ ) {
		for (int j=0; j<width; j++) {
			if(j==0)
				cout<<"$";
			if(i==x&&j==y)
				cout<<"O";
			else if(i==fruitx&&j==fruity)
				cout<<("F");
			else{
				bool print=false;
				for(int k=0;k<ntail;k++){
					if(tailx[k]== i && taily[k]==j){
						cout<<"o";
					    print=true;
					
				}
				}
				if(!print){
					cout<<" ";
				}
			}
			    
			if(j==width-1)
				cout<<"$";
		}
		cout<<endl;
	}

	for(int i=0; i<width+2; i++)
		cout<<"$";
	cout<<endl;
	cout<<"score:"<<score;

}
void input() {
	if(_kbhit()) {
		switch(getch()) {
			case 'a':
				dir=LEFT;
				break;
			case 'd':
				dir=RIGHT;
				break;
			case 'w':
				dir=UP;
				break;
			case 's':
				dir=DOWN;
				break;
			case 'x':
				gameover=true;
				break;

		}
	}
}
void logic()
{
    int prevx = tailx[0];
    int prevy = taily[0];
    int prev2x, prev2y;
    tailx[0]=x;
    taily[0]=y;
   
    for (int i = 1; i < ntail; i++)
    {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }
    switch (dir)
    {
    case LEFT:
        y--;
        break;
    case RIGHT:
        y++;
        break;
    case UP:
        x--;
        break;
    case DOWN:
        x++;
        break;
    default:
        break;
    }
    if (x > width || x < 0 || y > height || y < 0)
      gameover = true;
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;
 
    for (int i = 0; i < ntail; i++)
        if (tailx[i] == x && taily[i] == y)
            gameover = true;
 
    if (x == fruitx && y == fruity)
    {
        score += 10;
        fruitx = rand() % width;
        fruity = rand() % height;
        ntail++;
    }
}

int main() {
	setup();	
	while(!gameover) {
		draw();
		input();
		logic();
	}
	return 0;
}

