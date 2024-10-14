/*
Sales Report
Date Created: 10-9-2024
Author: Matthew Eagleman
Description: A program that gives you info about sales figures
Input: Twelve monthly sales figures
Output: Various facts about said figures
 */

#include <stdio.h>
#include <stdlib.h>

char* getMonth(int num){
    //Return the month given the number
    switch (num)
    {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    default:
        return "Error, month doesn't exist";
    }
}

int contains(float num, float *nums){
    //Return whether or not the list of numbers contains the given number
    for (int i = 0; i<12;i++){
        if (nums[i] == num){
            return 1;
        }
    }
    return 0;
}

int main(){
    //Run the program
    //Getting data from file
    FILE *inputFile;
    inputFile = fopen("inputfile.txt", "r");
    char line[12][255];
    for (int i = 0; i< 12; i++){
        fgets(line[i],255,inputFile);
    }
    fclose(inputFile);
    //Displaying the sales report--------------------------------------------
    printf("\nMonthly sales report for 2024:\n\nMonth:   Sales:\n");
    for (int i = 0; i<12; i++){
        printf("%s   %s", getMonth(i+1), line[i]);
    }
    //Displaying the min and max---------------------------------------------
    //min
    float minimum = atof(line[0]);
    int mini = 1;
    for (int i = 1; i<12; i++){
        if (atof(line[i]) < minimum){
            minimum = atof(line[i]);
            mini = i+1;
        }
    }
    //max
    float maximum = atof(line[0]);
    int maxi = 1;
    for (int i = 1; i<12; i++){
        if (atof(line[i]) > maximum){
            maximum = atof(line[i]);
            maxi = i+1;
        }
    }
    //average
    float average = atof(line[0]);
    for (int i = 1; i<12; i++){
        average = average + atof(line[i]);
    }
    average = average/12;
    //printing values
    printf("\n\nSales summery report:\n\n");
    printf("Maximum sales: %.2f (%s)\n", maximum, getMonth(maxi));
    printf("Minimum sales: %.2f (%s)\n", minimum, getMonth(mini));
    printf("Average sales: %.2f\n", average);
    //printing the moving report----------------------------------------------------------
    printf("\nSix-Month moving average report:\n\n");
    for (int i = 0; i < 7; i++){
        float newAverage = atof(line[i]);
        for (int j = 1; j<6; j++){
            newAverage += atof(line[j]);
        }
        newAverage = newAverage/6;
        printf("%s-%s   %.2f\n",getMonth(i+1),getMonth(i+6),newAverage);
    }
    //Highest to lowest-----------------------------------------------------------------
    float values[12];
    float orderedValues[12];
    float orderedMonths[12];
    //Take the list of strings and turn it into a list of numbers
    for (int i = 0;i<12;i++){
        values[i] = atof(line[i]);
    }
    //Order the list
    for (int i = 0; i<12;i++){
        float newMax = 0;
        int newI = -1;
        for (int j = 0; j<12-j;j++){
            //if the value at the current index is bigger than the current max value, and isn't already in the list of ordered values, add it.
            if (values[j]>newMax){
                if (!contains(values[j],orderedValues)){
                    newMax = values[j];
                    newI = j+1;
                }
            }
        }
        orderedValues[i] = newMax;
        orderedMonths[i] = newI;
    }
    //Print out the results
    printf("\nSales Report (highest to lowest): \n\n");
    printf("Month   Sales\n");
    for (int i = 0; i<12;i++){
        printf("%s   %f\n",getMonth(orderedMonths[i]),orderedValues[i]);
    }
    //Exiting----------------------------------------------------------------------------
    printf("\nPress enter to exit: ");
    char exit;
    scanf("%c", &exit);
    return 0;
}