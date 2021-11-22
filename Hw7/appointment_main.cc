/**
 *   @file: appointment_main.cc
 * @author: Hunter Stout
 *   @date: November 16, 2021
 *  @brief: Appointment Assignment (Main).
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <string>
#include "appointment.h"
using namespace std;

//################################################## ↓ ↓ ↓   M A I N   ↓ ↓ ↓ ##################################################
int main(int argc, char const *argv[]) {
    //Declare appointment class in main.
    Appointment first;

    // Test 1, ######### Default output #########
    cout << endl << "#########   D E F A U L T   O U T P U T   ##########" << endl;
    first.output();
    cout << endl << endl;

    // Test 2, ######### Manual input ##########
    first.setTitle("    Pediatric checkup        ");
    first.setYear(2021);
    first.setMonth(12);
    first.setDay(23);
    first.setTime(830);
    first.setTime(first.standardToMilitary("     4:44pM      "));
    first.setDuration(15);
    //Need these functions when manually inputting!
    first.setDate(first.getYear(), first.getMonth(), first.getDay());
    first.militaryToStandard(first.getTime());
    first.standardToMilitary(first.getStandardTime());
    //Output for manual test.
    cout << endl;
    cout << "##########   M A N U A L   O U T P U T   ###########" << endl;
    first.output();
    cout << endl << endl;

    // Test 3, ######### User input ##########
    string input;
    cout << endl << "#############   U S E R    I N P U T   #############" << endl << endl;
    cout << "Format: title | year | month | day | time | duration" << endl << endl;
    cout << "Schedule an appointment: ";
    getline(cin, input);
    Appointment second(input);
    //Output for user test.
    cout << endl << endl << "##########   U S E R ' S   O U T P U T   ###########" << endl;
    second.output();
    cout << endl << endl;
    //friend (bool == appointment 1 & 2) function test.
    if (first == second) {
        cout << endl << "Appointment 1 & 2 are equal." << endl;
    }
    else {
        cout << endl << "Appointment 1 & 2 are not equal." << endl;
    }

    return 0;
}
//################################################## ↑ ↑ ↑   M A I N   ↑ ↑ ↑ ##################################################