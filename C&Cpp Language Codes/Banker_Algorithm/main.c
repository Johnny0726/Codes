#include <stdio.h>

#define N 10
int AllocatedRes[N][N];   //currently allocated resources
int MaxResVector[N][N];   //maximum resources
int AvailableRes[N];      //total available resources in system
int Running[N];           // the process is running
int AllocPerRes[N]={0};   //total per resource
int ResidualRes[N];       //residual per resource
int nProcessNum;          //The number of processes
int nResourceNum;         //The number of resources
int nCount = 0;
int safe = 0;
int exec = 1;
int i, j;

void InitDate()
{
    printf("The number of processes:\n");
    scanf("%d",&nProcessNum);

    for(i=0; i< nProcessNum; i++)
    {
        Running[i] = 1;
        nCount++;
    }

    printf("The number of resources:\n");
    scanf("%d",&nResourceNum);

    printf("Please input maximum resource table:\n");
    for(i=0; i<nProcessNum; i++)
    {
        for(j=0; j<nResourceNum; j++)
        {
            scanf("%d", &MaxResVector[i][j]);
        }
    }

    printf("Please input allocated resource table:\n");
    for(i=0; i<nProcessNum; i++)
    {
        for(j=0; j<nResourceNum; j++)
        {
            scanf("%d", &AllocatedRes[i][j]);
        }
    }

    printf("Please input total number of per resource:\n");
    for(i=0; i<nResourceNum; i++)
    {
        scanf("%d", &AvailableRes[i]);
    }
}

void CalculateData()
{
    for(i=0; i<nProcessNum; i++)
    {
        for(j=0; j<nResourceNum; j++)
        {
            AllocPerRes[j] += AllocatedRes[i][j];
        }
    }

    for(i=0; i<nResourceNum; i++)
    {
        ResidualRes[i] = AvailableRes[i] - AllocPerRes[i];
    }
}

void CheckSafety()
{
     while(nCount!=0)
    {
        safe=0;
        for(i=0;i<nProcessNum;i++)
        {
            if(Running[i])
            {
                exec=1;
                for(j=0; j<nResourceNum; j++)
                {
                    if(MaxResVector[i][j] - AllocatedRes[i][j] > ResidualRes[j])
                    {
                        exec=0;
                        break;
                    }
                }
                if(exec)
                {
                    printf("\nProcess%d is executing\n",i+1);
                    Running[i]=0;
                    nCount--;
                    safe=1;

                    for(j=0; j<nResourceNum; j++)
                    {
                        ResidualRes[j] += AllocatedRes[i][j];
                    }

                    break;
                }
            }
        }
        if(!safe)
        {
            printf("\nThe processes are in unsafe state.\n");
            break;
        }
        else
        {
            printf("The process is in safe state");
            printf("\nresidual per resource is:");

            for(i=0; i<nResourceNum; i++)
            {
                printf("\t%d",ResidualRes[i]);
            }

            printf("\n");
        }
    }
}


int main()
{
    InitDate();
    CalculateData();
    CheckSafety();
    return 0;
}
