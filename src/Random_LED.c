#include <stdio.h> 
#include <stdlib.h>
//#include <time.h>

#define GPIO_PORTF_DATA_R (*((volatile unsigned long*)0x400253FC))//Bit specific addressing use just for data  register. 0x3fc access to all 8bits
#define GPIO_PORTF_DIR_R (*((volatile unsigned long*)0x40025400))//Search for GPIODIR
#define GPIO_PORTF_PUR_R (*((volatile unsigned long*)0x40025510))//Search for GPIOPUR
#define GPIO_PORTF_DEN_R (*((volatile unsigned long*)0x4002551C))//Search for GPIODEN	   //32 bit address in hex 
#define SYSCTL_RCGC2_R (*((volatile unsigned long*)0x400FE108))//Search for RCGC2  //variable name references that 32 bit address
	

unsigned long Input; // Input from PF4 (SW#1)
int temp; 

int randInt(){
	  return rand() % 6 + 1;
}


int main(void){
SYSCTL_RCGC2_R = 0x00000020; // Activate clock for Port F	-> Register 5

GPIO_PORTF_DIR_R = 0x0E; // Enable PF4 (SW1) as input, PF3, PF2, PF1 as outputs 
GPIO_PORTF_PUR_R = 0x10; // Enable pull-up (inputs) PF4 (SW1): 0x10 
GPIO_PORTF_DEN_R = 0x1E; // Enable digital I/O. Red_Green_Blue (SW1): 0x1E 

	
while(1){
        Input = GPIO_PORTF_DATA_R & 0x10; // Read SW1 into Input

        if (Input == 0) {   
					temp = randInt();
					if(temp == 1) GPIO_PORTF_DATA_R = 0x02;  //turn RED 
					else if (temp == 2) GPIO_PORTF_DATA_R = 0x04;  //turn BLUE
					else if (temp == 3) GPIO_PORTF_DATA_R = 0x06;  //turn MAGENTA
					else if (temp == 4) GPIO_PORTF_DATA_R = 0x08;  //turn GREEN
					else if (temp == 5) GPIO_PORTF_DATA_R = 0x0A;  //turn YELLOW
					else if (temp == 6) GPIO_PORTF_DATA_R = 0x0C;  //turn CYAN
					
					while((GPIO_PORTF_DATA_R & 0x10) == 0);        // wait for release
        }
			  	else {
					GPIO_PORTF_DATA_R = 0x00;  //turn off
        }
    } // end while

}
