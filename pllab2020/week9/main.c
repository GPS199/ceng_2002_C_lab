#include <stdio.h>
#include <stdlib.h>
#define MAX 30
typedef struct{
    int ID;
    char employee_name[30];
    char employee_department[30];
    int birth_year;
    int salary;
}employeeData;

void menu(void);
void convertTextFile(FILE *fPtr);
void addRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);
void updateRecord(FILE *fPtr);
void showRecords(FILE *fPtr);

int main()
{
    menu();
    return 0;
}



void menu(void){
FILE *fptr;
int choise;
char control = 1;
while(control!=0){
    printf("\n\n**********************************\n\nEMPLOYEE RECORD SYSTEM\n");
    printf("1- add new record\n2- update record\n3- delete record\n4- print all records\n5- save as txt file\n6- end program\n");
    printf("ENTER A CHOICE =>");
    scanf("%d",&choise);
    switch(choise){
    case 1:
        fptr = fopen("employee.bin","rb+");
        addRecord(fptr);
        fclose(fptr);
        break;
    case 2:
        fptr = fopen("employee.bin","rb+");
        updateRecord(fptr);
        fclose(fptr);
        break;
    case 3:
        fptr = fopen("employee.bin","rb+");
        deleteRecord(fptr);
        fclose(fptr);
        break;
    case 4:
        fptr = fopen("employee.bin","rb+");
        showRecords(fptr);
        fclose(fptr);
        break;
    case 5:
        fptr = fopen("employee.bin","rb+");
        convertTextFile(fptr);
        fclose(fptr);
        break;
    case 6:
        printf("See you later....");
        control = 0;
        break;

    }

}

}

void convertTextFile(FILE *fptr){
    FILE *input;
    int i;
    input = fopen("employee.txt","w");
    employeeData datas[100];
    if(fptr!=NULL){
            fread(datas,sizeof(employeeData),100,fptr);                                // We are checking whether there is a file exist or not.
            for(i=0;i<100;i++){
                if(datas[i].ID!=0){                                                             // We just transfer the data that have ID.
                        fprintf(input,"%d%s%s%d%d",datas[i].ID,datas[i].employee_name,datas[i].employee_department,datas[i].birth_year,datas[i].salary);

                }
    }
    fclose(input);
    }else{                                                                          // If there is no such file we just give a error message.
    printf("There is no such a file.");
    }

}


void addRecord(FILE *fptr){
    employeeData data;
    int ID;
    printf("Enter the ID to create new employee record:");
    scanf("%d",&ID);                                         // We just take an ID from user.
    if(fptr==NULL){                                         // We are checking whether there is a file exist or not.
        printf("There is no such a file.");                 // If there is no such file we just give a error message.
    }else{
    fseek(fptr,(ID-1)*sizeof(employeeData),SEEK_SET);        // We jumped the ID's address where we want to insert.
    fread(&data,sizeof(employeeData),1,fptr);
    if(data.ID==ID){                                         // We are checking whether if there is an ID exist with the same ID.
        printf("You can not add an employee with same ID with others");
    }
    else{
        printf("Employee Name:");                              // We just take the rest information about employee.
        scanf("%s",data.employee_name);
        printf("\nDepartment:");
        scanf("%s",data.employee_department);
        printf("\nBirth Year:");
        scanf("%d",&data.birth_year);
        printf("\nSalary:");
        scanf("%d",&data.salary);
        printf("Employee with ID #%d is recorded.",ID);

    }


    }

}


void deleteRecord(FILE *fptr){
    employeeData data;
    int ID;
    printf("Enter the ID to delete employee record:");
    scanf("%d",&ID);                                         // We just take an ID from user.
    if(fptr==NULL){                                         // We are checking whether there is a file exist or not.
        printf("There is no such a file.");                 // If there is no such file we just give a error message.
    }else{
    fseek(fptr,(ID-1)*sizeof(employeeData),SEEK_SET);        // We jumped the ID's address where we want to delete.
    fread(&data,sizeof(employeeData),1,fptr);
    if(data.ID!=ID){                                         // We are checking whether if there is an ID exist with the same ID.
        printf("You can not delete this record because there is no such a record.");
    }
    else{
        data.ID=0;

    }

    }
}

void updateRecord(FILE *fptr){
 employeeData data;
 float increase;
    int ID;
    printf("Enter the ID to update employee record:");
    scanf("%d",&ID);                                         // We just take an ID from user.
    if(fptr==NULL){                                         // We are checking whether there is a file exist or not.
        printf("There is no such a file.");                 // If there is no such file we just give a error message.
    }
    else{
    fseek(fptr,(ID-1)*sizeof(employeeData),SEEK_SET);        // We jumped the ID's address where we want to delete.
    fread(&data,sizeof(employeeData),1,fptr);
        if(data.ID!=ID){                                         // We are checking whether if there is an ID exist with the same ID.
            printf("You can not update this record because there is no such a record.");
                       }
        else{
            printf("ID\tEmployee Name\tDepartment\tBirth Year\tSalary\n%d\t%s\t%s\t%d\t%d\n ",data.ID,data.employee_name,data.employee_department,data.birth_year,data.salary); // Just print the infos before update
            printf("\nEnter the percentage of increase for salary:");
            scanf("%f",&increase);                                  // Take the increase of salary.
            data.salary+=(data.salary*(increase/100));              // Just transformed the '%'
            printf("ID\tEmployee Name\tDepartment\tBirth Year\tSalary\n%d\t%s\t%s\t%d\t%d\n ",data.ID,data.employee_name,data.employee_department,data.birth_year,data.salary); // Print again after update

            }

    }


}

void showRecords(FILE *fptr){
employeeData datas[100];
int i;
if(fptr==NULL){
    printf("There is no such a file.");
}
else{
    fread(datas,sizeof(employeeData),100,fptr);
    for(i=0;i<100;i++){
        if(datas[i].ID!=0){
            printf("ID\tEmployee Name\tDepartment\tBirth Year\tSalary\n%d\t%s\t%s\t%d\t%d\n ",datas[i].ID,datas[i].employee_name,datas[i].employee_department,datas[i].birth_year,datas[i].salary); // Just print the infos
            printf("\n");
        }
    }

}








}










