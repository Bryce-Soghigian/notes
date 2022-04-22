#include <stdio.h>

int main(){
int ages[] = {25,21,21,22,23};
char greetings[] = "Hello World!";
printf("%s",greetings);
for(int i = 0;i < 5;i++){
	printf("The users age is %d\n", ages[i]);
}
return 0;
}
