# Lexer
My Ds Mini Project implemented in C.


A lexer is a first step of a compiler. The basic task of a lexer is to divide the given program into tokens.
Tokens are nothing but different types of entitites in a basic programming language.
They are generally 
1. Identifiers i.e. variables
2. Keywords (for C there are 32 keywords)
3. Separator	i.e. }, (, ;
4. Operator	i.e. +, <, =
5. Literal	(contansts ,strings)
6. Comments (Single and multi line)


My code here divides the given program into these above mentioned tokens and displays it.
Also , parenthesis checker is added for incresed functionality.


Demo Input:<br>
#include<stdio.h><br>
#include<conio.h><br>
int main()<br>
{<br>
int n=500;int i=20;<br>
printf("the value is 5");<br>
if(i>10)<br>
    i++;<br>
else<br>
    i--;<br>
printf("%d is the value of i",i);<br>
return 0;<br>
<br>
}<br>

Output:


![capture](https://user-images.githubusercontent.com/27052899/32080975-4cb28ff2-bad0-11e7-96c2-4157119312ee.JPG)
