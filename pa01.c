/*=============================================================================
| Assignment: pa01 - Encrypting a plaintext file using the Vigenere cipher
|
| Author: Yuyang Zhang
| Language: c
|
| To Compile: gcc -o pa01 pa01.c
|
| To Execute: c -> ./pa01 k2.txt p2.txt
| where k2.txt is the keytext file
| and p2.txt is plaintext file
|
| Note: All input files are simple 8 bit ASCII input
|
| Class: CIS3360 - Security in Computing - Spring 2022
| Instructor: McAlpin
| Due Date: Feb 27
|
+=============================================================================*/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int * changeint(char * arr);
char * changechar(int * array);

int main()
{
    char ktext[1000] = "";
    char ptext[1000] =  "";
    char key[512], key1[512];
    char plain[512], plain1[512];
    char * result;
    int * key2;
    int * plain2;
    int result1[512] = {0};
    int key3[512] = {0};


    //key
    FILE *fptr1 = fopen("p1.txt", "r");
    if(fptr1 == NULL)
	{
		printf("file was not successful in opening.");
		printf("Program will now terminate.\n");
		exit(1);
	}

    fgets(ktext, 1000, fptr1);
    fclose(fptr1);

    int count1 = 0;
    for(int i = 0; i < strlen(ktext); i++)
    {
        if (isalpha(ktext[i]))
        {
            key[count1] = ktext[i];
            count1++;
        }
    }
    for(int j = 0; j < count1; j++)
        key1[j] = tolower(key[j]);

    printf("Vigenere key:\n\n");
    for(int i = 0; i < count1; i++)
    {
        if(i % 80 == 0)
            printf("\n");
        printf("%c", key1[i]);
    }

    printf("\n\n\n");
    for(int i = 1; i < 512/count1; i++)
    {
        for (int j = 0; j < count1; j++)
            key1[i * count1 + j] = key1[j];
    }
    for(int i = 0; i < 512 % count1; i++)
        key1[(512/count1) * count1 + i] = key1[i];


    //plaintext
    FILE *fptr2 = fopen("p2.txt", "r");
    if(fptr2 == NULL)
	{
		printf("file was not successful in opening.\n");
		printf("Program will now terminate.\n");
		exit(1);
	}
    fgets(ptext, 1000, fptr2);
    fclose(fptr2);

    int count2 = 0;
    for(int i = 0; i < strlen(ptext); i++)
    {
        if (isalpha(ptext[i]))
        {
            plain[count2] = ptext[i];
            count2++;
        }
    }
    for(int j = 0; j < count2; j++)
        plain1[j] = tolower(plain[j]);
    plain1[count2] = '\0';


    for(int i = strlen(plain1); i < 512; i++)
        plain1[i] = 'x';

    printf("Plaintext:\n\n");
    for(int i = 0; i < 512; i++)
    {
        if(i % 80 == 0)
            printf("\n");
        printf("%c", plain1[i]);
    }
    printf("\n\n\n");


    //change
    key2 = changeint(key1);
    for(int i = 0; i < 512; i++)
        key3[i] = key2[i];
    plain2 = changeint(plain1);

    for(int i = 0; i < 512; i++)
    {
        result1[i] = key3[i] + plain2[i];
        if(result1[i] > 25)
            result1[i] = (result1[i] % 26);
    }

    result = changechar(result1);
    printf("Ciphertext:\n\n");
    for(int i = 0; i < 512; i++)
    {
        if(i % 80 == 0)
            printf("\n");
        printf("%c", result[i]);
    }
    printf("\n");


    return 0;
}


int * changeint(char * arr)
{
    static int num[512];
    for(int i = 0; i < 512; i++)
    {
        if(arr[i] == 'a')
            num[i] = 0;
        else if(arr[i] == 'b')
            num[i] = 1;
        else if(arr[i] == 'c')
            num[i] = 2;
        else if(arr[i] == 'd')
            num[i] = 3;
        else if(arr[i] == 'e')
            num[i] = 4;
        else if(arr[i] == 'f')
            num[i] = 5;
        else if(arr[i] == 'g')
            num[i] = 6;
        else if(arr[i] == 'h')
            num[i] = 7;
        else if(arr[i] == 'i')
            num[i] = 8;
        else if(arr[i] == 'j')
            num[i] = 9;
        else if(arr[i] == 'k')
            num[i] = 10;
        else if(arr[i] == 'l')
            num[i] = 11;
        else if(arr[i] == 'm')
            num[i] = 12;
        else if(arr[i] == 'n')
            num[i] = 13;
        else if(arr[i] == 'o')
            num[i] = 14;
        else if(arr[i] == 'p')
            num[i] = 15;
        else if(arr[i] == 'q')
            num[i] = 16;
        else if(arr[i] == 'r')
            num[i] = 17;
        else if(arr[i] == 's')
            num[i] = 18;
        else if(arr[i] == 't')
            num[i] = 19;
        else if(arr[i] == 'u')
            num[i] = 20;
        else if(arr[i] == 'v')
            num[i] = 21;
        else if(arr[i] == 'w')
            num[i] = 22;
        else if(arr[i] == 'x')
            num[i] = 23;
        else if(arr[i] == 'y')
            num[i] = 24;
        else if(arr[i] == 'z')
            num[i] = 25;
    }
    return num;
}

char * changechar(int * array)
{
    static char arr[512];
    for(int i = 0; i < 512; i++)
    {
        if(array[i] == 0)
            arr[i] = 'a';
        else if(array[i] == 1)
            arr[i] = 'b';
        else if(array[i] == 2)
            arr[i] = 'c';
        else if(array[i] == 3)
            arr[i] = 'd';
        else if(array[i] == 4)
            arr[i] = 'e';
        else if(array[i] == 5)
            arr[i] = 'f';
        else if(array[i] == 6)
            arr[i] = 'g';
        else if(array[i] == 7)
            arr[i] = 'h';
        else if(array[i] == 8)
            arr[i] = 'i';
        else if(array[i] == 9)
            arr[i] = 'j';
        else if(array[i] == 10)
            arr[i] = 'k';
        else if(array[i] == 11)
            arr[i] = 'l';
        else if(array[i] == 12)
            arr[i] = 'm';
        else if(array[i] == 13)
            arr[i] = 'n';
        else if(array[i] == 14)
            arr[i] = 'o';
        else if(array[i] == 15)
            arr[i] = 'p';
        else if(array[i] == 16)
            arr[i] = 'q';
        else if(array[i] == 17)
            arr[i] = 'r';
        else if(array[i] == 18)
            arr[i] = 's';
        else if(array[i] == 19)
            arr[i] = 't';
        else if(array[i] == 20)
            arr[i] = 'u';
        else if(array[i] == 21)
            arr[i] = 'v';
        else if(array[i] == 22)
            arr[i] = 'w';
        else if(array[i] == 23)
            arr[i] = 'x';
        else if(array[i] == 24)
            arr[i] = 'y';
        else if(array[i] == 25)
            arr[i] = 'z';
    }
    return arr;
}






/*=============================================================================
| I Yuyang Zhang (4238503) affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
+=============================================================================*/
