#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define bool int
int tt;
struct node
{
char data;
struct node *next;
};
 struct node *root1=NULL,*root2=NULL;
 struct node1 *root3=NULL;
 struct node2 *root4=NULL,*root5=NULL;

void insert_end(struct node** head_ref, char new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
 struct node *last = *head_ref;

new_node->data=new_data;

    new_node->next = NULL;
if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
    while (last->next != NULL)
        last = last->next;
  last->next = new_node;
    return;
}

void print(struct node *start)
{
struct node *ptr;
ptr = start;
while(ptr != NULL)
{
printf("%c,", ptr -> data);
ptr = ptr -> next;
}

return start;
}

struct node1
{
int data;
struct node *next;
};

void insert_end1(struct node1** head_ref, int new_data)
{
    struct node1* new_node = (struct node1*) malloc(sizeof(struct node1));
 struct node1 *last = *head_ref;

new_node->data=new_data;

    new_node->next = NULL;
if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
    while (last->next != NULL)
        last = last->next;
  last->next = new_node;
    return;
}

void print1(struct node1 *start)
{
struct node1 *ptr;
ptr = start;
while(ptr != NULL)
{
printf("%d,", ptr -> data);
ptr = ptr -> next;
}
}

struct node2
{
char *data;
struct node *next;
};

void insert_end2(struct node2** head_ref, char *new_data)
{
    struct node2* new_node = (struct node2*) malloc(sizeof(struct node2));
 struct node2 *last = *head_ref;
new_node->data=strdup(new_data);
new_node->next = NULL;
if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
    while (last->next != NULL)
      {
        if(strcmp(last->data,new_node->data)==0)
          return ;
        else
        last = last->next;
      }
      if(strcmp(last->data,new_node->data)==0)
        return;
      else
  last->next = new_node;
    return;
}

void print2(struct node2 *start)
{
struct node2 *ptr;
ptr = start;
while(ptr != NULL)
{
printf("%s,", ptr -> data);
ptr = ptr -> next;
}
}

struct sNode
{
   char data;
   struct sNode *next;
};
const char *keywords[32]={"auto",	"double",	"int",	"struct",
"break",	"else",	"long",	"switch",
"case",	"enum",	"register",	"typedef",
"char",	"extern",	"return",	"union",
"const",	"float",	"short",	"unsigned",
"continue",	"for",	"signed",	"void",
"default",	"goto",	"sizeof",	"volatile",
"do",	"if",	"static",	"while" };

const char *preprocessor[20]={"#include",
"#define",
"#undef",
"#if",
"#ifdef",
"#ifndef",
"#error"};

void push(struct sNode** top_ref, int new_data)
{
  struct sNode* new_node =
            (struct sNode*) malloc(sizeof(struct sNode));

  if (new_node == NULL)
  {
     printf("Stack overflow n");
     getchar();
     exit(0);
  }
new_node->data  = new_data;
new_node->next = (*top_ref);
(*top_ref)    = new_node;
}

