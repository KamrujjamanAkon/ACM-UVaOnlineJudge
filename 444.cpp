#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	char inp [1000], val [10];
	int len, i, res;

	while ( gets (inp )) {
		if ( inp [0] > 47 && inp [0] < 58 ) {
			i = strlen (inp) - 1;

			while ( i >= 0 ) {
				val [0] =inp [i]; 
				val [1] = '\0';
				res = atoi (val);
				if ( res < 3 ) {
					val [0] = inp [i];
					val [1] = inp [i - 1];
					val [2] = inp [i - 2];
					val [3] = '\0';
					i -= 3;
					res = atoi (val);
				}

				else {
					val [0] = inp [i];
					val [1] = inp [i - 1];
					val [2] = '\0';
					i -= 2;
					res = atoi (val);
				}
				printf("%c", res);
			}
		}


		else {
			len = strlen (inp); 

			for ( i = len - 1; i >= 0; i-- ) {
				res = inp [i];
				while ( res ) {
					printf("%d", res % 10);
					res /= 10;
				}
			}
		}
		printf("\n");
	}
	return 0;
}