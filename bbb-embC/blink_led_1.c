/*
 * Name: Hai Dang (danghai@pdx.edu)
 * blink_led_1.c: blinking LED in 1s by writting directly to system bbb
 */
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define LED_ON  "1"
#define LED_OFF "0"
int main()
{
	/* USR1 LED path in system */
	const char *LED_brightness = "/sys/class/leds/beaglebone:green:usr1/brightness";
	/* Initial LED_status OFF*/
	char LED_status[] = LED_OFF;
	char LED_string[] = "LED OFF"; /* For debug*/
	FILE *inputFp;

	for(;;)
	{
		/* Open the file */
		inputFp = fopen(LED_brightness,"r+");
		if(inputFp == NULL)
		{
			perror("Error opening file ! ");
			fclose(inputFp);
			exit(-1);
		}
		/* Toogle LED USR1  */
		if(strcmp(LED_status,LED_ON)==0)    // 0 -> ON
	 	{
			strcpy(LED_status,LED_OFF); // Blink
			strcpy(LED_string,"LED OFF");
		}
		else
		{
			strcpy(LED_status,LED_ON);
			strcpy(LED_string,"LED ON");
		}
		/* Write value to LED*/
		fwrite(LED_status,sizeof(char),1,inputFp);
		printf("Debug: %s \n",LED_string);
		sleep(1);
		fclose(inputFp);		
	}

	fclose(inputFp);
	return 0;

}
