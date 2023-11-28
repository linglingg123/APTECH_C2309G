#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own 
getch, system("pause") or input loop */

void mang2chieu(){
	
}

int main(int argc, char *argv[]) {
	//gan gia tri cho toan bo cac ptu trong mang
	int a[4][1];
	int x, y; int count=0;
	for(x=0; x<=4; x++){ //x=hang
		for(y=0; y<=1; y++){ //y=cot
			a[x][y]=count;
			count++;
			if(y==0){
				printf("[%d]", a[x][y]);
			}
			if(y==1){
				printf("[%d] \n", a[x][y]);
			}
		}
	}
	return 0;
}
