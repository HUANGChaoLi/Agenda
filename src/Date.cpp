#include "Date.h"
#include <string>
#include <iostream>

int str_to_int(const std::string & one, int b, int e) {
    int num = 0;
    int i;
    for (i = b; i <= e; ++i) {
        num = num * 10 + one[i] - '0';
    }
    return num;
}

std::string int_to_str(int num) {
    if (num == 0) return "00";
    std::string result;
    int num_ = num;
    while (num_) {
        result += (num_ % 10) + '0';
        num_ /= 10;
    }
    if (num < 10) result += '0';
    std::string re;
    for (int i = result.size() - 1; i >= 0; --i) {
        re += result[i];
    }
    return re;
}

Date::Date() {
    year_ = 1000; month_ = 1; day_ = 1;
    hour_ = 0; minute_ = 0;
}

Date::Date(int y, int m, int d, int h, int mi) {
    year_ = y; month_ = m; day_ = d;
    hour_ = h; minute_ = mi;
}

int Date::getYear(void) const {
    return year_;
}

void Date::setYear(int year) {
    year_ = year;
}

int Date::getMonth(void) const {
    return month_;
}

void Date::setMonth(int month) {
    month_ = month;
}

int Date::getDay(void) const {
    return day_;
}

void Date::setDay(int day) {
    day_ = day;
}

int Date::getHour(void) const {
    return hour_;
}

void Date::setHour(int hour) {
    hour_ = hour;
}

int Date::getMinute(void) const {
    return minute_;
}

void Date::setMinute(int minute) {
    minute_ = minute;
}

bool Date::isValid(Date date) {
    if (date.year_ < 1000 || date.year_ > 9999) return false;
    if (date.month_ < 1 || date.month_ > 12) return false;
    if (date.hour_ < 0 || date.hour_ >= 24) return false;
    if (date.minute_ < 0 || date.minute_ >= 60) return false;
    if (date.day_ <= 0 || date.day_ > 31) return false;
    int m = date.month_;
    if ((m == 4 || m == 6 || m == 9 || m == 11) && (date.day_ == 31))
	return false;
    if (m == 2) {
        int y = date.year_;
        if ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0)) {
            if (date.day_ > 29) return false;
        } else if (date.day_ > 28) {
            return false;
        }
    }
    return true;
}

Date Date::stringToDate(std::string dateString) {
    int i, j, y, m, d, h, mi;
    i = 0;
    for (j = i; j < dateString.size(); ++j) {
        if (dateString[j] == '-') break;
    }
    y = str_to_int(dateString, i, j - 1);
    i = j + 1;
    for (j = i; j < dateString.size(); ++j) {
        if (dateString[j] == '-') break;
    }
    m = str_to_int(dateString, i, j - 1);
    i = j + 1;
    for (j = i; j < dateString.size(); ++j) {
        if (dateString[j] == '/') break;
    }
    d = str_to_int(dateString, i, j - 1);
    i = j + 1;
    for (j = i; j < dateString.size(); ++j) {
        if (dateString[j] == ':') break;
    }
    h = str_to_int(dateString, i, j - 1);
    i = j + 1;
    mi = str_to_int(dateString, i, dateString.size() - 1);
    return Date(y, m, d, h, mi);
}

std::string Date::dateToString(Date date) {
    std::string ooo;
    std::string result;
    result += int_to_str(date.year_);
    if (result == "00") {
        result = "0000";
    } else {
        for (int i = 4 - result.size(); i > 0; --i) ooo += '0';
        result = ooo + result;
    }
    result += '-';
    result += int_to_str(date.month_);
    result += '-';
    result += int_to_str(date.day_);
    result += '/';
    result += int_to_str(date.hour_);
    result += ':';
    result += int_to_str(date.minute_);
    return result;
}

Date & Date::operator=(const Date& date) {
    year_ = date.year_; month_ = date.month_; day_ = date.day_;
    hour_ = date.hour_; minute_ = date.minute_;
}

bool Date::operator==(const Date& date) const {
    return dateToString(*this) == dateToString(date);
}

bool Date::operator>(const Date& date) const {
    return dateToString(*this) > dateToString(date);
}

bool Date::operator<(const Date& date) const {
    return dateToString(*this) < dateToString(date);
}

bool Date::operator>=(const Date& date) const {
    return dateToString(*this) >= dateToString(date);
}

bool Date::operator<=(const Date& date) const {
    return dateToString(*this) <= dateToString(date);
}

