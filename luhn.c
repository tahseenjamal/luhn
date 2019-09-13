#include<stdio.h>
#include<stdlib.h>

unsigned int digital_root(unsigned int number) {

  unsigned int sum = 0;

  unsigned int temp = number;

  while(number > 0) {

    sum += number % 10;

    number /= 10;

    if(sum >= 10 && number == 0) {

      number = sum;

      sum = 0;
    }

  }

  return sum;

}

unsigned int luhm(unsigned long number) {

  unsigned int checksum = number % 10;

  number /= 10;

  int index = 0;
  
  int sum = 0;

  while(number > 0) {

    sum += 9 * (  digital_root(!(index % 2) * 2 * (number % 10)) + (number % 10 ) * (index % 2) ) ;

    number /= 10;

    index++;
    
  }

  return checksum == sum % 10;

}

int main(int argv, char *argc[]) {

  unsigned long number;

  char *end;
  
  number = strtol(argc[1], &end, 10);

  printf("%d\n",luhm(number));

  return 0;

}
