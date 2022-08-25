
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//Declaring the title variables
    #define title "DECIMAL TO RADIX-i converter"
    #define name "Luke Carter"
    #define date "2022" 


char * Dec2RadixI(int decValue, int radValue, char str[])
{   
    int in = 0; //defining the index if the array
    int val;

    while (decValue >0)
    {
        //continous dividing decValue by base and using its remainder
        val = decValue % radValue;
        if (val>=0 && val<=9)
        {
            val+='0';
        }
        else
        {
            val+=-10+'A';
        }

        str[in++]=val;
        decValue/=radValue;
        
    }
    str[in]='\0';

    //result in wrong order, needs to be reversed before returning
    //process done by temporarily setting the end values to each other and
    //gradually moving inwards using a for loop
    int length = strlen(str);
    for(int k =0; k< length/2;k++)
    {
        char temp = str[k];
        str[k]=str[length-k-1];
        str[length-k-1]=temp;  
    }

    return str;


}





int main(void)
{

    //printing the title varbiables in the format given
    printf("*****************************\n");
    printf(" %s\n Written by: ",title);
    printf("%s\n Date: ",name);
    printf("%s\n*****************************",date);

    //Declaring varibales
    int i,f;
    i=0;
    f=0;

    //creating a do while loop to repeat the following code until a condition is met
    do
    {   
        //getting the value for the decimal number
        printf("\nEnter a decimal number: ");
        scanf("%d",&i);
        if (i>=0)
        {   
            //getting the value for the radix number but only after checking that i>=0
            //as the program should end
            printf("The number you have entered is %d",i);
            printf("\nEnter a radix for the converter between 2 and 16: ");
            scanf("%d",&f);
            if (f>=0)
                //displaying the radix number after checking it is positive
                printf("The radix you have entered is %d",f);  
                //calculatin the log2 of the decimal number
                printf("\nThe log2 of the number is %.2f",log2(i));
                float x=i/f;
                float z=i%f;
                //calculating the division of the two numbers and then the remainder
                printf("\nThe integer result of the number divided by %d is %.0f",f,x);
                printf("\nThe remainder is %.0f",z);

                //defining the array and then calling the function to call the Dec2RadiaxI function
                char str[100];
                printf("\nThe radix-2 value %s",Dec2RadixI(i,f, str));
            }
        }
    //end of the do while loop condition with the EXIT clause 
    while((f>=0)&&(i>=0) );
    printf("EXIT");
}   