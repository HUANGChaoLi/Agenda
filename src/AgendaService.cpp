#include "AgendaService.h"
#include "Storage.h"
#include "User.h"
#include "Date.h"
#include "Meeting.h"
#include <list>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>

bool Check_(const std::string & one) {
    return one == "\"name\",\"password\",\"email\",\"phone\"" ||
	   one == "\"sponsor\",\"participator\",\"sdate\",\"edate\",\"title\"";
}

std::string get_str_(const std::string & one, int b, int e) {
    std::string result;
    for (int i = b; i <= e; ++i) {
        if (one[i] == '\"') ++i;
        result += one[i];
    }
    return result;
}

bool Check_Date(const std::string & one);

std::list<Meeting> meetingReadFromFile(std::string file) { // no problem
    std::ifstream meeting(file.c_str());
    std::list<Meeting> meetingList_;
    if (!meeting) {
         std::cout << "---------------------------------- [ Error ] ----------------------------------" << std::endl
                   << "- [ File ] ~ No such a file Path. Please try again.                           -" << std::endl
                   << "-------------------------------------------------------------------------------" << std::endl;
         return meetingList_;
    }
    std::string get;
    int a, b, c, d, now, i;
    while (std::getline(meeting, get)) {
        if (Check_(get)) continue;
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
        meetingList_.push_back(Meeting(get_str_(get, 1, a - 2), get_str_(get, a + 2, b - 2),
            Date::stringToDate(get_str_(get, b + 2, c - 2)), Date::stringToDate(get_str_(get, c + 2, d - 2)),
            get_str_(get, d + 2, get.size() - 2)));
    }
    meeting.close();
    return meetingList_;
}

