#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int CURR = 0;
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

KPI kpis[1000];

//Sort Functions
void mergeIDAsc(int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    KPI L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = kpis[l + i];
    for (j = 0; j < n2; j++)
        R[j] = kpis[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].idEmployee <= R[j].idEmployee)
        {
            kpis[k] = L[i];
            i++;
        }
        else
        {
            kpis[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        kpis[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        kpis[k] = R[j];
        j++;
        k++;
    }
}
void mergeSortByIDAsc(int l = 0, int r = CURR-1){
    if (l < r)
    {
        int m = (l+r)/2;
        mergeSortByIDAsc(l,m);
        mergeSortByIDAsc(m+1,r);
        mergeIDAsc(l,m,r);
    }
}

void mergeIDDesc(int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    KPI L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = kpis[l + i];
    for (j = 0; j < n2; j++)
        R[j] = kpis[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].idEmployee >= R[j].idEmployee)
        {
            kpis[k] = L[i];
            i++;
        }
        else
        {
            kpis[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        kpis[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        kpis[k] = R[j];
        j++;
        k++;
    }
}
void mergeSortByIDDesc(int l = 0, int r = CURR-1){
    if (l < r)
    {
        int m = (l+r)/2;
        mergeSortByIDDesc(l,m);
        mergeSortByIDDesc(m+1,r);
        mergeIDDesc(l,m,r);
    }
}

void mergeScoreAsc(int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    KPI L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = kpis[l + i];
    for (j = 0; j < n2; j++)
        R[j] = kpis[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].kpiScore <= R[j].kpiScore)
        {
            kpis[k] = L[i];
            i++;
        }
        else
        {
            kpis[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        kpis[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        kpis[k] = R[j];
        j++;
        k++;
    }
}
void mergeSortByScoreAsc(int l = 0, int r = CURR-1){
    if (l < r)
    {
        int m = (l+r)/2;
        mergeSortByScoreAsc(l,m);
        mergeSortByScoreAsc(m+1,r);
        mergeScoreAsc(l,m,r);
    }
}

void mergeScoreDesc(int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    KPI L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = kpis[l + i];
    for (j = 0; j < n2; j++)
        R[j] = kpis[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].kpiScore >= R[j].kpiScore)
        {
            kpis[k] = L[i];
            i++;
        }
        else
        {
            kpis[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        kpis[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        kpis[k] = R[j];
        j++;
        k++;
    }
}
void mergeSortByScoreDesc(int l = 0, int r = CURR-1){
    if (l < r)
    {
        int m = (l+r)/2;
        mergeSortByScoreDesc(l,m);
        mergeSortByScoreDesc(m+1,r);
        mergeScoreDesc(l,m,r);
    }
}

//Validate
bool validateComp(float comp){
    if (comp < 0 || comp > 6)
        return false;
    return true;
}
bool validateSortBy(char sortBy[]){
    if (strcmp(sortBy,"id") == 0 || strcmp(sortBy,"score") == 0)
        return true;
    return false;
}
bool validateSortType(char sortType[]){
    if (strcmp(sortType,"ascending") == 0 || strcmp(sortType,"descending") == 0)
        return true;
    return false;
}

//Data Manipulation Functions
void getData(KPI *empKPI){
    system("CLS");
    empKPI->idEmployee = CURR+1;
    printf("Input ID Employee: %d\n", empKPI->idEmployee); 

    printf("Input Name: "); scanf("%s",empKPI->empDetail.name);

    printf("Input Department: "); scanf("%s",empKPI->empDetail.department);
    
    do{
        printf("Input Component A: "); scanf("%f",&empKPI->components.compA);
    }while(!validateComp(empKPI->components.compA));
    
    do{
        printf("Input Component B: "); scanf("%f",&empKPI->components.compB);
    }while(!validateComp(empKPI->components.compB));
    
    do{
        printf("Input Component C: "); scanf("%f",&empKPI->components.compC);
    }while(!validateComp(empKPI->components.compC));
    
    do{
        printf("Input Component D: "); scanf("%f",&empKPI->components.compD);
    }while(!validateComp(empKPI->components.compD));

    do{
        printf("Input Component E: "); scanf("%f",&empKPI->components.compE);
    }while(!validateComp(empKPI->components.compE));
    empKPI->kpiScore = (empKPI->components.compA + empKPI->components.compB + empKPI->components.compC + empKPI->components.compD + empKPI->components.compE)/5;
}

//Binary Search
int binarySearch(int l, int r, int x){
    if (r >= l)
    {
        int mid = l + (r - l)/2;
        if (kpis[mid].idEmployee == x)
            return mid;
        if (kpis[mid].idEmployee > x)
            return binarySearch(l, mid-1, x);
        return binarySearch(mid+1, r, x);
    }
    return -1;
}

//Use Case Functions
void inputData(KPI empKPI){
    int n;
    printf("Input Number of Employee: ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        getData(&empKPI);
        kpis[CURR++] = empKPI;
    }
}
void printData(){
    char sortBy[100];
    do{
        printf("Sort Based on [id / score] : ");
        scanf("%[^\n]",sortBy); getchar();
    }while(!validateSortBy(sortBy));

    char sortType[100];
    do{
        printf("Sort Type [ascending / descending] : ");
        scanf("%[^\n]",sortType); getchar();
    }while(!validateSortType(sortType));

    if (strcmp(sortBy,"id") == 0)
    {
        if (strcmp(sortType,"ascending") == 0)
            mergeSortByIDAsc();
        else
            mergeSortByIDDesc();
    }
    else
    {
        if (strcmp(sortType,"ascending") == 0)
            mergeSortByScoreAsc();
        else
            mergeSortByScoreDesc();
    }
    puts("====================================================================");
    printf("| %-5s | %-5s | %-4s | %-4s | %-4s | %-4s | %-4s | %-15s |\n", "ID", "Name", "A", "B", "C", "D", "E", "KPI Score");
    for (int i = 0; i < CURR; i++)
    {
        printf("| %-5d | %-5s | %-3.2f | %-3.2f | %-3.2f | %-3.2f | %-3.2f | %-15.2f |\n", kpis[i].idEmployee, kpis[i].empDetail.name, kpis[i].components.compA, kpis[i].components.compB, kpis[i].components.compC, kpis[i].components.compD, kpis[i].components.compE, kpis[i].kpiScore);
    }
    puts("===================================================================");
    
}
void deleteData(){
    mergeSortByIDAsc();
    puts("====================================================================================================");
    printf("| %-5s | %-5s | %-3s | %-3s | %-3s | %-3s | %-3s | %-15s |\n", "ID", "Name", "A", "B", "C", "D", "E", "KPI Score");
    for (int i = 0; i < CURR; i++)
    {
        printf("| %-5d | %-5s | %-3.2f | %-3.2f | %-3.2f | %-3.2f | %-3.2f | %-15.2f |\n", kpis[i].idEmployee, kpis[i].empDetail.name, kpis[i].components.compA, kpis[i].components.compB, kpis[i].components.compC, kpis[i].components.compD, kpis[i].components.compE, kpis[i].kpiScore);
    }
    puts("====================================================================================================");
    
    int id;
    printf("Input ID Employee: ");
    scanf("%d",&id); getchar();
    
    int idx = binarySearch(0,CURR-1,id);
    if (idx == -1)
    {
        puts("Employee Not Found");
        return;
    }
    for (int i = idx; i < CURR-1; i++)
    {
        kpis[i] = kpis[i+1];
    }
    CURR--;
    puts("Employee Deleted");
}
void findData(){
    int id;
    printf("Input ID Employee: ");
    scanf("%d",&id); getchar();
    mergeSortByIDAsc();
    int idx = binarySearch(0,CURR-1,id);
    if (idx == -1)
    {
        puts("Employee Not Found");
        return;
    }
    puts("=================================================================================================================================");
    printf("| %-5s | %-5s | %-3s | %-3s | %-3s | %-3s | %-3s | %-15s |\n", "ID", "Name", "A", "B", "C", "D", "E", "KPI Score");
    printf("| %-5d | %-5s | %-3.2f | %-3.2f | %-3.2f | %-3.2f | %-3.2f | %-15.2f |\n", kpis[idx].idEmployee, kpis[idx].empDetail.name, kpis[idx].components.compA, kpis[idx].components.compB, kpis[idx].components.compC, kpis[idx].components.compD, kpis[idx].components.compE, kpis[idx].kpiScore);
    puts("=================================================================================================================================");
}

void menu(){
    system("CLS");
    printf("1. Input Data\n");
    printf("2. Print Data\n");
    printf("3. Delete Data\n");
    printf("4. Find Data\n");
    printf("0. exit\n");
}

int main(){
    KPI empKPI;
    int inp = 1;
  
    while (inp != 0)
    {
        menu();
        printf("Choose >> ");
        scanf("%d",&inp); getchar();
        switch (inp)
        {
        case 1:
            inputData(empKPI);
            break;
        
        case 2:
            printData();
            break;
        
        case 3:
            deleteData();
            break;
				
        case 4:
            findData();
            break;
        default:
            break;
        }
        printf("Press Enter to Continue...");
        getchar();
    }
    printf("THANK YOU");
}