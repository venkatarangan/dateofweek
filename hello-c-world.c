#include <stdio.h>


//Quick n Dirty implementation of Tomohiko Sakamoto's Algorithm for finding day of the week using C language
int dow(int y, int m, int d) {
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	y -= m < 3;
	return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

//Prompt a string and accept an integer from console
int GetInteger ( char *DisplayName ) {
	int TempValue;
	printf ( "%s", DisplayName );
	while ( scanf ( "%d", &TempValue ) != 1 )
    {
        printf ( "%s", DisplayName );
        while ( getchar() != '\n' );
    }
    return TempValue;

}

int main() {
	
	int year	= 2017;
	int month	= 4;
	int date	= 13;

	const char * DayNames[] = {
    	"Sunday",
    	"Monday",
    	"Tuesday",
    	"Wednesday",
    	"Thursday",
    	"Friday",
    	"Saturday",
	};


	date		= GetInteger ("Enter a Date:");
	month		= GetInteger ("Enter a Month:");
	year		= GetInteger ("Enter a Year:");

    int myDoW	= dow ( year, month, date ); 
	char str [10];

	printf ("Date in YYYY-MM-YY is: %i-%i-%i \n", year, month, date);
	printf ("Day of the week in number: %i \n", myDoW);
	printf ("Day of the week in words: %s \n",  DayNames[myDoW]);
	printf ("Type any character & <ENTER> to quit: ");
	scanf ("%s", str);
	
    // printf("Hello World!\n");
    
    return 0;   
}
