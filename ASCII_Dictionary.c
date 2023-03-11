// Defines

#define _CRT_SECURE_NO_WARNINGS
#define NotaNumber 95284032
#define TAB 9
#define SPACE 32
#define lettera 97
#define letterz 122
#define letterA 65
#define letterZ 90

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Declarations:

void printMenu();
int checkString(char[]);
void printWords(char[][20],int);
void insertStrings(char[][20],int);
int getSize(int,int);
int asciiSum(char[]);
int power(int,int);
double asciiAvg(char[]);
void sortStringsLexicographic(char[][20],int);
void sortStringsByLength(char[][20],int);
void sortStringsByAsciiAvg(char[][20],int);
void sortStringsByAsciiSum(char[][20],int);
void sortEachString(char[][20],int);
void sortString(char[]);
void sortAllAsOne(char[][20],int);
void swapStrings(char[],char[]);
void swapInts(int *, int, int);
void swapDoubles(double *, int, int);
int isAlphabetic(char aArr[]);
void wrongNum();
int stringToNumConvert(char[]);
int spaceAndTabClassifier(char[]);
int isNum(char[]);
int getState();
char wordList[10][20];
int N = 0; int error = 0;
void FSM(int);

 /// Main Function
int main() {
    int state;
    while(error<5){
        if(state!=NotaNumber){
            printMenu();}
        else{
            fflush(stdin);fflush(stdout);
            printf("Please enter a number between 0 and 99:");
        }
        state = getState();
        FSM(state);
    }
     fflush(stdin);fflush(stdout);
    printf("5 errors, bye bye.");
//*/
        return 0;
}
    //Function Definitions:
//
void FSM(int a) {
    switch (a) {
        case 0:
            fflush(stdin);fflush(stdout);
            printf("You chose to end the program, bye!!!");
            exit(0);
        case 1:{
            N = getSize(2,10);
            insertStrings(wordList,N);
            break;
        }
        case 2:{
            printWords(wordList,N);
            break;
            }
        case 3:{
            sortStringsLexicographic(wordList,N);
            break;
        }
        case 4:{
            sortStringsByLength(wordList,N);
            break;
        }
        case 5:{
            sortStringsByAsciiSum(wordList,N);
            break;
        }
        case 6:{
            sortStringsByAsciiAvg(wordList,N);
            break;
        }
        case 7:{
            sortEachString(wordList,N);
            break;
        }
        case 8:{
            sortAllAsOne(wordList,N);
            break;
        }
        case NotaNumber: {
            break;
        }
        default :
            wrongNum();
    }
}
void swapStrings(char str1[], char str2[]){
    char temp[20];
    strcpy(temp,str1);
    strcpy(str1,str2);
    strcpy(str2,temp);
}
void swapInts(int * Arr, int i, int j){
    /// Swap two numerical elements in an array
    int temp = Arr[i];
    Arr[i] = Arr[j];
    Arr[j] = temp;
}
void swapDoubles(double * Arr, int i, int j){
    /// Swap two numerical elements in an array
    double temp = Arr[i];
    Arr[i] = Arr[j];
    Arr[j] = temp;
}
void printWords(char aArr[][20],int wordsCount){
    if(N==0){
        fflush(stdin);fflush(stdout);
        printf("There are no words, cannot operate.\n");
    }
    else{
    int i;
    fflush(stdin);fflush(stdout);
    printf("The words are:\n==============\n");
    if(wordsCount<10){
        for(i=0;i<wordsCount;i++) {
            printf("0%d:(ascii sum %4d, ascii avg %6.2f)%s\n", i + 1, asciiSum(aArr[i]), asciiAvg(aArr[i]), aArr[i]);
    }
    }
    else{
        for(i=0;i<wordsCount-1;i++) {
            printf("0%d:(ascii sum %4d, ascii avg %6.2f)%s\n", i + 1, asciiSum(aArr[i]), asciiAvg(aArr[i]), aArr[i]);
    }
        printf("%d:(ascii sum %4d, ascii avg %6.2f)%s\n", wordsCount, asciiSum(aArr[wordsCount-1]), asciiAvg(aArr[wordsCount-1]), aArr[wordsCount-1]);
    }
}
}
double asciiAvg(char aArr[]) {
    if (N == 0) {
        fflush(stdin);fflush(stdout);
        printf("There are no words, cannot operate.\n");
    return 0;
    } else {
        double arrLength = (double) strlen(aArr);
        double avg = 0;
        int i;
        for (i = 0; i <= arrLength; i++)
            avg += aArr[i];
        avg = avg / arrLength;
        return avg;
    }
}
int asciiSum(char aArr[]) {
    if(N==0){
        fflush(stdin);fflush(stdout);
        printf("There are no words, cannot operate.\n");
        return 0;
    }
    else{
        int arrLength = (int)strlen(aArr); int i; int sum = 0;
        for (i = 0; i <= arrLength; i++)
            sum += aArr[i];
        return sum;
    }
}
int getState(){
    int i, state,isNumCheck,hasNoMiddleSpace=0; char temp[200];
    fflush(stdin); fflush(stdout);
    fgets(temp, 199, stdin);
    for(i=0;i<strlen(temp);i++){
        if(temp[i]=='\n'){ // Deals with the issue that sometimes fgets adds '/n' at the end of a string
            temp[i]='\0';
        }}
    isNumCheck = isNum(temp);
    if(!isNumCheck){
        state = NotaNumber;
    }
    else{
        hasNoMiddleSpace = spaceAndTabClassifier(temp);
    }
    if(hasNoMiddleSpace==1){
        state = stringToNumConvert(temp);
        if(!((state<=99)&&(0<=state))) {
            state = NotaNumber;
        }
    }else{
            state = NotaNumber;
    }
    return state;
    }
