/**
 *   @file: appointment.cc
 * @author: Hunter Stout
 *   @date: November 16, 2021
 *  @brief: Appointment Assignment (Class functions).
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <string>
#include "appointment.h"
using namespace std;
/**
 * whitespace_Annihilator - Removes whitespaces from end of a string.
 * @param input - String with extra whitespaces.
 * @return - Finished string.
 */
string whitespace_Annihilator(string input);
/**
 * stringToInt - Checks if a string is eligible to become and integer, then converts.
 * @param str - Input string.
 * @return - finished integer.
 */
int stringToInt(string str);

//########################################## ↓ ↓ ↓   C O N S T R U C T O R S   ↓ ↓ ↓ ##########################################
Appointment::Appointment(){
    //Default inputs.
    title = "N/A";
    year = 1;
    month = 1;
    day = 1;
    time = 0;
    duration = 1;
    date = "N/A";
    standardTime = "N/A";
}
Appointment::Appointment(string appData) {
    //Default inputs.
    title = "N/A";
    year = 1;
    month = 1;
    day = 1;
    time = 0;
    duration = 1;
    date = "N/A";
    standardTime = "N/A";

    //Deciphers line input.
    int length = appData.length(), ch_Counter = 0, int_Placeholder;
    string placeholder, ch = "|";

    //Counts dividers in application.
    for (int i = 0; i < length; i++) {
        string ad_Ch = appData.substr(i, 1);
        if (ad_Ch == ch) {
        ch_Counter++;
        }
    }
    //Checks for valid appointment application.
    if (ch_Counter == 5) {
        //Loop breaks down string to correct member variables.
        for(int s_Counter = 1; s_Counter < 6; s_Counter++) {
            int position = appData.find("|", 0);
            if (position >= 0) {
                //Breaks down string after every breaker.
                placeholder = appData.substr(0, position);
                position++;
                appData.erase(0, position);
                placeholder = whitespace_Annihilator(placeholder);
            }
                //#1, Assigns Title.
                if (s_Counter == 1) { 
                    setTitle(placeholder);
                }
                //#2, Assigns Year.
                else if (s_Counter == 2) {
                    int_Placeholder = stringToInt(placeholder);
                    setYear(int_Placeholder);
                }
                //#3, Assigns Month.
                else if (s_Counter == 3) {
                    int_Placeholder = stringToInt(placeholder);
                    setMonth(int_Placeholder);
                }
                //#4, Assigns Day.
                else if (s_Counter == 4) {
                    int_Placeholder = stringToInt(placeholder);
                    setDay(int_Placeholder);
                }
                //#5, Assigns Time.
                else if (s_Counter == 5) {
                    //Checks to see if time entered is military or standard.
                    int size = placeholder.length();
                        for (int j = 0; j < size; j++) {
                            placeholder[j] = tolower(placeholder[j]);
  	                    }
                    int pos1 = placeholder.find("am", 0), pos2 = placeholder.find("pm", 0);
                    if (pos1 >= 0 || pos2 >= 0) {
                        //Run standard to military.
                        setTime(standardToMilitary(placeholder));
                        militaryToStandard(getTime());
                    }
                    else {
                        //Run military to standard
                        int_Placeholder = stringToInt(placeholder);
                        setTime(int_Placeholder);
                        militaryToStandard(getTime());
                    }
                }
        } //end of loop.

                //Checks to make sure the string end is not blank.
                if (appData == "") {
                    appData = "-10";
                }
                //#6, Assigns Duration.
                else {
                    appData = whitespace_Annihilator(appData);
                    int_Placeholder = stringToInt(appData);
                    setDuration(int_Placeholder);
                }
        //Sets date.
        setDate(getYear(), getMonth(), getDay());
    }
    //Output for in-valid appointment application.
    else {
        cout << endl;
        cout << "Incorrect input, must include 5 spacers ( | ) to file appointment." << endl;
    }
}
//########################################## ↑ ↑ ↑   C O N S T R U C T O R S   ↑ ↑ ↑ ##########################################


