// 1. Header Files
#include <stdio.h>  // Header Filed for Input, Output Functions
#include <stdlib.h> // Header File for DMA

// 2. Symbolic Names
#define SIZE 15       // Number of data sets in each prod line
#define ISS_LENGTH 51 // Length of issue strings
#define PROD_NUM 19   // Number of Product IDs used for Task 4
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
    int i_code;              // Issue Code
    char i_desc[ISS_LENGTH]; // String for Issue Descs
};

struct sol_info // Structure Template for resolution data
{
    int s_code;              // Solution Code
    char s_desc[ISS_LENGTH]; // String for Solution Descs
};

struct manData // Structure Template for manufacturing data
{
    int lineNo;               // Line Code (1 digit)
    int batch;                // Batch Code (7 digit int)
    struct date time;         // Date (Day, Hour, Minute) (ints)
    int prod_ID;              // Product ID (9 digit int)
    struct is_info issue;     // Nested structure of issues (5 digit int & string)
    struct sol_info solution; // Nested structure of solutions (5 digit int & string)
    int empl_ID;              // Employee ID (3 digit int)
};

struct node // Structure Template for a node (data and address of next node)
{
    struct manData data; // Node data
    struct node *link;   // Pointer to next node
};

// 4. Method Signatures

// Task 1 functions
void task1(struct manData prod_line1[], struct manData prod_line2[], struct manData prod_line3[], struct manData prod_line4[]);
void prodLineSort(struct manData prod_line[]);
void displaySort(struct manData prod_line[]);

// Product ID sorting functions
void prodSort(struct manData prod_line[], int low, int high);
void prodMerge(struct manData prod_line[], int low, int mid, int high);

// Issue code sorting functions
void issueArrange(struct manData prod_line[]);
void issueSort(struct manData prod_line[], int low, int high);
void issueMerge(struct manData prod_line[], int low, int mid, int high);

// Date/time sorting functions
void dateArrange(struct manData prod_line[]);
void dateSort(struct manData prod_line[], int low, int high);
void dateMerge(struct manData prod_line[], int low, int mid, int high);

// Task 2 functions
struct node *listCreate(struct manData prod_line1[], struct manData prod_line2[], struct manData prod_line3[], struct manData prod_line4[]);
struct node *appendNode(struct node *ptr, struct manData data);
void printList(struct node *ptr);