int stringToNumConvert(char string[]) {
    int i, num = 0, spaceOrTab = 0, digitFound = 0;
    for (i = 0; i < strlen(string); i++) {
        if ((string[i] == TAB) || string[i] == SPACE) {
            if (digitFound == 1) {
                spaceOrTab += 1;
            }
        } else {
            digitFound = 1;
            num += (int) (power(10, (int) (strlen(string) - i - 1))) * (string[i] - 48);
        }
    }
    if (spaceOrTab > 0) {
        num = num / (int) power(10, (spaceOrTab));
    }
    return num;
}
int checkString(char aArr[]) {
    char temp[200]; int is_AlphaBetic;
    fflush(stdin); fflush(stdout);
    fgets(temp, 199, stdin);
    is_AlphaBetic = isAlphabetic(temp);
    if (20 >= strlen(temp) && is_AlphaBetic) {
        strcpy(aArr,temp);
        int k;
        for(k = 0;; k++) {
            if(aArr[k] == '\n') {
                aArr[k] = '\0';
                break;
            }
        }
        return 1;
    } else {
    }
    return 0;
}
int getSize(int min, int max) {
    char temp[200];
    int val,legit;
    memset(temp, '\0', sizeof temp);
    int flag = 1, goodNum;
    fflush(stdin);fflush(stdout);
    printf("Enter new word count,\n");
    while (flag) {
        fflush(stdin);fflush(stdout);
        printf("Please enter a number between %d and %d:", min, max);
        fflush(stdin); fflush(stdout);
        fgets(temp, 199, stdin);
        temp[strlen(temp)-1] = '\0'; // fgets adds extra '\n' to any user input.
        val = stringToNumConvert(temp);
        legit = spaceAndTabClassifier(temp);
        if (((min <= val) && (val <= max))&&legit) {
            goodNum = val;
            flag = 0;
        }
    }
    return goodNum;
}
void sortString(char aArr[]){
    /// Performed as Heap Sort algorithm
    int num,i,j,root,x; char t;
    num = (int)strlen(aArr);
// build max heap
    for(i=0;i<num;i++)
    {
        x=i;
        do
        {
            root = (x - 1) / 2;
            if (aArr[root] < aArr[x])
            {
                t = aArr[root];
                aArr[root] = aArr[x];
                aArr[x] = t;
            }
            x = root;
        } while (x != 0);
    }
    for (j = num - 1; j >= 0; j--)
    {
        t = aArr[0];
        aArr[0] = aArr[j];
        aArr[j] = t;
        root = 0;
        do
        {
            x = 2 * root + 1;
            if ((aArr[x] < aArr[x + 1]) && x < j-1)
                x++;
            if (aArr[root]<aArr[x] && x<j)
            {
                t = aArr[root];
                aArr[root] = aArr[x];
                aArr[x] = t;
            }
            root = x;
        } while (x < j);
    }
    }
