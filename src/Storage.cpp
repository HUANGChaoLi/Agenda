#include "Storage.h"
#include "Meeting.h"
#include "User.h"
#include "Date.h"
#include <functional>
#include <stack>
#include <fstream>
#include <iostream>
const char * File = "./";

bool Check(const std::string & one) {
    return one == "\"name\",\"password\",\"email\",\"phone\"" ||
	   one == "\"sponsor\",\"participator\",\"sdate\",\"edate\",\"title\"";
} // check PB whether is wrong;

std::string get_str(const std::string & one, int b, int e) {
    std::string result;
    for (int i = b; i <= e; ++i) {
        if (one[i] == '\"') ++i;
        result += one[i];
    }
    return result;
}

Storage * Storage::instance_ = NULL;

Storage::Storage() {
    std::string writer_1(File);
    writer_1 += "User.csv";
    std::ifstream check(writer_1.c_str());
    if (check) {
        check.close();
    } else {
        std::string writer_2(File);
        writer_2 += "Meeting.csv";
        std::ofstream user(writer_1.c_str());
        std::ofstream meeting(writer_2.c_str());
        user.close(); meeting.close();
    }
    readFromFile(File);
}

bool Storage::readFromFile(const char *fpath) {
    userList_.clear(); meetingList_.clear();
    std::string writer_1(fpath), writer_2(fpath);
    writer_1 += "User.csv"; writer_2 += "Meeting.csv";
    std::ifstream user(writer_1.c_str());
    std::ifstream meeting(writer_2.c_str());
    if (!(user && meeting)) {
        if (user) user.close();
        if (meeting) meeting.close();
        return false;
    }
    std::string get;
    int a, b, c, d, now;
    int i, j;
    // std::getline(user, get);
    while (std::getline(user, get)) {
        if (Check(get)) continue; // here;
        now = a = b = c = 0;
        while ((!a || !b || !c)) {
            bool here = true;
            for (i = now; i < get.size(); ++i) {
                if (get[i] == '\"') {
                    here = !here;
                } else if (get[i] == ',') {
                    if (here) {
                        if (!a) a = i;
                        else if (!b) b = i;
                        else if (!c) c = i;
                        now = i + 1;
                        break;
                    }
                }
            }
        }
        userList_.push_back(User(get_str(get, 1, a - 2), get_str(get, a + 2, b - 2),
                get_str(get, b + 2, c - 2), get_str(get, c + 2, get.size() - 2)));
    }
    // std::getline(meeting, get);
    while (std::getline(meeting, get)) {
        if (Check(get)) continue;
        now = a = b = c = d = 0;
        while (!a || !b || !c || !d) {
            bool here = true;
            for (i = now; i < get.size(); ++i) {
                if (get[i] == '\"') {
                    here = !here;
                } else if (get[i] == ',') {
                    if (here) {
                        if (!a) a = i;
                        else if (!b) b = i;
                        else if (!c) c = i;
                        else if (!d) d = i;
                        now = i + 1;
                        break;
                    }
                }
            }
        }
        meetingList_.push_back(Meeting(get_str(get, 1, a - 2), get_str(get, a + 2, b - 2),
            Date::stringToDate(get_str(get, b + 2, c - 2)), Date::stringToDate(get_str(get, c + 2, d - 2)),
            get_str(get, d + 2, get.size() - 2)));
    }
    meeting.close(); user.close();
    return true;
}