int main()
{
    // Declaration of variables
    // Initialisation of alldata in each package (15 packages)
    // Format: Line Code, Batch Code, Date, Product ID, Issue Code + Desc, Solution Code + Desc, Employee ID

    // Production Line 1
    struct manData prod_line1[SIZE] =
        {
            {1, 9825647, {28, 8, 22}, 185723649, {32789, "Fuel pump failure"}, {86420, "Replace fuel pump"}, 128},
            {1, 3156789, {18, 14, 45}, 927361845, {81936, "GPS signal interruption"}, {50287, "Replace GPS antenna"}, 184},
            {1, 8912456, {5, 3, 10}, 536974182, {50876, "Hydraulic fluid leakage"}, {12272, "Replace hydraulic hoses"}, 186},
            {1, 7248963, {10, 5, 39}, 638927154, {59163, "Landing gear fatigue cracking"}, {85429, "Conduct non-destructive testing"}, 154},
            {1, 4785621, {16, 8, 32}, 749812536, {13579, "Engine turbine blade fracture"}, {41783, "Replace worn turbine blades"}, 125},
            {1, 4390876, {12, 4, 25}, 927361845, {94727, "Voltage regulator malfunction"}, {23917, "Update voltage regulator software"}, 152},
            {1, 6512987, {5, 18, 35}, 638927154, {59163, "Landing gear fatigue cracking"}, {10725, "Replace worn landing gear components"}, 173},
            {1, 2178643, {27, 20, 17}, 946178523, {64921, "Throttle response delay"}, {81537, "Inspect and adjust throttle linkage"}, 186},
            {1, 5367412, {8, 11, 48}, 536974182, {50876, "Hydraulic fluid leakage"}, {57236, "Repair hydraulic fluid leaks"}, 128},
            {1, 1234567, {1, 1, 30}, 987456123, {59472, "Airframe collision with birds"}, {16243, "Install bird strike prevention measures"}, 173},
            {1, 4789651, {13, 15, 22}, 867541293, {81205, "Aeroelastic flutter instability"}, {79058, "Modify aircraft structure"}, 186},
            {1, 7896542, {11, 23, 40}, 789512364, {93627, "Stuck cabin pressure valve"}, {82137, "Repair cabin pressure valve"}, 152},
            {1, 2658139, {5, 7, 53}, 927361845, {81936, "GPS signal interruption"}, {50287, "Replace GPS antenna"}, 118},
            {1, 8453762, {12, 13, 15}, 946178523, {40589, "Autopilot misconfiguration"}, {20796, "Conduct thorough autopilot checks"}, 186},
            {1, 6907382, {30, 23, 40}, 372894615, {18762, "Inadequate scheduled maintenance"}, {67035, "Fix the Problem"}, 173}};

    // Production Line 2
    struct manData prod_line2[SIZE] =
        {
            {2, 5849301, {12, 22, 45}, 327361845, {94727, "Voltage regulator malfunction"}, {58160, "Install redundant voltage regulators"}, 271},
            {2, 7263158, {22, 31, 50}, 748314236, {74128, "Fuel tank contamination"}, {50372, "Drain and clean fuel tanks"}, 274},
            {2, 3098745, {16, 26, 55}, 927361845, {81936, "GPS signal interruption"}, {50287, "Replace GPS antenna"}, 261},
            {2, 6321897, {23, 14, 20}, 448923781, {81526, "Elevator control failure"}, {51063, "Replace elevator control module"}, 210},
            {2, 8750143, {28, 2, 5}, 946178523, {93621, "Inoperative navigation lights"}, {40285, "Replace navigation light bulbs"}, 251},
            {2, 4026178, {8, 21, 40}, 372894615, {75236, "Faulty airspeed indicator"}, {49127, "Replace airspeed sensor"}, 274},
            {2, 9163820, {7, 15, 10}, 448923781, {81526, "Elevator control failure"}, {31582, "Reprogram autopilot system"}, 210},
            {2, 5432085, {20, 8, 35}, 946178523, {64921, "Throttle response delay"}, {81537, "Inspect and adjust throttle linkage"}, 245},
            {2, 7802164, {5, 15, 40}, 187523649, {58241, "Unresponsive altitude indicator"}, {86420, "Repair altitude indicator"}, 245},
            {2, 1653472, {20, 7, 55}, 732615849, {62134, "Rudder control failure"}, {40958, "Inspect rudder control linkage"}, 210},
            {2, 8902451, {25, 23, 30}, 927361845, {94727, "Voltage regulator malfunction"}, {58160, "Install redundant voltage regulators"}, 271},
            {2, 2389746, {11, 46, 50}, 789512364, {93627, "Stuck cabin pressure valve"}, {72836, "Release cabin pressure manually"}, 220},
            {2, 6941852, {10, 20, 28}, 106267292, {81266, "Inoperative cockpit display"}, {51429, "Update cockpit display firmware"}, 233},
            {2, 3216387, {11, 18, 35}, 372894615, {58319, "Flap actuator malfunction"}, {74215, "Install backup hydraulic pump"}, 245},
            {2, 1983752, {41, 40, 26}, 789512364, {93627, "Stuck cabin pressure valve"}, {32137, "Repair cabin pressure valve"}, 521},
        };

    // Production Line 3
    struct manData prod_line3[SIZE] =
        {
            {3, 8219743, {3, 15, 30}, 946178523, {64921, "Throttle response delay"}, {81537, "Inspect and adjust throttle linkage"}, 381},
            {3, 5461238, {6, 9, 45}, 867541923, {37856, "Engine ignition system malfunction"}, {69124, "Replace faulty ignition coils"}, 355},
            {3, 3981245, {9, 12, 15}, 642357819, {24681, "Broken cabin door seal"}, {57342, "Replace worn cabin door hinges"}, 355},
            {3, 6823714, {12, 18, 20}, 789654321, {21453, "Malfunctioning communication radio"}, {93478, "Perform radio system diagnostic"}, 349},
            {3, 5124698, {5, 7, 55}, 473926185, {81364, "Electrical wiring insulation damage"}, {52749, "Repair wiring harness"}, 376},
            {3, 9758236, {8, 20, 10}, 749815236, {74128, "Fuel tank contamination"}, {50372, "Drain and clean fuel tanks"}, 381},
            {3, 2641893, {19, 22, 12}, 185723649, {32789, "Fuel pump failure"}, {71506, "Inspect fuel lines for leaks"}, 391},
            {3, 7314956, {4, 10, 25}, 654987321, {54792, "Unresponsive throttle pedal"}, {31876, "Inspect throttle position sensor"}, 358},
            {3, 8726315, {7, 14, 50}, 473926185, {59472, "Airframe collision with bird"}, {93517, "Implement bird avoidance radar systems"}, 371},
            {3, 4128963, {10, 17, 35}, 372894615, {75236, "Faulty airspeed indicator"}, {49127, "Replace airspeed sensor"}, 381},
            {3, 9852614, {1, 22, 15}, 106267292, {36482, "Hydraulic system pressure drop"}, {51963, "Check and tighten hydraulic fittings"}, 397},
            {3, 7425618, {2, 5, 30}, 726148935, {14893, "Flight control surface binding"}, {62874, "Adjust flight control system"}, 371},
            {3, 6298471, {5, 13, 45}, 789654321, {92573, "Fuel gauge inaccuracies"}, {46821, "Calibrate fuel level sensors"}, 397},
            {3, 3729584, {8, 19, 20}, 852963741, {35791, "Electrical power loss"}, {31578, "Enhance battery backup systems"}, 366},
            {3, 9164723, {11, 21, 55}, 867541923, {81642, "Elevator control surface misalignment"}, {52479, "Adjust elevator trim tabs"}, 366}};

    // Production Line 4
    struct manData prod_line4[SIZE] =
        {
            {4, 9348572, {12, 5, 43}, 789512364, {93627, "Stuck cabin pressure valve"}, {82137, "Repair cabin pressure valve"}, 415},
            {4, 2169483, {29, 14, 52}, 106267292, {81266, "Inoperative cockpit display"}, {51429, "Update cockpit display firmware"}, 440},
            {4, 5738294, {7, 23, 18}, 732615849, {62134, "Rudder control failure"}, {71826, "Grease rudder control mechanism"}, 440},
            {4, 8096251, {18, 6, 55}, 852963741, {35791, "Electrical power loss"}, {31578, "Enhance battery backup systems"}, 415},
            {4, 3621749, {3, 19, 30}, 837594216, {83759, "Fuel gauge malfunction"}, {62138, "Replace fuel gauge"}, 470},
            {4, 4873156, {25, 11, 8}, 638927154, {59163, "Landing gear fatigue cracking"}, {10725, "Replace worn landing gear components"}, 444},
            {4, 7251984, {8, 3, 49}, 726148935, {14893, "Flight control surface binding"}, {62874, "Adjust flight control system"}, 415},
            {4, 1958372, {16, 10, 21}, 372894615, {59572, "Inaccurate altimeter readings"}, {32689, "Calibrate altimeter system"}, 440},
            {4, 6384921, {23, 22, 57}, 185723649, {58241, "Unresponsive altitude indicator"}, {86420, "Repair or replace altitude indicator"}, 425},
            {4, 3847269, {11, 2, 42}, 946178523, {40589, "Autopilot misconfiguration"}, {15062, "Reset autopilot settings"}, 465},
            {4, 9763128, {28, 18, 14}, 749815236, {13579, "Engine turbine blade fracture"}, {79135, "Perform vibration analysis"}, 444},
            {4, 5184397, {9, 7, 3}, 732615849, {28374, "Clogged fuel injector nozzles"}, {61947, "Clean and test fuel injectors"}, 440},
            {4, 2748951, {3, 15, 59}, 789512364, {71582, "Worn brake pads"}, {93624, "Replace brake pads and discs"}, 470},
            {4, 6938271, {14, 12, 46}, 732615849, {63978, "Engine rough idling"}, {42816, "Inspect and clean fuel injectors"}, 444},
            {4, 4857261, {6, 4, 12}, 837594216, {45928, "Engine compressor stall"}, {83759, "Repair engine compressor"}, 425}};

    // Call task one
    task1(prod_line1, prod_line2, prod_line3, prod_line4);

} // End Main