void printMenu(){
    fflush(stdin);fflush(stdout);
    printf("The menu:\n"
           "=========\n"
           "0. Exit\n"
           "1. Insert words\n"
           "2. Print words\n"
           "3. Sort words lexicographic\n"
           "4. Sort words by length\n"
           "5. Sort words by ascii sum\n"
           "6. Sort words by ascii average\n"
           "7. Sort each word by ascii\n"
           "8. Sort all words as one\n"
           "Please enter a number between 0 and 99:");
}
void sortStringsByAsciiSum(char aArr[][20],int aLength) {
    if (N == 0) {
        fflush(stdin); fflush(stdout);
        printf("There are no words, cannot operate.\n");
    } else {
        int words = aLength;
        int i,j;
        int sumsArr[words];
        for (i = 0; i < words; i++) {
            sumsArr[i] = asciiSum(aArr[i]);
        }
    /// Bubble Sort:
    for (i = 0; i < words - 1; i++) {
        for (j = 0; j < words - i - 1; j++) {
            if (sumsArr[j] > sumsArr[j + 1]) {
                swapStrings(aArr[j], aArr[j + 1]);
                swapInts(sumsArr, j, j + 1);
            }
        }
    }
    }
}
void sortStringsByAsciiAvg(char aArr[][20],int aLength){
    if(N==0){
        fflush(stdin);fflush(stdout);
        printf("There are no words, cannot operate.\n");
    }
    else {
        int words = aLength;
        int i, j;
        double avgsArr[words];
        for (i = 0; i < words; i++) {
            avgsArr[i] = asciiAvg(aArr[i]);
        }
        /// Bubble Sort:
        for (i = 0; i < words-1; i++) {
            for (j = 0; j < words - i - 1; j++) {
                if (avgsArr[j] > avgsArr[j+1]) {
                    swapStrings(aArr[j], aArr[j+1]);
                    swapDoubles(avgsArr, j, j+1);
                }
            }
        }
    }
}
void sortStringsByLength(char aArr[][20],int aLength){
    if(N==0){
        fflush(stdin);fflush(stdout);
        printf("There are no words, cannot operate.\n");
    }
    else {
        int words = aLength;
        int i, j;
        int LengthsArr[words];
        for (i = 0; i < words; i++) {
            LengthsArr[i] = (int) strlen(aArr[i]);
        }
        /// Bubble Sort
        for (i = 0; i < words-1; i++) {
            for (j = 0; j < words-i-1; j++) {
                if (LengthsArr[j] > LengthsArr[j+1]) {
                    swapStrings(aArr[j], aArr[j+1]);
                    swapInts(LengthsArr, j, j+1);
                }
            }
        }
    }
}
void wrongNum(){
    error += 1;
    if(error<5) {
        fflush(stdin);fflush(stdout);
        printf("You made %d errors from 5, try again,\n", error);
    }
}
int power(int a,int b){ // Compute a^b
    int i,result=1;
    for(i=b;i>0;i--){
        result *= a;
    }
    return result;
}
int isNum(char num[]) {
    int isNum=1, i;
    for(i=0;i<strlen(num);i++){
        if (!(((48 <= num[i]) && (num[i] <= 57))||(num[i]==TAB)||(num[i]==SPACE))) {
            isNum = 0;
            break;
        }
            }
    return isNum;
}
int spaceAndTabClassifier(char aArr[]) {
    int i=0, j=0, k=0, digitStart = 0, digitEnd = 0, legitSpaceAndTabs = 1;
    while ((digitStart == 0)&&(i<strlen(aArr))) {
        for (i = 0; i < strlen(aArr); i++) {
            if ((aArr[i] != TAB) && (aArr[i] != SPACE)) {
                digitStart = 1;
                break;
            }
        }
    }
    while ((digitStart == 1 && digitEnd == 0)&&(j<strlen(aArr))) {
        for (j = i+1; i < strlen(aArr); j++) {
            if ((aArr[j] == TAB) || (aArr[j] == SPACE) || (aArr[j]=='\0')) {
                digitEnd = 1;
                break;
            }
        }
    }
    while ((digitEnd == 1)&&(k<strlen(aArr))) {
        for (k = j+1; k < strlen(aArr); k++) {
            if ((aArr[k] != TAB) && (aArr[k] != SPACE)) {
                legitSpaceAndTabs = 0;
                digitEnd=0;
                break;
            }
        }
    }
    return legitSpaceAndTabs;
}
void sortStringsLexicographic(char aArr[][20],int aLength){
    if(N==0){
        fflush(stdin);fflush(stdout);
        printf("There are no words, cannot operate.\n");
    }
    else {
        int words = aLength;
        int i, j;
        char temp[20];
        for (i = 0; i < words-1; i++) {
            for (j = 0; j < words-i-1; j++) {
                if (strcmp(aArr[j], aArr[j+1]) > 0) {
                    strcpy(temp, aArr[j]);
                    strcpy(aArr[j], aArr[j+1]);
                    strcpy(aArr[j+1], temp);
                }
            }
        }

    }
}
void sortEachString(char aArr[][20],int aLength){
    if(N==0){
        fflush(stdin);fflush(stdout);
        printf("There are no words, cannot operate.\n");
    }
    else {
        int words = aLength;
        int i, j, k;
        char temp;
        for (i = 0; i < words; i++) {
            for (j = 0; j < 20; j++) {
                for (k = j + 1; k < 20; k++) {
                    if (aArr[i][k] == 0)
                        break;
                    if (aArr[i][j] > aArr[i][k]) {
                        temp = aArr[i][j];
                        aArr[i][j] = aArr[i][k];
                        aArr[i][k] = temp;
                    }
                }
            }
        }
    }
}
int isAlphabetic(char aArr[]){
    int i, is_Alphabetic = 1;
    for (i = 0; i < strlen(aArr) - 1; i++) {
        if (!(((lettera <= aArr[i]) && (aArr[i] <= letterz)) || (letterA <= aArr[i]) && (aArr[i] <= letterZ))) {
            is_Alphabetic = 0;
            break;
        }
    }
    if (is_Alphabetic) {
        return 1;
    } else {
    }
    return 0;

}
void insertStrings(char aArr[][20], int aLength){
    int i=0; int validityBits[10]={0};
    N = aLength;
    while(i<N){
        fflush(stdin);fflush(stdout);
        printf("Please enter word #%d:\n",i+1);
        x:
        validityBits[i] = checkString(aArr[i]);
        if(validityBits[i]==1){
            i++;
            }
        else{
            fflush(stdin);fflush(stdout);
            printf("Wrong input, try again:\n");
            goto x;
        }
        }
    }
void sortAllAsOne(char aArr[][20], int aLength){
    if(N==0){
        fflush(stdin);fflush(stdout);
        printf("There are no words, cannot operate.\n");
    }
    else {
        int words = aLength;
        int i, j, k = 0;
        char temp[20*words];
        memset(temp, '\0', sizeof temp);
        while (k < 200) {
            for (i = 0; i < words; i++) {
                for (j = 0; j < 20; j++) {
                    if (aArr[i][j] == '\0')
                        break;
                    temp[k] = aArr[i][j];
                    k++;
                }
            }
            k = 200;
        }
        sortString(temp);
        k = 0;
        while ((k < 200 )) {
            for (i = 0; i < words; i++) {
                for (j = 0; j < 20; j++) {
                    if (aArr[i][j] == '\0') {
                        break;
                    }
                    aArr[i][j] = temp[k];
                    k++;
                }
            }
            k = 200;
        }
    }
    }
//
