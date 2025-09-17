// 1. Header Files
#include <stdio.h> // Header Filed for Input, Output Functions
#include <stdlib.h> // Header File for DMA


// 2. Symbolic Names 
#define SIZE 15 // Number of data sets in each prod line
#define ISS_LENGTH 51 // Length of issue strings
#define PROD_NUM 19 // Number of Product IDs used for Task 4 
#define TOTAL_SIZE 60 // Total size of all prod lines together


// 3. Structure Templates
struct date // Structure Template for batch date & time
{
    int day;
    int hour;
    int minute;
};

struct is_info // Structure Template for issue data
{
    int_code; // Issue Code
    char i_desc[ISS_LENGTH]; // String for Issue Descs
};

struct sol_info // Structure Template for resolution data
{
    int s_code; // Solution Code
    char s_desc[ISS_LENGTH]; // String for Solution Descs
};

struct manData // Structure Template for manufacturing data
{
    int linNo; // Line Code (1 digit)
    int batch; // Batch Code (7 digit int)
    struct date time; // Date (Day, Hour, Minute) (ints)
    int prod_ID; // Product ID (9 digit int)
    struct is_info issue; // Nested structure of issues (5 digit int & string)
    struct sol_info solution; // Nested structure of solutions (5 digit int & string)
    int empl_ID; // Employee ID (3 digit int)
};

struct node // Structure Template for a node (data and address of next node)
{
    struct manData data; // Node data
    struct node *link; // Pointer to next node
};
