#include <stdio.h>
#include <math.h>
typedef struct equation
{
    float a,b,c;
}Eqn;
struct complex
{
    float imaginary,real;
};
typedef struct roots
{
    struct complex r1,r2;
}Roots;
typedef enum equation_type
{
    NOT_EQUATION=0,LINEAR,QUADRATIC
}EQUATION_TYPE;
typedef enum solution_type
{
    COMPLEX=-1,REAL_EQUAL,REAL_UNEQUAL
}SOLUTION_TYPE;
typedef enum yes_or_no
{
    n,y
}YesOrNo;
typedef enum error_no
{
    NO_ERROR,ERROR0,ERROR1
}ErrorNo;
Eqn input()
{
    Eqn coeff;
    printf("Enter the values of a,b and c in ax%c+bx+c=0\n",253);
    scanf("%f%f%f",&coeff.a,&coeff.b,&coeff.c);
    return coeff;
}
float determinant(Eqn coeff)
{
    float det;
    det=(pow(coeff.b,2))-4*coeff.a*coeff.c;
    return det;
}
SOLUTION_TYPE solutionType(Eqn coeff)
{
    float det=determinant(coeff);
    SOLUTION_TYPE sType;
    if(coeff.a!=0&&det>0)
    {
        sType=REAL_UNEQUAL;
    }
    else if(coeff.a!=0&&det==0)
    {
        sType=REAL_EQUAL;
    }
    else if(coeff.a!=0&&det<0)
    {
        sType=COMPLEX;
    }
    return sType;
}
EQUATION_TYPE typeEquation(Eqn coeff)
{
    EQUATION_TYPE eType;
    if(coeff.a==0&&coeff.b!=0)
    {
        eType=LINEAR;
    }
    else if(coeff.a==0&&coeff.b==0)
    {
         eType=NOT_EQUATION;
    } 
    else if(coeff.a!=0)
    {
        eType=QUADRATIC;
    }
    return eType;
}
void errorNumber(Eqn coeff,ErrorNo errNo)
{
    switch(errNo)
    {
        case ERROR0:
            printf("There is a temporary error");
            break;
        case ERROR1:
            printf("\nThis is not an equation");
        case NO_ERROR:
        default:
            break;
    }
}
Roots compute(Eqn coeff,ErrorNo *errNo)
{
    Roots root;
    EQUATION_TYPE eType;
    SOLUTION_TYPE sType;
    float det=determinant(coeff);
    eType=typeEquation(coeff);
    sType=solutionType(coeff);
    root.r1.real=0;
    root.r1.imaginary=0;
    root.r2.real=0;
    root.r2.imaginary=0;
    switch(eType)
    {
        case LINEAR:   
            root.r1.real=-coeff.c/coeff.b;
            break;
        case QUADRATIC:
            switch(sType)
            {
                case REAL_UNEQUAL:  
                    root.r1.real=(-coeff.b+sqrt(det))/(2*coeff.c);
                    root.r2.real=(-coeff.b-sqrt(det))/(2*coeff.c);
                    break;
                case REAL_EQUAL:
                    root.r1.real=(-coeff.b)/(2*coeff.a);
                    root.r2.real=root.r1.real;
                    break;
                case COMPLEX:     
                    root.r1.real=(-coeff.b)/(2*coeff.a);
                    root.r1.imaginary=(sqrt(-det))/(2*coeff.a);
                    root.r2.real=root.r1.real;
                    root.r2.imaginary=-root.r1.imaginary;
            }
            break;
        case NOT_EQUATION:*errNo=ERROR1;
    }
    return root;
}
void toString(struct complex root,int n,char string_root[n])
{
    int j,i,temp,length,integer;
    float decimal;
    i=0;
    if(root.real<0)
    {
        string_root[i]='-';
        i++;
        root.real=-root.real;
    }
    integer=root.real;
    temp=integer;
    length=0;
    if(integer==0)
    {
        string_root[i]=48;
        i++;
    }
    while(temp!=0)
    {
        temp/=10;
        length++;
    }
    i+=(length-1);
    temp=integer;
    while(integer!=0)
    {
        string_root[i]=(integer%10)+48;
        integer/=10;
        i--;
    }
    i+=(length+1);
    string_root[i]='.';
    i++;
    decimal=root.real-temp;
    integer=decimal*10;
    for(j=1;j<=2;j++)
    {
        if(integer==0)
        {
           string_root[i]=48;
           i++;
           decimal=decimal*10;
           decimal=decimal-integer;
           integer=decimal*10;
        }
    }
    while(integer!=0)
    {
        decimal=decimal*10;
        integer=decimal;
        string_root[i]=integer+48;
        decimal=decimal-integer;
        integer=decimal*10;
        i++;
    }
    integer=root.imaginary;
    temp=integer;
    length=0;
    if(root.imaginary<0)
    {
        string_root[i]='-';
        i++;
        integer=-integer;
        temp=integer;
        root.imaginary=-root.imaginary;
    }
    else
    {
        string_root[i]='+';
        i++;
    }
    string_root[i]='i';
    i++;
    if(integer==0)
    {
        string_root[i]=48;
        i++;
    }
    while(temp!=0)
    {
        temp/=10;
        length++;
    }
    i+=(length-1);
    temp=integer;
    while(integer!=0)
    {
        string_root[i]=(integer%10)+48;
        integer/=10;
        i--;
    }
    i+=(length+1);
    string_root[i]='.';
    i++;
    decimal=root.imaginary-temp;
    integer=decimal*10;
    for(j=1;j<=2;j++)
    {
        if(integer==0)
        {
           string_root[i]=48;
           i++;
           decimal=decimal*10;
           decimal=decimal-integer;
           integer=decimal*10;
        }
    }
    while(integer!=0)
    {
        decimal=decimal*10;
        integer=decimal;
        string_root[i]=integer+48;
        decimal=decimal-integer;
        integer=decimal*10;
        i++;
    }
    string_root[i]='\0';
    printf("%s  ",string_root);
}
int stringLength(struct complex root)
{
    int length=0,integer;
    if(root.real<0)
    {
        root.real=-root.real;
    }
    integer=root.real;
    while(integer!=0)
    {
        integer/=10;
        length++;
    }
    if(root.imaginary<0)
    {
        root.imaginary=-root.imaginary;
    }
    integer=root.imaginary;
    while(integer!=0)
    {
        integer/=10;
        length++;
    }
    length+=9;
    return length;
}
void output(Eqn coeff,Roots root,ErrorNo errNo)
{
    EQUATION_TYPE eType;
    SOLUTION_TYPE sType;
    int length;
    eType=typeEquation(coeff);
    sType=solutionType(coeff);
    printf("\n%.1fx%c+%.1fx+%.1f=0",coeff.a,253,coeff.b,coeff.c);
    char string_root1[18],string_root2[18];
    switch(errNo)
    {
        case NO_ERROR:
             switch(eType)
             {
                case LINEAR:
                     printf("\nThe equation is linear:\n(%.3f)+(%.3f)i  is the solution",root.r1.real,root.r1.imaginary);
                     break;
                case NOT_EQUATION:
                     printf("\nThis is not an equation");
                     break;
                case QUADRATIC:
                     switch(sType)
                     {
                        case REAL_UNEQUAL:
                             printf("\nThe roots are real and unequal:\n");
                             break;
                        case REAL_EQUAL:
                             printf("\nThe roots are real and equal:\n");
                             break;
                       case COMPLEX:
                             printf("\nThe roots are imaginary:\n");
                            break;
                       default:
                            break;
                     }
                     length=stringLength(root.r1);
                     toString(root.r1,length,string_root1);
                     length=stringLength(root.r1);
                     toString(root.r2,length,string_root2);
                     printf("are the roots of the equation");
                     break;
             } 
         case ERROR0:
         case ERROR1:
         default:
              errorNumber(coeff,errNo);
    }
}
YesOrNo check(char in)
{
    YesOrNo y_n;
    if(in=='y'||in=='Y')
    {
        y_n=y;
    }
    else 
        y_n=n;
    return y_n;
}
YesOrNo continueORno()
{
    YesOrNo y_n;
    char in;
    scanf(" %c",&in);
    y_n=check(in);
    printf("\n\n");
    return y_n;
}
int main(void)
{
    Eqn coeff;
    Roots root;
    YesOrNo y_n;
    ErrorNo errNo;
    y_n=y;
    while(y_n==y)
    {
        errNo=NO_ERROR;
        coeff=input();
        root=compute(coeff,&errNo);
        output(coeff,root,errNo);
        printf("\n\nEnter y to continue or n to quit ");
        y_n=continueORno();
    }
    printf("\n\n");
    return 0;
}
