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
    // struct manData data; // Node data
    struct node *link; // Pointer to next node
};

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
        {1, 6907382, {30, 23, 40}, 372894615, {18762, "Inadequate scheduled maintenance"}, {67035, "Establish and adhere to maintenance schedules"}, 173}
    };

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
        {3, 7314956, {4, 10, 25}, 654987321, {54792, "Unresponsive throttle pedal"}, {31876, "Inspect and replace throttle position sensor"}, 358},
        {3, 8726315, {7, 14, 50}, 473926185, {59472, "Airframe collision with bird"}, {93517, "Implement bird avoidance radar systems"}, 371},
        {3, 4128963, {10, 17, 35}, 372894615, {75236, "Faulty airspeed indicator"}, {49127, "Replace airspeed sensor"}, 381},
        {3, 9852614, {1, 22, 15}, 106267292, {36482, "Hydraulic system pressure drop"}, {51963, "Check and tighten hydraulic fittings"}, 397},
        {3, 7425618, {2, 5, 30}, 726148935, {14893, "Flight control surface binding"}, {62874, "Adjust flight control system"}, 371},
        {3, 6298471, {5, 13, 45}, 789654321, {92573, "Fuel gauge inaccuracies"}, {46821, "Calibrate fuel level sensors"}, 397},
        {3, 3729584, {8, 19, 20}, 852963741, {35791, "Electrical power loss"}, {31578, "Enhance battery backup systems"}, 366},
        {3, 9164723, {11, 21, 55}, 867541923, {81642, "Elevator control surface misalignment"}, {52479, "Adjust elevator trim tabs"}, 366}
    };

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
        {4, 4857261, {6, 4, 12}, 837594216, {45928, "Engine compressor stall"}, {83759, "Repair engine compressor"}, 425}
    };

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