#include <stdio.h>
#include <stdlib.h>
int counter(int val)
{
	/*
	Takes in the current card value and returns 0,1,or -1 depending on what the value is
	based on certain cards increasing likelihood of success and others reducing it.
	*/
	if ((val>2) && (val<7)) {
		return 1;
	} else if (val == 10) {
		return -1;
	}
	else {
		return 0;
	}
}

int newVal(char cardName[]) {
	/*
	Takes the card name character and determines the value of the card as a result.
	Returns an integer denoting the value of the card, or returns 0 if the card isn't recognized.
	*/
	int val = 0;
	switch(cardName[0]) {
		case 'K':
		case 'Q':
		case 'J':
			return 10;
		case 'A':
			return 11;
		case 'X':
			return 0;
		default:
			val = atoi(cardName);
			if((val<1) || (val>10)) {
				puts("I don't understand that value!");
				return 0;
			}
			return atoi(cardName);
	}
}

int main()
{
	/*
	Main function responsible for gathering user input for what card was just played
	and returns what the current count of the table is.
	*/
	char card_name[3];
	int count = 0;
	while(card_name[0]!='X') {
		puts("Enter the card_name: ");
		scanf("%2s", card_name);
		int val = 0;
		val += newVal(card_name);
		count += counter(val);
		printf("Current count: %i\n", count);
	}
	return 0;
}
