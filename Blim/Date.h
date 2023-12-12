#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include<string>
#include<iostream>
#include<ctime>
#include<vector>

class Date{
    private:
        int year;
        std::string month;
        int day;
        int hour;
        int minute;

    public:
		Date();
		Date(const Date&);


    int getYear();
    std::string getMonth();
    std::string getDay();
    int getHour();
    int getMinute();

    std::string toString();

    void setYear(const int&);
    void setMonth(const int&);
    void setDay(const int&);


    Date& operator = (const Date&);

    ///Para imprimir
    friend std::ostream& operator << (std::ostream& os, const Date& dt) {

    os << dt.day << " | " << dt.month << " | " << std::to_string(dt.year);

    return os;
    }
};


Date::Date() { }

Date::Date(const Date& d) : year(d.year), month(d.month), day(d.day) { }

int Date::getYear() {

    time_t now = time(0);
    tm*time = localtime(&now);

    int year = 1900 + time->tm_year;

	return year;
}

string Date::getMonth() {

    time_t now = time(0);
    tm*time = localtime(&now);
    vector<string> month;
    month.push_back("Enero");
    month.push_back("Febrero");
    month.push_back("Marzo");
    month.push_back("Abril");
    month.push_back("Mayo");
    month.push_back("Junio");
    month.push_back("Julio");
    month.push_back("Agosto");
    month.push_back("Septiembre");
    month.push_back("Octubre");
    month.push_back("Noviembre");
    month.push_back("Diciembre");

    //month[time->tm_mon];

	return month[time->tm_mon];
}

string Date::getDay() {

    time_t now = time(0);
    tm*time = localtime(&now);
    vector<string> day;
    day.push_back("Domingo");
    day.push_back("Lunes");
    day.push_back("Martes");
    day.push_back("Miercoles");
    day.push_back("Jueves");
    day.push_back("Viernes");
    day.push_back("Sabado");

	return day[time->tm_wday];
}

int Date::getHour()
{
    time_t now = time(0);
    tm*time = localtime(&now);

    return time->tm_hour;
}

int Date::getMinute()
{
    time_t now = time(0);
    tm*time = localtime(&now);

    return time->tm_min;
}
string Date::toString(){
	char myDate[11];

	sprintf(myDate, "%04i/%02i/%02i", year, month, day);

	return myDate;
}

void Date::setYear(const int& y) {
	year = y;
}

void Date::setMonth(const int& m) {
	month = m;
}

void Date::setDay(const int& d) {
	day = d;
}

Date& Date::operator=(const Date& d) {
	year =  d.year;
	month = d.month;
	day = d.day;

	return *this;
}

#endif // DATE_H_INCLUDED