// Function to pass given structure by Prod ID, Issue Code and Date & Time
void prodLineSort(struct manData prod_line[])
{
    int high = TOTAL_SIZE - 1;
    int low = 0;

    // Deviation of merge sort function that takes manData structs instead of integer arrays
    // Call function to order product IDs in non descending order
    prodSort(prod_line, low, high);

    // Call function to order issue codes in non descending order (By Product ID)
    issueArrange(prod_line);

    // Call function to order date & time in non descending order (By Issue Code)
    dateArrange(prod_line);

    // Call function to display sorted temporary array
    displaySort(prod_line);
}

// Function to separate elements in given structure
void prodSort(struct manData prod_line[], int low, int high)
{
    // Initialise mid
    int mid;

    // Base Case: array has been checked
    if (low >= high)
    {
        return; // Pop number off stack
    } // End If
    else
    {
        // Reinitialise mid
        mid = (low + high) / 2;

        // Call Merge Sort for left side
        prodSort(prod_line, low, mid);

        // Call Merge Sort for right side
        prodSort(prod_line, mid + 1, high);

        // Call Function to put array together
        prodMerge(prod_line, low, mid, high);
    } // End Else
} // End Function

// Recursive Function to merge separated arrays back together
void prodMerge(struct manData prod_line[], int low, int mid, int high)
{
    // Initialise temporary array
    struct manData tempArr[TOTAL_SIZE];
    int i = low;     // Index for left side array
    int j = mid + 1; // Index for right side array
    int t = low;     // Index for temp array

    // While both left and right side still have elements to be checked
    while (i <= mid && j <= high)
    {
        // If number in left array is smaller than right, put left
        if (prod_line[i].prod_ID <= prod_line[j].prod_ID)
        {
            tempArr[t] = prod_line[i];
            i++; // Increment left side counter
        } // End If
        else // Else put right side
        {
            tempArr[t] = prod_line[j];
            j++; // Increment left side counter
        }

        t++; // Incremenet temporary counter
    } // End While

    // If right side finished before left
    // Fill rest of temp array with remainder of left side
    while (i <= mid)
    {
        tempArr[t] = prod_line[i];
        i++;
        t++;
    }

    // If left side finished before left
    // Fill rest of temp array with remainder of right side
    while (j < high)
    {
        tempArr[t] = prod_line[j];
        j++;
        t++;
    }

    // Put temp array contents into actual array contents
    for (i = low; i < high; i++)
    {
        prod_line[i] = tempArr[i];
    } // End For
} // End Function

