#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void clear();
void killer(int* kx, int* ky);
void food(int* fx, int* fy);
int main() {

	char  regame,tab[20][40], t = ' ';
	char points = 0, score[30] = { 's','c','o','r','e',' ',' ' ,' ' ,' ',' ',' ',' ',':',' '};
	int g,s,i, fx, fy, key,  j, xflag=0,kflag , l = 20, c = 40;
	int kx, ky;
	int ypos = 10, xpos = 20;
	srand(time(NULL));

	//make all interface of the game
	do {
		do {
			g = 1;
			for (i = 0;i < l;i++)
				for (j = 0;j < c;j++) {
					tab[i][j] = t;
				}

			//the game body
			kflag = 1;
			s = 1;
			do {
				killer(&kx, &ky);
				food(&fx, &fy);
			} while ((fx == xpos) && (fy == ypos) && (kx == xpos) && (ky == ypos));
			tab[fy][fx] = '$';
			do {
				clear();
				//killer follow 0
				if ((kx < xpos) && (ky < ypos)) {
					if (fx < kx) {
						tab[ky][kx] = t;
						xflag = -2;
						kx--;
					}
					else if (kx < fx) {
						tab[ky][kx] = t;
						kx++;
						xflag = 2;
					}
					else if ((kx == fx) && (ky != fy)) {
						if (fy < ky) {
							tab[ky][kx] = t;
							ky--;
							xflag = 1;
						}
						else if (ky < fy) {
							tab[ky][kx] = t;
							ky++;
							xflag = -1;
						}
					}
				}
				else if ((kx > xpos) && (ky > ypos)) {
					if (fx < kx) {
						xflag = -2;
						tab[ky][kx] = t;
						kx--;
					}
					else if (kx < fx) {
						tab[ky][kx] = t;
						kx++;
						xflag = 2;
					}
					else if ((kx == fx) && (ky != fy)) {
						if (fy < ky) {
							tab[ky][kx] = t;
							ky--;
							xflag = 1;
						}
						else if (ky < fy) {
							tab[ky][kx] = t;
							ky++;
							xflag = -1;
						}
					}
				}
				else if ((kx > xpos) && (ky < ypos)) {
					if (fx < kx) {
						tab[ky][kx] = t;
						xflag = -2;
						kx--;
					}
					else if (kx < fx) {
						tab[ky][kx] = t;
						kx++;
						xflag = 2;
					}
					else if ((kx == fx) && (ky != fy)) {
						if (fy < ky) {
							tab[ky][kx] = t;
							ky--;
							xflag = 1;
						}
						else if (ky < fy) {
							tab[ky][kx] = t;
							ky++;
							xflag = -1;
						}
					}
				}
				else if ((kx < xpos) && (ky > ypos)) {
					if (fx < kx) {
						tab[ky][kx] = t;
						xflag = -2;
						kx--;
					}
					else if (kx < fx) {
						tab[ky][kx] = t;
						kx++;
						xflag = 2;
					}
					else if ((kx == fx) && (ky != fy)) {
						if (fy < ky) {
							tab[ky][kx] = t;
							ky--;
							xflag = 1;
						}
						else if (ky < fy) {
							tab[ky][kx] = t;
							ky++;
							xflag = -1;
						}
					}
				}
				else if ((kx != xpos) && (ky == ypos)) {
					if (kx < xpos) {
						tab[ky][kx] = t;
						kx++;
						xflag = 2;
					}
					else if (kx > xpos) {
						tab[ky][kx] = t;
						kx--;
						xflag = -2;
					}
				}
				else if ((kx == xpos) && (ky != ypos)) {
					if (ky < ypos) {
						tab[ky][kx] = t;
						ky++;
						xflag = -1;
					}
					else if (ky > ypos) {
						tab[ky][kx] = t;
						ky--;
						xflag = 1;
					}
				}



				tab[ky][kx] = 'x';
				tab[ypos][xpos] = '0';
				for (i = 0;i < l;i++) {
					for (j = 0;j < c;j++) {
						printf("%c", tab[i][j]);
					}
					printf("\n");
				}
				//check if x is eaten 0
				if ((kx == xpos) && (ky == ypos)) {
					s = 0;
					kflag = 0;
					g++;
				}
				//check if x is on food
				if ((kx == fx) && (ky == fy)) {
					s = 0;
					kflag = 0;
					points--;
				}
				//write the score
				for (i = 0;i < 14;i++) {
					printf("%c", score[i]);
				}
				printf("%d", points);




				// here we can know which key is pressed
				if (kflag) {
					key = _getch();
					if (key == 0 || key == 224)
					{
						switch (_getch()) {
						case 72:    // key up
							tab[ypos - 1][xpos] = tab[ypos][xpos];
							tab[ypos][xpos] = t;
							ypos--;

							if ((ypos == fy) && (xpos == fx)) {
								points++;
								s = 2;
							}
							break;
						case 75:    // key left
							tab[ypos][xpos - 1] = tab[ypos][xpos];
							tab[ypos][xpos] = t;
							xpos--;

							if ((ypos == fy) && (xpos == fx)) {
								points++;
								s = 2;
							}
							break;

						case 77:    // key right
							tab[ypos][xpos + 1] = tab[ypos][xpos];
							tab[ypos][xpos] = t;
							xpos++;

							if ((ypos == fy) && (xpos == fx)) {
								points++;
								s = 2;
							}
							break;

						case 80:    // key down
							tab[ypos + 1][xpos] = tab[ypos][xpos];
							tab[ypos][xpos] = t;
							ypos++;

							if ((ypos == fy) && (xpos == fx)) {
								points++;
								s = 2;
							}
							break;
						}
					}
				}
			} while (s == 1);
		} while (g==1);
		clear();
		printf("You've been eaten by X");
		printf("\npress y to play again or press any key to end the game.");
		scanf("%c",&regame);
	} while (regame == 'y');
}
// fonction for generate the killer position randomly
void killer(int* kx, int* ky) {
	*kx = rand() % 40;
	*ky = rand() % 20;
}
//generate food position
void food(int *fx, int *fy) {
	*fx = rand() % 40;
	*fy = rand() % 20;
}
//fonction to clear the screen
void clear()
{
	system("cls");
}
