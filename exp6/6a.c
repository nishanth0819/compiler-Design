#include<stdio.h>
#include<string.h>
#include<ctype.h>
char gram[10][10],first[10];
int k=0,n;
void funcfirst(char g,int n)
{
    int i,j;
    if(!(isupper(g)))
         first[k++]=g;
    else
    {
        for(i=0;i<n;i++)
        {
            if(gram[i][0]==g)
            {
                if(islower(gram[i][3]))
                    first[k++]=gram[i][3];
                else
                    funcfirst(gram[i][3],n);
            }
        }
    }
}
int main()
{
    char nt;
    printf("Enter No of Productions ");
    scanf("%d",&n);
    printf("Enter the Productions");
    for(int i=0;i<n;i++)
    {
        scanf("%s",gram[i]);
    }
    printf("...PREDECTIVE PARSING TABLE LL(1)...\n");
    for(int i=0;i<n;i++)
    {
     k=0;
     funcfirst(gram[i][0],n);
    
    printf("%s--->",gram[i]);
    for(int j=0;j<k;j++)
    {
        printf("{%c,%c}",gram[i][0],first[j]);
    }
    
    printf("\n");
   }
   return 0;
}