// Function to arrange issue codes in order, for duplicate values
void issueArrange(struct manData prod_line[])
{
    int begin = 0; // Sets start index for merge sort
    int end = 0;   // Sets end index for merge sort
    int i;
    int curr = 0; // Index of current Product ID

    for (i = 0; i < TOTAL_SIZE; i++)
    {
        begin = i; // Sets start index for merge sort
        curr = i;  // Index of current Product ID

        // While loop to check if next product ID is the same as the current one
        while (prod_line[curr].prod_ID == prod_line[i].prod_ID)
        {
            i++;
        } // End While

        i--;
        end = i;

        issueSort(prod_line, begin, end); // Call marge sort for issue codes within common Product IDs
    } // End For
} // End Function

// Recursive Function to merge separated arrays back together
void issueMerge(struct manData prod_line[], int low, int mid, int high)
{
    // Initialise temporary array
    struct manData tempArr[TOTAL_SIZE];
    int i = low;     // Index for left side array
    int j = mid + 1; // Index for right side array
    int t = low;     // Index for temp array

    // While both left and right side still have elements to be checked
    while (i <= mid && j <= high)
    {
        // If number in left array is smaller than right, put left
        if (prod_line[i].issue.i_code <= prod_line[j].issue.i_code)
        {
            tempArr[t] = prod_line[i];
            i++; // Increment left side counter
        } // End If
        else // Else put right side
        {
            tempArr[t] = prod_line[j];
            j++; // Increment left side counter
        }

        t++; // Incremenet temporary counter
    } // End While

    // If right side finished before left
    // Fill rest of temp array with remainder of left side
    while (i <= mid)
    {
        tempArr[t] = prod_line[i];
        i++;
        t++;
    }

    // If left side finished before left
    // Fill rest of temp array with remainder of right side
    while (j < high)
    {
        tempArr[t] = prod_line[j];
        j++;
        t++;
    }

    // Put temp array contents into actual array contents
    for (i = low; i < high; i++)
    {
        prod_line[i] = tempArr[i];
    } // End For
} // End Function