bool Storage::writeToFile(const char *fpath) {
    std::string writer_1(fpath), writer_2(fpath);
    writer_1 += "User.csv"; writer_2 += "Meeting.csv";
    std::ofstream user(writer_1.c_str());
    std::ofstream meeting(writer_2.c_str());
    if (!(user && meeting)) {
        if (user) user.close();
        if (meeting) meeting.close();
        return false;
    }
    user << "\"name\",\"password\",\"email\",\"phone\"" << std::endl;
    std::list<User>::iterator it;
    std::string test;
    std::size_t i;
    for (it = userList_.begin(); it != userList_.end(); ++it) {
        user << "\""; 
        test = it->getName();
        for (i = 0; i < test.size(); ++i) {
            if (test[i] == '\"') {user << "\"\"";}
            else user << test[i];
        }
        user << "\",\"";
        test = it->getPassword();
        for (i = 0; i < test.size(); ++i) {
            if (test[i] == '\"') {user << "\"\"";}
            else user << test[i];
        }
        user << "\",\"";
        test = it->getEmail();
        for (i = 0; i < test.size(); ++i) {
            if (test[i] == '\"') {user << "\"\"";}
            else user << test[i];
        }
        user << "\",\"";
        test = it->getPhone();
        for (i = 0; i < test.size(); ++i) {
            if (test[i] == '\"') {user << "\"\"";}
            else user << test[i];
        }
        user << "\"" << std::endl;
    }
    user.close();
    meeting << "\"sponsor\",\"participator\",\"sdate\",\"edate\",\"title\"" << std::endl;
    std::list<Meeting>::iterator jt;
    for (jt = meetingList_.begin(); jt != meetingList_.end(); ++jt) {
        meeting << "\"";
        test = jt->getSponsor();
        for (i = 0; i < test.size(); ++i) {
            if (test[i] == '"') meeting << "\"\"";
            else meeting << test[i];
        }
        meeting << "\",\"";
        test = jt->getParticipator();
        for (i = 0; i < test.size(); ++i) {
            if (test[i] == '"') {meeting << "\"\"";}
            else meeting << test[i];
        }
        meeting << "\",\"";
        meeting << Date::dateToString(jt->getStartDate());
        meeting << "\",\"";
        meeting << Date::dateToString(jt->getEndDate());
        meeting << "\",\"";
        test = jt->getTitle();
        for (i = 0; i < test.size(); ++i) {
            if (test[i] == '\"') {meeting << "\"\"";}
            else meeting << test[i];
        }
        meeting << "\"" << std::endl;
    }
    meeting.close();
    return true;
}

Storage * Storage::getInstance(void) {
    if (instance_) return instance_;
    instance_ = new Storage();
    return instance_;
}

Storage::~Storage() {
    writeToFile(File);
    instance_ = NULL;
}

void Storage::createUser(const User & newone) {
    userList_.push_back(newone);
}

std::list<User> Storage::queryUser(std::function<bool(const User&)> filter) {
    std::list<User> result;
    std::list<User>::iterator it;
    for (it = userList_.begin(); it != userList_.end(); ++it) {
        if (filter(*it)) {
            result.push_back(*it);
        }
    }
    return result;
}

int Storage::updateUser(std::function<bool(const User&)> filter,
        std::function<void(User&)> switcher) {
    int result = 0;
    std::list<User>::iterator it;
    for (it = userList_.begin(); it != userList_.end(); ++it) {
        if (filter(*it)) {
            switcher(*it); ++result;
        }
    }
    return result;
}

int Storage::deleteUser(std::function<bool(const User&)> filter) {
    int before = userList_.size();
    std::list<User>::iterator it;
    for (it = userList_.begin(); it != userList_.end(); ) {
        if (filter(*it)) {
            it = userList_.erase(it);
        } else {
            ++it;
        }
    }
    return before - userList_.size();
}

void Storage::createMeeting(const Meeting & newone) {
    meetingList_.push_back(newone);
}

std::list<Meeting> Storage::queryMeeting(std::function<bool(const Meeting&)> filter) {
    std::list<Meeting> result;
    std::list<Meeting>::iterator it;
    for (it = meetingList_.begin(); it != meetingList_.end(); ++it) {
        if (filter(*it)) {
            result.push_back(*it);
        }
    }
    return result;
}

int Storage::updateMeeting(std::function<bool(const Meeting&)> filter,
            std::function<void(Meeting&)> switcher) {
    int result = 0;
    std::list<Meeting>::iterator it;
    for (it = meetingList_.begin(); it != meetingList_.end(); ++it) {
        if (filter(*it)) {
            switcher(*it); ++result;
        }
    }
    return result;
}

int Storage::deleteMeeting(std::function<bool(const Meeting&)> filter) {
    int before = meetingList_.size();
    std::list<Meeting>::iterator it;
    for (it = meetingList_.begin(); it != meetingList_.end(); ) {
        if (filter(*it)) {
            it = meetingList_.erase(it);
        } else {
            ++it;
        }
    }
    return before - meetingList_.size();
}

bool Storage::sync(void) {
    return writeToFile(File);
}

