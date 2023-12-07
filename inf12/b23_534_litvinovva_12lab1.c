/************************** Thu Dec 07 10:19:49 2023 **************************/
//#include "../clib/src/title.h"
/*                                _      _       __   _        _              */
/*        _ __ ___    ___  _ __  | |__  (_)     / /  (_)  ___ (_) ___         */
/*       | '_ ` _ \  / _ \| '_ \ | '_ \ | |    / /   | | / __|| |/ __|        */
/*       | | | | | ||  __/| |_) || | | || |   / /    | || (__ | |\__ \        */
/*       |_| |_| |_| \___|| .__/ |_| |_||_|  /_/     |_| \___||_||___/        */
/*                        |_|                                                 */
/*                                                                            */
/*                    Created by Vlad Litvinov b23-534                        */
/*                       https://github.com/vSEK1RO                           */
/*                                                                            */
//#endclude "../clib/src/title.h"
/************************************ TASK ************************************/
/*                                                                            */
/*                     Create a company employee structure                    */
/*         Implement a search for the employee with the lowest salary         */
/*                   Outputting employee data to the console                  */
/*                                                                            */
/******************************* INCLUDES START *******************************/

typedef struct {
    char * firstName;
    char * name;
    int depart;
    int salary;
    int bonus;
    int dues;
} Employee;

#define ARR_TYPE Employee
#include "../clib/src/array.h"
#include "../clib/src/string.h"

/********************************* CODE START *********************************/

Employee * get_io_employee();

int main()
{
    Employee * emps = get_io_employee()
    
}

/**************************** IMPLEMENTATIONS START ***************************/

/********************************* PROGRAM END ********************************/