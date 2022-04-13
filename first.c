#include <stdio.h>
#include <ctype.h>
#include <string.h>


void reverse(char s[]); // reverse string if U need it(don't used in main)
void parseStr(char inp[], char res[], int pos); // fucntion taht convert a-z or 0-9 into abcd...xyz and 0123456789
char isLetter(char symbol); //check if symbol is letter 
char isNum(char symbol); // check if symbol is number
char findCharacter(char s[], int pos); // find character in sting s[] from certain position
char LetOrNum(char symbol); // check if symbol is letter(treturn 1) or number(return 2) else return 0 
void printRange(char symbol1, char symbol2); // print the range of choosen symbols; Ex: input(a-d), print(abcd)


// MAIN FUNCTION
void main(){

    char inp[999];
    char res[9999];
    printf("Write a string to parse:\n");
    scanf("%s", inp);
    parseStr(inp, res, 0);

}

void parseStr(char inp[], char res[], int pos)
{
    int letterTracker = 0; // 1 - letter; 2 - number
    int firstSymbolPos, lastSymbolPos;
    char firstSymbol, lastSymbol;

    
    firstSymbolPos = findCharacter(inp, pos);
    if(firstSymbolPos >= strlen(inp)) return;
    firstSymbol = inp[firstSymbolPos];

    letterTracker = LetOrNum(firstSymbol);
    if (!letterTracker){
        printf("Invalid character!!!");
        return;
    }

    lastSymbolPos = findCharacter(inp, firstSymbolPos + 1);
    lastSymbol = inp[lastSymbolPos];

    if( letterTracker == LetOrNum(lastSymbol)){
        printRange(firstSymbol, lastSymbol);
    } else{
        printf("Invalid input!!!");
        return;
    }   
    
    if(lastSymbolPos + 1 != '\0'){
        parseStr(inp, res, lastSymbolPos + 1);
    }
}


void printRange(char symbol1, char symbol2)
{
    int c;
    for(c = symbol1; c <= symbol2; c++){
        printf("%c", c);
    }
    putchar('\n');
}

char LetOrNum(char symbol)
{
    if( isLetter(symbol) ){
        return 1;
        
    } else if ( isNum(symbol) ){
        return 2;
    } else{
        return 0;
    }
}


char isLetter(char symbol)
{
    if( ((symbol >= 'a') && (symbol <= 'z')) || ( (symbol >= 'A') && (symbol <= 'Z') ) ){
        return 1;    
    } 
    return 0;
}

char isNum(char symbol)
{
    if ( (symbol >= '0') && (symbol <= '9')){
        return 1;
    }
    return 0;
}

char findCharacter(char s[], int pos)
{
    while (s[pos] == '-'){
        pos++;
    }
     
    return pos;
}

void reverse(char s[])
{
    int c, i, j;
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    printf("%s", s);
}