int pop(struct sNode** top_ref)
{
  char res;
  struct sNode *top;
  if (*top_ref == NULL)
  {
     printf("Stack overflow n");
     getchar();
     exit(0);
  }
  else
  {
     top = *top_ref;
     res = top->data;
     *top_ref = top->next;
     free(top);
     return res;
  }
}
bool isMatchingPair(char character1, char character2)
{
   if (character1 == '(' && character2 == ')')
     return 1;
   else if (character1 == '{' && character2 == '}')
     return 1;
   else if (character1 == '[' && character2 == ']')
     return 1;
   else if (character1 == '"' && character2 == '"')
        return 1;
   else
     return 0;
}
bool areParenthesisBalanced(char exp[])
{
   int i = 0;
  struct sNode *stack = NULL;
  while (exp[i])
   {
      if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
        push(&stack, exp[i]);
      if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
      {
         if (stack == NULL)
           return 0;
         else if ( !isMatchingPair(pop(&stack), exp[i]) )
           return 0;
      }
      i++;
   }
   if (stack == NULL)
     return 1; /*balanced*/
   else
     return 0;  /*not balanced*/
}
char* readFile(char* filename)
{
    FILE* file = fopen(filename,"r");
    if(file == NULL)
    {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long int size = ftell(file);
    rewind(file);

    char* content = calloc(size + 1, 1);

    fread(content,1,size,file);

    return content;
}
int main()
{
    char filename[15];
    struct node *w;
    char ch;int i=0,temp,f,h;

    printf("Enter the filename to be opened \n");
    scanf("%s", filename);
    char* a=readFile(filename);
if (!areParenthesisBalanced(a))
    printf("\n UnBalanced Parenthesis");
else
	{ while (a[i]!= '\0')
	    {

	        if(a[i]=='/')
	        	{
	        		temp=i+1;
	        		if (a[temp]=='*') {
	        			f=++temp;h=temp+2;
	        			while(a[f]!='*'&&a[h]!='/')
	        			{
	        				f++;
	        				h++;
	        			}
	        			i=h;//++h;
	        		}
	        		else if(a[temp]=='/')
	        		{
	        			while(a[++temp]!='\n');
	        			i=temp;//++temp;
	        		}

	        		else {
	        			i=i+1;
	        			printf("Incorrect character\n");
	        		}
	        	}
	       else if(a[i]=='#')
	        {
	        	char p[100];int k=0,j;
            p[k]='#';
            k++;

	        	while(a[++i]!='<')//||a[i]==' ')
	        	{
	        		p[k]=a[i];
              k++;
	        	}
            insert_end(&root2,a[i]);
            p[k]='\0';
	        	for(j=0;j<7;j++)
	        	{
	        		if(strcmp(p,preprocessor[j])==0)
	        		{

	        			printf("%s is a preprocessor\n",p);
	        			break;
	        		}
	        	}
	        	if(j==7)
	        	{
	        		printf("Invalid word");
	        	}
            i--;
	        }
         else if(a[i]=='<')
          {
            printf("%c",a[i] );
            while(a[i++]!='>')
            {
              printf("%c",a[i]);
            }
            insert_end(&root2,a[i-1]);
            printf("%c\n",a[i] );


          }
         else if(a[i]==';'||a[i]==')'||a[i]=='('||a[i]=='{'||a[i]=='}')
          {
            insert_end(&root1,a[i]);
          }
         else if(a[i]=='+'||a[i]=='-'||a[i]=='/'||a[i]=='*'||a[i]=='%'||a[i]=='>'||a[i]=='<'||a[i]=='=')
         {

          insert_end(&root2,a[i]);
         }
          else if(isdigit(a[i]))
           {
            char p[100];int k=0;
            p[k++]=a[i];
            while(isdigit(a[++i]))
            {
                p[k]=a[i];
                k++;
            }
            i--;
            p[k]='\0';
            int tep=k-1;
            int h=0;double val=0;
            while(p[h]!='\0')
            {
              val=val+(((int)(p[h]-'0'))*pow(10,tep-h));
              h++;
            }
            insert_end1(&root3,val);
            }

	     else  if (isalpha(a[i]))//(a[i]>='a'&&a[i]<='z')//||(a[i]>='A'&&a[i]<='Z')||a[i]=='_')
			{
	        	char p[100];int k=0,j;
            int ttttr=i;
            p[k]=a[i];k++;
	        	while(isalpha(a[++i]))
	        	{
	        		p[k]=a[i];k++;
	        	}
            i--;
            p[k]='\0';
	        	for( j=0;j<32;j++)
	        	{
	        		if(strcmp(p,keywords[j])==0)
	        		{
                insert_end2(&root4,p);
	        			break;
	        		}
	        	}
	        	if(j==32)
	        	{
              if(strcmp(p,"true")==0||strcmp(p,"false")==0)
                printf("%s is a boolean value \n",p);
              else
              insert_end2(&root5,p);
	        	}

	        }

         else if(a[i]=='"')
         {
          char p[10000];int k=0;
          while(a[++i]!='"')
          {
            p[k++]=a[i];
          }
          printf("%s  is a string \n\n",p);
         }

i++;

	    }
      printf("These is the lexical analysis\n\n");
	//printf("balanced\n");
      print(root1);
      printf(" are the seperators\n\n");
      print(root2);
      printf(" are the operators\n\n");
      print1(root3);
      printf(" are the constants\n\n");
      print2(root4);
      printf(" are the keywords\n\n");
      print2(root5);
      printf(" are the identifiers\n\n");
}

return 0;
}