//############################################### ↓ ↓ ↓   G E T T E R S   ↓ ↓ ↓ ###############################################
string Appointment::getTitle() const{
    return title;
}
int Appointment::getYear() const{
    return year;
}
int Appointment::getMonth() const{
    return month;
}
int Appointment::getDay() const{
    return day;
}
int Appointment::getTime() const{
    return time;
}
int Appointment::getDuration() const{
    return duration;
}
string Appointment::getDate() const{
    return date;
}
string Appointment::getStandardTime() const{
    return standardTime;
}
//############################################### ↑ ↑ ↑   G E T T E R S   ↑ ↑ ↑ ###############################################


//############################################### ↓ ↓ ↓   S E T T E R S   ↓ ↓ ↓ ###############################################
void Appointment::setTitle(string newTitle) {
    if (newTitle != "") {
        title = whitespace_Annihilator(newTitle);
    }
}
void Appointment::setYear(int newYear) {
    if (newYear >= 2021 && newYear <= 2030)
    {
        year = newYear;
    }
}
void Appointment::setMonth(int newMonth) {
    if (newMonth >= 1 && newMonth <= 12)
    {
        month = newMonth;
    }
}
void Appointment::setDay(int newDay) {
    if (newDay >= 1 && newDay <= 31)
    {
        day = newDay;
    }
}
void Appointment::setTime(int newTime) {
    if (newTime >= 0 && newTime <= 2359)
    {
        time = newTime;
    }
}
void Appointment::setDuration(int newDuration) {
    if (newDuration >= 1 && newDuration <= 120)
    {
        duration = newDuration;
    }
}
void Appointment::setDate(int newYear, int newMonth, int newDay) {
    string placeholder, space = "-", y_ph = to_string(newYear);
    string m_ph = to_string(newMonth), d_ph = to_string(newDay);
    placeholder = y_ph;
    placeholder += space;
    placeholder += m_ph;
    placeholder += space;
    placeholder += d_ph;
    date = placeholder;
}

//############################################### ↑ ↑ ↑   S E T T E R S   ↑ ↑ ↑ ###############################################


