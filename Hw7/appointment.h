/**
 *   @file: appointment.h
 * @author: Hunter Stout
 *   @date: November 16, 2021
 *  @brief: Appointment Assignment (Header).
 */

#ifndef APPOINTMENT_H
#define APPOINTMENT_H

class Appointment{
//Class functions.
public:

//Constructors
    /**
    * Appointment - Default constructor.
    * @return - Program defaults.
    */
    Appointment();
    /**
    * Appointment - Secondary constructor (breaks down input string).
    * @param appData - appointment input.
    * @return - Program defaults or adjusts member variables accordingly.
    */
    Appointment(std::string appData);

//Setters
    /**
    * setTitle - Sets title.
    * @param newTitle - Current title.
    */
    void setTitle(std::string newTitle);
    /**
    * setYear - Sets year.
    * @param newYear - Current year.
    */
    void setYear(int newYear);
    /**
    * setMonth - Sets month.
    * @param newMonth - Current month.
    */
    void setMonth(int newMonth);
    /**
    * setDay - Sets day.
    * @param newDay - Current day.
    */
    void setDay(int newDay);
    /**
    * setTime - Sets military time.
    * @param newTime - Current time.
    */
    void setTime(int newTime);
    /**
    * setDuration - Sets duration.
    * @param newDuration - Current duration.
    */
    void setDuration(int newDuration);
    /**
    * setDate - Sets entire date (year-month-day).
    * @param newYear - Current year.
    * @param newMonth - Current month.
    * @param newDay - Current day.
    */
    void setDate(int newYear, int newMonth, int newDay);

//getters
    /**
    * getTitle - Updates title.
    * @return - Title.
    */
    std::string getTitle() const;
    /**
    * getYear - Updates year.
    * @return - Year.
    */
    int getYear() const;
    /**
    * getMonth - Updates month.
    * @return - Month.
    */
    int getMonth() const;
    /**
    * getDay - Updates day.
    * @return - Day.
    */
    int getDay() const;
    /**
    * getTime - Updates military time.
    * @return - Time.
    */
    int getTime() const;
    /**
    * getDuration - Updates duration.
    * @return - Duration.
    */
    int getDuration() const;
    /**
    * getDate - Updates date (year-month-day).
    * @return - Date.
    */
    std::string getDate() const;
    /**
    * getStandardTime - Updates standard time.
    * @return - StandardTime.
    */
    std::string getStandardTime() const;

//helper function
    /**
    * militaryToStandard - Converts military time to standard.
    * @param time - Military time.
    * @return - Standard time.
    */
    std::string militaryToStandard(int time);
    /**
    * standardToMilitary - Converts standard time to military.
    * @param time - Standard time.
    * @return - Military time.
    */
    int standardToMilitary(std::string time);
    /**
    * operator - Compares first appointment with second appointment.
    * @param first - First appointment.
    * @param second - Second appointment.
    * @return - True or False.
    */
    friend bool operator == (const Appointment &first, const Appointment &second);
    /**
    * output - Outputs appointment results.
    */
    void output();

//Member variables
private:
    std::string title;
    int year;
    int month;
    int day;
    int time; //Military Time
    int duration;
    std::string date; //(year-month-day)
    std::string standardTime;
};

#endif