bool meetingWriteToFile(const std::list<Meeting> & meetingList_, const std::string & file) {  // no problem
    std::ifstream meeting_(file.c_str());
    if (!meeting_) {
        std::cout << "---------------------------------- [ Error ] ----------------------------------" << std::endl
                  << "- [ File ] ~ No such a file Path. Please try again.                           -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
        return false;
    }
    meeting_.close();
    std::ofstream meeting(file.c_str());
    meeting << "\"sponsor\",\"participator\",\"sdate\",\"edate\",\"title\"" << std::endl;
    std::list<Meeting>::const_iterator jt;
    std::string test;
    int i;
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

bool userWriteToFile(const std::list<User> & userList_, std::string file) {  // no problem
    std::ifstream user_(file.c_str());
    if (!user_) {
        std::cout << "---------------------------------- [ Error ] ----------------------------------" << std::endl
                  << "- [ File ] ~ No such a file Path. Please try again.                           -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
        return false;
    }
    user_.close();
    std::ofstream user(file.c_str());
    user << "\"name\",\"email\",\"phone\"" << std::endl;
    std::list<User>::const_iterator it;
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
    return true;
}

std::list<User> userReadFromFile(std::string file) { // no problem
    std::ifstream user(file.c_str());
    std::list<User> userList_;
    if (!user) {
        std::cout << "---------------------------------- [ Error ] ----------------------------------" << std::endl
                  << "- [ File ] ~ No such a file Path. Please try again.                           -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
        return userList_;
    }
    std::string get;
    int a, b, c, now;
    int i, j;
    while (std::getline(user, get)) {
        if (Check_(get)) continue;
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
        userList_.push_back(User(get_str_(get, 1, a - 2), get_str_(get, a + 2, b - 2),
                get_str_(get, b + 2, c - 2), get_str_(get, c + 2, get.size() - 2)));
    }
    user.close();
    return userList_;
}

//////  /* new */  ////////////////////////////////

bool AgendaService::userRegisterByFile(std::string file) {
    std::list<User> Register = userReadFromFile(file);
    if (Register.size() == 0) return false;
    std::list<User>::iterator it = Register.begin();
    std::cout << std::endl << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl;
    for (; it != Register.end(); ++it) {
        if (userRegister(it->getName(), it->getPassword(), it->getEmail(), it->getPhone())) {
            std::cout << "- [User] " << std::setw(20) << std::left << it->getName()
                << "  Register Succeed !!!                           -" << std::endl;
        } else {
            std::cout << "- [User] " << std::setw(20) << std::left << it->getName()
                << "  Register Fail !!!                              -" << std::endl;
        }
    }
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    return true;
}

bool AgendaService::userPrintToFile(std::string file) {
    return userWriteToFile(listAllUsers(), file);
}

bool AgendaService::MeetingCreateByFile(std::string username, std::string file) {
    std::list<Meeting> Register = meetingReadFromFile(file);
    if (Register.size() == 0) return false;
    std::list<Meeting>::iterator it;
    std::cout << std::endl << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl;
    for (it = Register.begin(); it != Register.end(); ++it) {
        if (it->getSponsor() == username && createMeeting(it->getSponsor(), it->getTitle(), it->getParticipator(),
            Date::dateToString(it->getStartDate()), Date::dateToString(it->getEndDate()))) {
            std::cout << "- [Meeting] " << std::setw(20) << std::left << it->getTitle()
                << "  Created Succeed !!!                         -" << std::endl;
        } else {
            std::cout << "- [Meeting] " << std::setw(20) << std::left << it->getTitle()
                << "  Created Fail !!!                            -" << std::endl;
        }
    }
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    return true;
}

bool AgendaService::MeetingPrintToFile(const std::string & userName, std::string file) {
    return meetingWriteToFile(listAllMeetings(userName), file);
}

bool AgendaService::userUpdatePassword(std::string userName, std::string password, std::string newpassword) {
    return storage_->updateUser([&userName, &password](const User & one) -> bool {
        return one.getName() == userName && one.getPassword() == password;
    }, [&newpassword](User & one) -> void {
        one.setPassword(newpassword);
    });
}

bool AgendaService::userUpdateEmail(std::string userName, std::string password, std::string newEmail) {
    return storage_->updateUser([&userName, &password](const User & one) -> bool {
        return one.getName() == userName && one.getPassword() == password;
    }, [&newEmail](User & one) -> void {
        one.setEmail(newEmail);
    });
}

bool AgendaService::userUpdatePhone(std::string userName, std::string password, std::string newPhone) {
    return storage_->updateUser([&userName, &password](const User & one) -> bool {
        return one.getName() == userName && one.getPassword() == password;
    }, [&newPhone](User & one) -> void {
        one.setPhone(newPhone);
    });
}

bool AgendaService::meetingUpdateStartDate(std::string userName, std::string title, std::string newStartDate) {
    if (!Check_Date(newStartDate) || !Date::isValid(Date::stringToDate(newStartDate))) return false;
    return storage_->updateMeeting([&userName, &title, &newStartDate](const Meeting & one) -> bool {
        return one.getSponsor() == userName && one.getTitle() == title &&
                Date::stringToDate(newStartDate) < one.getEndDate();
    }, [&newStartDate](Meeting & one) -> void {
        one.setStartDate(Date::stringToDate(newStartDate));
    });
}

bool AgendaService::meetingUpdateEndDate(std::string userName, std::string title, std::string newEndDate) {
    if (!Check_Date(newEndDate) || !Date::isValid(Date::stringToDate(newEndDate))) return false;
    return storage_->updateMeeting([&userName, &title, &newEndDate](const Meeting & one) -> bool {
        return one.getSponsor() == userName && one.getTitle() == title &&
                Date::stringToDate(newEndDate) > one.getStartDate();
    }, [&newEndDate](Meeting & one) -> void {
        one.setEndDate(Date::stringToDate(newEndDate));
    });
}

bool AgendaService::meetingUpdateTitle(std::string userName, std::string title, std::string newTitle) {
    if (title == newTitle) return true;
    if (storage_->queryMeeting([&newTitle](const Meeting & one) -> bool {
        return one.getTitle() == newTitle;
    }).size() != 0) return false;
    return storage_->updateMeeting([&userName, &title](const Meeting & one) -> bool {
        return one.getSponsor() == userName && one.getTitle() == title;
    }, [&newTitle](Meeting & one) -> void {
        one.setTitle(newTitle);
    });
}

bool AgendaService::meetingUpdateParticipator(std::string userName, std::string title, std::string newParticipator) {
    if (storage_->queryUser([&newParticipator](const User & one) -> bool {
        return one.getName() == newParticipator;
    }).size() == 0) return false;
    return storage_->updateMeeting([&userName, &title](const Meeting & one) -> bool {
        return one.getSponsor() == userName && one.getTitle() == title;
    }, [&newParticipator](Meeting & one) -> void {
        one.setParticipator(newParticipator);
    });
}

///////////  /* new */   ////////////////////////////////////

bool Check_Date(const std::string & one) {
    if (!(one[0] >= '0' && one[0] <= '9')) return false;
    if (!(one[one.size() - 1] >= '0' && one[one.size() - 1] <= '9')) return false;
    std::size_t i;
    int check_1 = 0, check_2 = 0, check_3 = 0;
    for (i = 1; i < one.size() - 1; ++i) {
        if (one[i] == '-') {
            ++check_1;
            if (!(one[i - 1] >= '0' && one[i - 1] <= '9') || !(one[i + 1] >= '0' && one[i + 1] <= '9')) return false;
        }
        else if (one[i] == '/') {
            ++check_2;
            if (!(one[i - 1] >= '0' && one[i - 1] <= '9') || !(one[i + 1] >= '0' && one[i + 1] <= '9')) return false;
        }
        else if (one[i] == ':') {
            ++check_3;
            if (!(one[i - 1] >= '0' && one[i - 1] <= '9') || !(one[i + 1] >= '0' && one[i + 1] <= '9')) return false;
        }
        else if (!(one[i] >= '0' && one[i] <= '9')) return false;
    }
    return (check_1 == 2) && (check_2 == 1) && (check_3 == 1);
}

AgendaService::AgendaService() {storage_ = Storage::getInstance();}

AgendaService::~AgendaService() {
    if (storage_) delete storage_;
    storage_ = NULL;
}

bool AgendaService::userLogIn(std::string userName, std::string password) {
    return (storage_->queryUser([&userName, &password](const User & one) -> bool {
            return one.getName() == userName && one.getPassword() == password;
    }).size() > 0);
}

bool AgendaService::userRegister(std::string userName, std::string password,
                    std::string email, std::string phone) {
    if (storage_->queryUser([&userName](const User & one) -> bool {
            return one.getName() == userName;
        }).size() == 0) {
        storage_->createUser(User(userName, password, email, phone));
        return true;
    }
    return false;
}

bool AgendaService::deleteUser(std::string userName, std::string password) {
    if (storage_->deleteUser([&userName, &password](const User & one) -> bool {
        return one.getName() == userName && one.getPassword() == password;
    })) {
        storage_->deleteMeeting([&userName](const Meeting & one) -> bool {
            return one.getSponsor() == userName || one.getParticipator() == userName;
        });
        return true;
    }
    return false;
}

std::list<User> AgendaService::listAllUsers(void) {
    return storage_->queryUser([](const User & one) -> bool { return true; });
}

bool AgendaService::createMeeting(std::string userName, std::string title,
                     std::string participator,
                     std::string startDate, std::string endDate) {
    if (!(Check_Date(startDate) && Check_Date(endDate)) || (startDate >= endDate)) return false;//here
    if (!(Date::isValid(Date::stringToDate(startDate))) || !(Date::isValid(Date::stringToDate(endDate)))) return false;
    std::list<User> all =  storage_->queryUser([&userName, &participator](const User & one) -> bool {
        return one.getName() == userName || one.getName() == participator;
    });
    if (all.size() < 2) return false;
    std::list<Meeting> one = storage_->queryMeeting([&title](const Meeting & one) -> bool {
        return one.getTitle() == title;
    });
    if (one.size() >= 1) return false;
    Date sDate = Date::stringToDate(startDate), eDate = Date::stringToDate(endDate);
    std::list<Meeting> two = storage_->queryMeeting([&userName, &sDate, &eDate](const Meeting & one) -> bool {
        if (!(one.getSponsor() == userName || one.getParticipator() == userName)) return false;
        if (one.getStartDate() <= sDate && one.getEndDate() >= eDate) return true;
        if (!(one.getStartDate() >= sDate && one.getStartDate() <= eDate) &&
            !(one.getEndDate() >= sDate && one.getEndDate() <= eDate)) return false;
        if (one.getEndDate() == sDate || one.getStartDate() == eDate) return false;
        return true;
    });
    if (two.size() >= 1) return false;
    std::list<Meeting> three = storage_->queryMeeting([&participator, &sDate, &eDate](const Meeting & one) -> bool {
        if (!(one.getSponsor() == participator || one.getParticipator() == participator)) return false;
        if (one.getStartDate() <= sDate && one.getEndDate() >= eDate) return true;
        if (!(one.getStartDate() >= sDate && one.getStartDate() <= eDate) &&
            !(one.getEndDate() >= sDate && one.getEndDate() <= eDate)) return false;
        if (one.getEndDate() == sDate || one.getStartDate() == eDate) return false;
        return true;
    });
    if (three.size() >= 1) return false;
    storage_->createMeeting(Meeting(userName, participator, Date::stringToDate(startDate), Date::stringToDate(endDate), title));
    return true;
}

std::list<Meeting> AgendaService::meetingQuery(std::string userName, std::string title) {
    return storage_->queryMeeting([&userName, &title](const Meeting & one) -> bool {
        if (one.getSponsor() != userName && one.getParticipator() != userName) return false;
        return one.getTitle() == title;
    });
}

std::list<Meeting> AgendaService::meetingQuery(std::string userName, std::string startDate,
                                    std::string endDate) {
    if (!(Check_Date(startDate) && Check_Date(endDate)) || (startDate > endDate)) {
        std::list<Meeting> one; return one;
    }
    if (!(Date::isValid(Date::stringToDate(startDate))) || !(Date::isValid(Date::stringToDate(endDate)))) {
        std::list<Meeting> one; return one;
    }
    Date sDate = Date::stringToDate(startDate), eDate = Date::stringToDate(endDate);
    return storage_->queryMeeting([&userName, &sDate, &eDate](const Meeting & one) -> bool {
        if (!(one.getSponsor() == userName || one.getParticipator() == userName)) return false;
        if (one.getStartDate() <= sDate && one.getEndDate() >= eDate) return true;
        if (!(one.getStartDate() >= sDate && one.getStartDate() <= eDate) &&
            !(one.getEndDate() >= sDate && one.getEndDate() <= eDate)) return false;
        return true;
    });
}

std::list<Meeting> AgendaService::listAllMeetings(std::string userName) {
    return storage_->queryMeeting([&userName](const Meeting & one) -> bool {
        return one.getSponsor() == userName || one.getParticipator() == userName;
    });
}

std::list<Meeting> AgendaService::listAllSponsorMeetings(std::string userName) {
    return storage_->queryMeeting([&userName](const Meeting & one) -> bool {
        return one.getSponsor() == userName;
    });
}

std::list<Meeting> AgendaService::listAllParticipateMeetings(std::string userName) {
    return storage_->queryMeeting([&userName](const Meeting & one) -> bool {
        return one.getParticipator() == userName;
    });
}

bool AgendaService::deleteMeeting(std::string userName, std::string title) {
    return storage_->deleteMeeting([&userName, &title](const Meeting & one) -> bool {
        return one.getSponsor() == userName && one.getTitle() == title;
    });
}

bool AgendaService::deleteAllMeetings(std::string userName) {
    return storage_->deleteMeeting([&userName](const Meeting & one) -> bool {
        return one.getSponsor() == userName;
    });
}

void AgendaService::startAgenda(void) {
    storage_ = Storage::getInstance();
}

void AgendaService::quitAgenda(void) {
    if (storage_) delete storage_;
    storage_ = NULL;
}

