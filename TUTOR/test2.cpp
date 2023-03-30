#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct emp
{
    /* data */
    char name[100];
    char department[100];
}eDetail;

struct comp{
    //1 - 6
    float compA;
    float compB;
    float compC;
    float compD;
    float compE;
}kpiComp;

struct kpi
{
    /* data */
    int idEmployee;
    emp empDetail;
    comp components;
    //sum setiap komponen
    float kpiScore;

}KPI;

void menu(){
    puts("1. Input Data");
    puts("2. Print Data");
    puts("3. Delete Data");
    puts("4. Find Data");
    puts("0. Exit");
}

bool validateComp(float comp){
    if (comp < 0 || comp > 100)
    {
        return false;
    }
    return true;
}

void inputData(kpi empKPI[]){
    int size = 0;
    int id = 0;
    char name[100];
    char department[100];
    float compA, compB, compC, compD, compE;

    do {
        printf("ID: ");
        scanf("%d",&id); getchar();
        if (id < 0)
        {
            printf("ID must be positive\n");
    }while(id < 0));

    do{
        printf("Comp A: ");
        scanf("%f",&compA); getchar();
        if (!validateComp(compA))
        {
            printf("Comp A must be between 0 and 100\n");
        }
    }while(!validateComp(compA));

    do{
        printf("Comp B: ");
        scanf("%f",&compB); getchar();
        if (!validateComp(compB))
        {
            printf("Comp B must be between 0 and 100\n");
        }
    }while(!validateComp(compB));

    do{
        printf("Comp C: ");
        scanf("%f",&compC); getchar();
        if (!validateComp(compC))
        {
            printf("Comp C must be between 0 and 100\n");
        }
    }while(!validateComp(compC));

    do{
        printf("Comp D: ");
        scanf("%f",&compD); getchar();
        if (!validateComp(compD))
        {
            printf("Comp D must be between 0 and 100\n");
        }
    }while(!validateComp(compD));

    do{
        printf("Comp E: ");
        scanf("%f",&compE); getchar();
        if (!validateComp(compE))
        {
            printf("Comp E must be between 0 and 100");
        }
    }while(!validateComp(compE));

    empKPI[size].idEmployee = id;
    empKPI[size].empDetail.name = name;
    empKPI[size].empDetail.department = department;

}

int main(){
    
    int inp = 1;
  
    while (inp != 0)
    {
        menu();
        scanf("%d",&inp); getchar();
        switch (inp)
        {
        case 1:
            inputData(empKPI);
            break;
        
        case 2:
            printData(empKPI, size);
            break;
        
        case 3:
            deleteData(empKPI);
            break;
				
        case 4:
            findData(empKPI);
            
        default:
            break;
        }
     
    }
    printf("THANK YOU");
    
    return 0;
    
}