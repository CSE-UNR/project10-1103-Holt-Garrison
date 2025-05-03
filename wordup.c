// Garrison Holt
// 04/25/25
// project 10 - wordup.c

#include <stdio.h>
#define CAP 7
#define FILENAME "word.txt"

void getword(int lenght, char array[]);
void getguess(int* guess, int length, char array[]);
void validateguess(int* guess, int length, char array[]);
void makelower(int length, char array[]); 
void checkguess(int* game, int row, int col, char array1[], char array2[], char array3[][col], char array4[][col]);
void display(int row, int col, char pastG[][col], char[][col]);
void gameend(int end, int guess);


int main(){
	char guess[CAP], word[CAP], pastG[6][CAP], CL[6][CAP];
	int num = 0, again = 1, lose = 0;	
	getword(CAP, word);
	while(again == 1 && num <= 5){
		getguess(&num, CAP, guess);
		validateguess(&num, CAP, guess);
		makelower(CAP, guess);	
		checkguess(&again, num, CAP, guess, word, pastG, CL);
		if(again != 0){
			display(num+1, CAP, pastG, CL);
		}
		num++;
		if(again == 0){
			lose = 0;
		}else if(num > 5){
			again = 0;
			lose = 1;
			
		}	
	}
	gameend(lose, num);
	return 0;
}
	
void getword(int length, char array[]){
	FILE* readfileptr;
	readfileptr = fopen(FILENAME, "r");
	if(readfileptr == NULL){
		printf("Cannot open file for reading.\n");
		return;
	}
	fgets(array, length, readfileptr);
}

void getguess(int* guess, int length, char array[]){
	if(*guess == 5){
	printf("GUESS FINAL! Enter your guess: ");
	}
	else{
		printf("GUESS %d! Enter your guess: ", *guess+1);
	}
	
	fgets(array, length, stdin);
	
}
void validateguess(int* guess, int length, char array[]){
	int  count;
	for(count = 0; array[count] != '\0'; count++){
		}
	while(count != 6 ){
		count = 0;

		printf("Your guess must be 5 letters long.\n");
		printf("Please try again: ");
		fgets(array, length, stdin);
		for(count = 0; array[count] != '\0'; count++){
		}
	}
	for(int i = 0; i < count-1; i++){
		if (!((array[i] >= 'A' && array[i] <= 'Z') || (array[i] >= 'a' && array[i] <= 'z'))){
			printf("Your guess must contain only letters.\n");
			printf("Please try again: ");
			fgets(array, length, stdin);
		}
	}
	
}
	
void makelower(int lenth , char array[]){
	for(int x = 0; x<lenth; x++){
		if(array[x] >= 'A' && array[x] <= 'Z'){
			array[x] += 32;
		}
	}
}

void checkguess(int* game, int row, int col, char array1[], char array2[], char array3[][col], char array4[][col]){
	*game = 0; 
	for (int i = 0; i < col - 2; i++) {
		array3[row][i] = array1[i];
		if (array1[i] == array2[i]) {
			array3[row][i] = array1[i] - 32; 
			array4[row][i] = ' ';
		} else {
			array4[row][i] = ' '; 
			for (int j = 0; j < col - 2; j++) {
				if (array1[i] == array2[j] && array1[i] != array2[i]) {
					array4[row][i] = '^'; 
					j = col - 2;
				}
			}
			*game = 1;
		}
	}
	array3[row][col - 1] = '\0';
	array4[row][col - 1] = '\0';
}

void display(int row, int col, char array3[][col], char array4[][col]){
	printf("================================\n");
	for(int i = 0; i < row; i++){
		printf("%s\n", array3[i]);
		printf("%s\n", array4[i]);
	}
}
void gameend(int end, int guess){
	printf("================================\n");
	if(end == 0){
		switch(guess){
			case 1:
				printf("\t\tgoat!\n");
				break;
			case 2:
			case 3:
				printf("\t\tamazing!\n");
				break;
			case 4:
			case 5:
				printf("\t\tnice!\n");
				break;
			case 6:
		}
		printf("\tYou won in %d guesses!\n", guess);
	}
	else{
	printf("You lost, better luck next time!\n");
	}
}	