// Function to separate elements in given structure
void issueSort(struct manData prod_line[], int low, int high)
{
    // Initialise mid
    int mid;

    // Base Case: Array has been checked
    if (low >= high)
    {
        return; // Pop number off stack
    } // End If
    else // Otherwise, recuresively call merge sort or merge
    {
        // Reinitialise mid
        mid = (low + high) / 2;

        // Call Merge Sort for left side
        issueSort(prod_line, low, mid);

        // Call Merge Sort for right side
        issueSort(prod_line, mid + 1, high);

        // Call Function to put array together
        issueMerge(prod_line, low, mid, high);
    } // End Else
} // End Function

// Function to arrange issue codes in order, for duplicate values
void dateArrange(struct manData prod_line[])
{
    int begin = 0; // Sets start index for merge sort
    int end = 0;   // Sets end index for merge sort
    int i;
    int curr = 0; // Index of current Product ID

    for (i = 0; i < TOTAL_SIZE; i++)
    {
        begin = i; // Sets start index for merge sort
        curr = i;  // Index of current Product ID

        // While loop to check if next product ID is the same as the current one
        while (prod_line[curr].issue.i_code == prod_line[i].issue.i_code)
        {
            i++;
        } // End While

        i--;
        end = i;

        dateSort(prod_line, begin, end); // Call marge sort for issue codes within common Product IDs
    } // End For
} // End Function

// Recursive Function to merge separated arrays back together
void dateMerge(struct manData prod_line[], int low, int mid, int high)
{
    // Initialise temporary array
    struct date tempArr[TOTAL_SIZE];
    int i = low;     // Index for left side array
    int j = mid + 1; // Index for right side array
    int t = low;     // Index for temp array

    // While both left and right side still have elements to be checked
    while (i <= mid && j <= high)
    {
        // If number in left array is smaller than right, put left
        if (prod_line[i].time.day <= prod_line[j].time.day)
        {
            tempArr[t] = prod_line[i].time;
            i++; // Increment left side counter
        } // End If
        else if (prod_line[i].time.day > prod_line[j].time.day)
        {
            tempArr[t] = prod_line[j].time;
            j++; // Increment right side counter
        } // End If
        else
        {
            if (prod_line[i].time.hour < prod_line[j].time.hour)
            {
                tempArr[t] = prod_line[i].time;
                i++; // Increment left side counter
            }
            else if (prod_line[i].time.hour > prod_line[j].time.hour)
            {
                tempArr[t] = prod_line[j].time;
                j++; // Increment right side counter
            }
            else
            {
                if (prod_line[i].time.minute < prod_line[j].time.minute)
                {
                    tempArr[t] = prod_line[i].time;
                    i++; // Increment left side counter
                }
                else
                {
                    tempArr[t] = prod_line[j].time;
                    j++; // Increment left side counter
                }
            }
        }

        t++; // Increment right side counter
    }

    // If right side finished before left
    // Fill rest of temp array with remainder of left side
    while (i <= mid)
    {
        tempArr[t] = prod_line[i].time;
        i++;
        t++;
    }

    // If left side finished before left
    // Fill rest of temp array with remainder of right side
    while (j < high)
    {
        tempArr[t] = prod_line[j].time;
        j++;
        t++;
    }

    // Put temp array contents into actual array contents
    for (i = low; i < high; i++)
    {
        prod_line[i].time = tempArr[i];
    } // End For
} // End Function

// Function to separate elements in given structure
void dateSort(struct manData prod_line[], int low, int high)
{
    // Initialise mid
    int mid;

    // Base Case: Array has been checked
    if (low >= high)
    {
        return; // Pop number off stack
    } // End If
    else // Otherwise, recuresively call merge sort or merge
    {
        // Reinitialise mid
        mid = (low + high) / 2;

        // Call Merge Sort for left side
        dateSort(prod_line, low, mid);

        // Call Merge Sort for right side
        dateSort(prod_line, mid + 1, high);

        // Call Function to put array together
        dateMerge(prod_line, low, mid, high);
    } // End Else
} // End Function

