/*=============================================================================
| Assignment: pa02 - Calculating an 8, 16, or 32 bit
| checksum on an ASCII input file
|
| Author: Yuyang Zhang
| Language: c
|
| To Compile: javac pa02.java
| gcc -o pa02 pa02.c
| g++ -o pa02 pa02.cpp
| go build pa02.go
| python pa02.py //Caution - expecting input parameters
|
| To Execute:
| c -> ./pa02 inputFile.txt 8
|
| where inputFile.txt is an ASCII input file
| and the number 8 could also be 16 or 32
| which are the valid checksum sizes, all
| other values are rejected with an error message
| and program termination
|
| Note: All input files are simple 8 bit ASCII input
|
| Class: CIS3360 - Security in Computing - Spring 2022
| Instructor: McAlpin
| Due Date: per assignment
|
+=============================================================================*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

char * inttohex(int a);

int main(int argc, char * argv[])
{
    int digit = atoi(argv[2]);
    char text[1000] = "";
    char * ans;
    char * ans1;
    char * ans2;
    char * ans3;
    char * ans4;
    char * ans5;
    char * ans6;

    FILE *file = fopen(argv[1], "r" );

    if(file == NULL)
	{
		printf("file was not successful in opening.");
		printf("Program will now terminate.\n");
		exit(1);
	}

	fgets(text, 1000, file);
	fclose(file);

	int count = strlen(text);

    if(digit == 8)
    {
        int sum = 0;
        for(int h = 0; h < strlen(text); h++)
           sum = (unsigned char)text[h] + sum;

        int sum1 = sum % 256;
        ans = inttohex(sum1);
    }
    else if(digit == 16)
    {
        int suml = 0, sumh = 0;
        char ans11[5] = "";
        int b = (count) % 2;

        if(b == 1)
             strcat(text, "X");

        for(int j = 0; j < strlen(text); j = j + 2)
        {
            sumh = (unsigned char)text[j] + sumh;
            suml = (unsigned char)text[j + 1] + suml;
        }

        sumh = (sumh + suml / 256) % 256;
        suml = (suml) % 256;

        ans1 = inttohex (sumh);
        strcpy(ans11, ans1);
        ans2 = inttohex (suml);
        ans = strcat(ans11, ans2);
    }
    else if(digit == 32)
    {
        int sum3 = 0, sum4 = 0, sum5 = 0, sum6 = 0;
        char ans21[5] = "", ans22[5] = "",ans23[5] = "";
        int c = count % 4;

        if(c == 1)
            strcat(text, "XXX");
        if(c == 2)
            strcat(text, "XX");
        if(c == 3)
            strcat(text, "X");

        for(int k = 0; k < strlen(text); k = k + 4)
        {
            sum3 = (unsigned char)text[k] + sum3;
            sum4 = (unsigned char)text[k + 1] + sum4;
            sum5 = (unsigned char)text[k + 2] + sum5;
            sum6 = (unsigned char)text[k + 3] + sum6;
        }
        sum3 = (sum3 + (sum4 + (sum5 + sum6/256)/256)/256)%256;
        sum4 = (sum4 + (sum5 + sum6/256)/256)%256;
        sum5 = (sum5 + sum6 / 256) % 256;
        sum6 = (sum6) % 256;

        ans3 =  inttohex (sum3);
        strcpy(ans21, ans3);
        ans4 =  inttohex (sum4);
        strcpy(ans22, ans4);
        ans5 =  inttohex (sum5);
        strcpy(ans23, ans5);
        ans6 =  inttohex (sum6);
        ans = strcat(strcat(ans21, ans22), strcat(ans23, ans6));
    }
    else
        printf("Valid checksum sizes are 8, 16, or 32\n");

    if(digit == 8 || digit == 16 || digit == 32)
    {
        for(int i = 0; i < strlen(text); i++)
        {
            if(i % 79 == 0)
                printf("\n");
            printf("%c", text[i]);
        }

        int length = strlen(text);
        if(ans[0] == '0')
            ans[0] = ' ';
        printf("\n");
        printf("%2d bit checksum is %8s for all %4d chars\n", digit, ans, length);
    }

    return 0;
}


char * inttohex(int  a)
{
    static char buffer[3];

    if(a / 16 < 10)
        buffer[0] = a / 16 +  '0' ;
    else
        buffer[0] = a / 16 - 10 +  'a' ;
    if(a % 16 < 10)
        buffer[1] = a % 16 +  '0' ;
    else
        buffer[1] = a % 16 - 10 +  'a' ;

    buffer[2] =  '\0' ;

    return buffer;
}

/*=============================================================================
| I Yuyang Zhang (4238503) affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
+=============================================================================*/
