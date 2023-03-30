#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct emp
{
    /* data */
    char name[100];
    char department[100];
}eDetail;

typedef struct comp{
    //1 - 6
    float compA;
    float compB;
    float compC;
    float compD;
    float compE;
}kpiComp;

typedef struct kpi
{
    /* data */
    int idEmployee;
    eDetail empDetail;
    kpiComp components;
    //sum setiap komponen
    float kpiScore;

}KPI;

bool validateComp(float comp){
    if (comp < 1 || comp > 6)
    {
        return false;
    }
    return true;
}

void inputData(KPI empKPI[], int n){
    system("CLS");
    for (int i = 0; i < n; i++)
    {
        printf("ID Employee: ");
        scanf("%d", &empKPI[i].idEmployee); getchar();
        printf("Name: ");
        scanf("%[^\n]", empKPI[i].empDetail.name); getchar();
        printf("Department: ");
        scanf("%[^\n]", empKPI[i].empDetail.department); getchar();
        printf("Component A: ");
        float temp = 0;
        do{

        }while(!validateComp(temp));
        scanf("%f", &empKPI[i].components.compA); getchar();
        printf("Component B: ");
        scanf("%f", &empKPI[i].components.compB); getchar();
        printf("Component C: ");
        scanf("%f", &empKPI[i].components.compC); getchar();
        printf("Component D: ");
        scanf("%f", &empKPI[i].components.compD); getchar();
        printf("Component E: ");
        scanf("%f", &empKPI[i].components.compE); getchar();
        empKPI[i].kpiScore = empKPI[i].components.compA + empKPI[i].components.compB + empKPI[i].components.compC + empKPI[i].components.compD + empKPI[i].components.compE;
    }
    
}

void printData(KPI empKPI[], int n){
    system("CLS");
    for (int i = 0; i < n; i++)
    {
        printf("id employee: %d\n",empKPI[i].idEmployee);
        printf("employee name: %s\n",empKPI[i].empDetail.name);
        printf("compA: %f\n", empKPI[i].components.compA);
        printf("compB: %f\n", empKPI[i].components.compB);
        printf("compC: %f\n", empKPI[i].components.compC);
        printf("compD: %f\n", empKPI[i].components.compD);
        printf("compE: %f\n", empKPI[i].components.compE);
        printf("kpi score: %f\n", empKPI[i].kpiScore);
        printf("Press to continue ...");
        getchar();
    }
}

void menu(){
    system("CLS");
    printf("1. Input Data\n");
    printf("2. Print Data\n");
    printf("0. exit\n");
}

int main(){
    KPI empKPI[1000];
    int inp = 1;
    
    int n;
    while (inp != 0)
    {
        menu();
        printf("input: ");
        scanf("%d", &inp); getchar();
        switch (inp)
        {
        case 1:
            printf("input number of employee: ");
            scanf("%d", &n); getchar();
            inputData(empKPI, n);
            break;
        case 2:
            printData(empKPI, n);
            break;
        default:
            break;
        }
    }
}