// Function for Task 1
void task1(struct manData prod_line1[], struct manData prod_line2[], struct manData prod_line3[], struct manData prod_line4[])
{
    // Copy all prod lines to one production line
    struct manData totalProdLine[TOTAL_SIZE];
    int i;
    int j = 0;

    for (i = 0; i < SIZE; i++)
    {
        totalProdLine[j] = prod_line1[i];
        j++;
    }

    for (i = 0; i < SIZE; i++)
    {
        totalProdLine[j] = prod_line2[i];
        j++;
    }

    for (i = 0; i < SIZE; i++)
    {
        totalProdLine[j] = prod_line3[i];
        j++;
    }

    for (i = 0; i < SIZE; i++)
    {
        totalProdLine[j] = prod_line4[i];
        j++;
    }

    prodLineSort(totalProdLine);

    // Copy back sorted data
    j = 0;

    for (i = 0; i < SIZE; i++)
    {
        prod_line1[j] = totalProdLine[i];
        j++;
    }

    for (i = 0; i < SIZE; i++)
    {
        prod_line2[j] = totalProdLine[i];
        j++;
    }

    for (i = 0; i < SIZE; i++)
    {
        prod_line3[j] = totalProdLine[i];
        j++;
    }

    for (i = 0; i < SIZE; i++)
    {
        prod_line4[j] = totalProdLine[i];
        j++;
    }

    // Print Separator
    printf("\n\n\n\n\n");

} // End Function

// Display all data from all prod lines
void displaySort(struct manData prod_line[])
{
    printf("\n\n| Line Code | Batch Code | Date & Time  | Product ID | Issue Codes |           Issue Descriptions          | Solution Code |         Solution Descriptions         | Employee ID |\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    // Loop through values in array and print
    for (int i = 0; i < TOTAL_SIZE; i++)
    {
        printf("|     %d     |  %d   | %d %d:%d\t| %d  |    %d    | %-37s |     %d     | %-37s |     %d     |\n",
               prod_line[i].lineNo,
               prod_line[i].batch,
               prod_line[i].time.day,
               prod_line[i].time.hour,
               prod_line[i].time.minute,
               prod_line[i].prod_ID,
               prod_line[i].issue.i_code,
               prod_line[i].issue.i_desc,
               prod_line[i].solution.s_code,
               prod_line[i].solution.s_desc,
               prod_line[i].empl_ID);

        if ((i + 1) % 15 == 0)
        {
            printf("\n");
        }
    }
} // End for
// End function

// Function for task 2 function calls
struct node *task2(struct manData prod_line1[], struct manData prod_line2[], struct manData prod_line3[], struct manData prod_line4[])
{
    // Create pointer that will point to the entire linked list (equivalent to head)
    struct node *listPtr;

    // Call function to create a linked list and copy all info to a single linked list
    listPtr = listCreate(prod_line1, prod_line2, prod_line3, prod_line4);

    // Call function to print info in linked list
    printList(listPtr);

    // Print Separator
    printf("\n\n\n\n\n");

    return listPtr;
} // End Function

// Function to create a linked list with all prod data
struct node *listCreate(struct manData prod_line1[], struct manData prod_line2[], struct manData prod_line3[], struct manData prod_line4[])
{
    // Create head node
    struct node *head = malloc(sizeof(struct node));

    // Put first struct in prod line 1 into node where head points
    head->data = prod_line1[0];
    head->link = NULL;

    // Create new pointer and point at same address in head
    struct node *ptr = head;

    // Copy all prod line data into linked list
    for (int i = 1; i < SIZE; i++)
    {
        ptr = appendNode(ptr, prod_line1[i]);
    }

    for (int i = 0; i < SIZE; i++)
    {
        ptr = appendNode(ptr, prod_line2[i]);
    }

    for (int i = 0; i < SIZE; i++)
    {
        ptr = appendNode(ptr, prod_line3[i]);
    }

    for (int i = 0; i < SIZE; i++)
    {
        ptr = appendNode(ptr, prod_line4[i]);
    }

    // Point ptr back to head
    ptr = head;

    return ptr;
} // End Function

// Function to append node to end of linked list
struct node *appendNode(struct node *ptr, struct manData data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;
    return temp;
} // End Function

// Function to print content of a single linked list
void printList(struct node *ptr)
{
    printf("\t\t|Product ID| \t | Issue Code| \t\t|Description|");

    // Check that pointer after current nide is not the tail
    while (ptr->link != NULL)
    {
        printf("\nLine Code [%d]: \t %d\t   %d  \t %s", ptr->data.lineNo, ptr->data.prod_ID, ptr->data.issue.i_code, ptr->data.issue.i_desc);

        ptr = ptr->link;
    }
}