//############################################### ↓ ↓ ↓   H E L P E R S   ↓ ↓ ↓ ###############################################
string Appointment::militaryToStandard(int time) {
    string placeholder = to_string(time), firstHalf, secondHalf;
    int size = placeholder.length();
        //Adjusts time to 4 digits.
        for (int i = 4; i > size; i--) {
            placeholder.insert(0, "0");
        }
    //Breaks time in half.
    firstHalf = placeholder.substr(0, 2);
    secondHalf = placeholder.substr(2, 2);
        //Checks to make sure second half is under 60.
        if (stoi(secondHalf) >= 60) {
            secondHalf = "59";
        }
        //12:00AM
        if (stoi(firstHalf) == 0) {
            firstHalf = "12:AM";
        }
        //1:00AM-11:00AM
        else if (stoi(firstHalf) >= 1 && stoi(firstHalf) <= 11) {
            int am = firstHalf.find("0", 0);
            if (am == 0) {
                firstHalf.erase(0, 0);
                firstHalf += ":AM";
            }
            else {
                firstHalf += ":AM";
            }
        }
        //12:00PM
        else if (stoi(firstHalf) == 12) {
            firstHalf = "12:PM";
        }
        //1:00PM-11:00PM
        else if (stoi(firstHalf) >= 13 && stoi(firstHalf) <= 23) {
            int pm = stoi(firstHalf), num = 0;
            for (int j = 12; j < pm; j++) {
                num++;
            }
            firstHalf = to_string(num);
            firstHalf += ":PM";
        }
    //Completes time string.
    int position = firstHalf.find(":", 0);
    position++;
    secondHalf.insert(2, " ");
    firstHalf.insert(position, secondHalf);
    standardTime = firstHalf;
    return (standardTime);
}
int Appointment::standardToMilitary(string time) {
    //Turns lowercase & deleted whitespaces if manual input.
    time = whitespace_Annihilator(time);
    int size = time.length();
    for (int i = 0; i < size; i++) {
        time[i] = tolower(time[i]);
  	}
    //Starts here for non-manual input.
    string firstHalf, secondHalf;
    int position1 = time.find(":", 0), am_Pm = 0, finalTime;
        if (position1 >= 0) { //removes : in entered time.
            time.erase(position1, 1);
        }
    int position2 = time.find("am", 0);
        if (position2 >= 0) {
            time.erase(position2, 2);
            am_Pm = 1; //sets to am.
        }
    int position3 = time.find("pm", 0);
        if (position3 >= 0) {
            time.erase(position3, 2);
            am_Pm = 2; // sets to pm.
        }
    //Works up to here breaking it down
    int length = time.length();
        if (length == 3) {
            //number under 10
            firstHalf = time.substr(0, 1);
            secondHalf = time.substr(1, 2);
        }
        else if (length == 4) {
            //0 start, 10, 11, or 12.
            firstHalf = time.substr(0, 2);
            secondHalf = time.substr(2, 2);
        }
            //Standard time set to default if incorrect input.
        else if (length < 3 || length > 4) {
            firstHalf = "00";
            secondHalf = "00";
        }
    //Checks to make sure second half is under 60.
    if (stoi(secondHalf) >= 60) {
        secondHalf = "59";
    }
    finalTime = stoi(firstHalf);
        //AM route.
        if (am_Pm == 1) {
            //12:00AM
            if (finalTime == 12) {
                finalTime = 0;
            }
        }
        //PM route.
        else if (am_Pm == 2) {
            //12:00PM
            if (finalTime == 12) {
                finalTime = 12;
            }
            else if(finalTime >= 1 && finalTime < 12) {
                int newFinalTime = 13;
                for (int j = 1; j < finalTime; j++) {
                newFinalTime++;
                }
                finalTime = newFinalTime;
            }
        }
    firstHalf = to_string(finalTime);
    firstHalf += secondHalf;
    finalTime = stoi(firstHalf);
    return(finalTime);
}
bool operator == (const Appointment &first, const Appointment &second) {
    if (first.getTitle() == second.getTitle() &&
    first.getYear() == second.getYear() &&
    first.getMonth() == second.getMonth() &&
    first.getDay() == second.getDay() &&
    first.getTime() == second.getTime() &&
    first.getDuration() == second.getDuration()) {
        return true;
    }
    return false;
}
void Appointment::output(){
    //Adjusts time to 4 digits.
    string time_Placeholder = to_string(time);
    int size = time_Placeholder.length();
    for (int i = 4; i > size; i--) {
        time_Placeholder.insert(0, "0");
    }
    //Output
    cout << endl;
    cout << " | " << title << " | " << year << " | " << month << " | ";
    cout << day << " | " << standardTime << " (" << time_Placeholder << ")" << " | " << duration << " | " << endl;
    cout << " | Date: " << date << endl;
}
//############################################### ↑ ↑ ↑   H E L P E R S   ↑ ↑ ↑ ###############################################


//######################################## ↓ ↓ ↓   E X T R A  F U N C T I O N S   ↓ ↓ ↓ #######################################
string whitespace_Annihilator(string input) {
    //Removes whitespaces from a string.
    int size = input.length();
        for(int j = 0; j <= size; j++) {

            for(int i = 0; i <= j; i++) {

                if(input[i] == ' ' && input[i + 1] == ' ') {
                    input.erase(input.begin() + i);
                }
                else if(input[0]== ' ') {
                    input.erase(input.begin());
                }
                else if(input[i] == '\0' && input[i - 1] == ' ') {
                    input.erase(input.end() - 1);
                }
            }
        }
    return (input);
}

int stringToInt(string str) {
    //Checks to make sure string is eligable to be an integer then converts it.
    int check = 1, number, length = str.length();
    for (int i = 0; i < length; i++) {
        if (! isdigit(str[i])) {
            check = 0;
        }
    }
    if (check == 1) {
        number = stoi(str);
    }
    else if (check == 0) {
        number = -10;
    }
    return (number);
}
//######################################## ↑ ↑ ↑   E X T R A  F U N C T I O N S   ↑ ↑ ↑ #######################################
