#include "AgendaUI.h"
#include "Date.h"
#include "User.h"
#include "Meeting.h"
#include "AgendaService.h"
#include <list>
#include <string>
#include <iostream>
#include <iomanip>

const std::string NONE = "";

//////  /* new */  /////////////////////

void AgendaUI::userRegisterByFile(void) {
    std::string file;
    std::cout << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl
              << "------------------------- [ Register Users From File ]-------------------------" << std::endl << std::endl
              << "- [Write The Input File] ~ [File Path And Name]                               -" << std::endl
              << "- [Write The Input File] ~ ";
    std::cin >> file;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl << std::endl;
    agendaService_.userRegisterByFile(file);
}

void AgendaUI::userPrintToFile(void) {
    std::string file;
    std::cout << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl
              << "------------------------- [ Write All Users To File ]--------------------------" << std::endl << std::endl
              << "- [Write The Output File] ~ [File Path And Name]                              -" << std::endl
              << "- [Write The Output File] ~ ";
    std::cin >> file;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl << std::endl;
    if (agendaService_.userPrintToFile(file)) {
        std::cout << "--------------------------------- [ Succeed ] ---------------------------------" << std::endl
                  << "- [ Write All Users To File ] ~ Users Write To File Succeed !!!               -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    } else {
        std::cout << "---------------------------------- [ Error ] ----------------------------------" << std::endl
                  << "- [ Write All Users To File ] ~ Users Write To File Fail !!!                  -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    }
}

void AgendaUI::MeetingCreateByFile(void) {
    std::string file;
    std::cout << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl
              << "------------------------- [ Create Meeting From File ]-------------------------" << std::endl << std::endl
              << "- [Write The Input File] ~ [File Path And Name]                               -" << std::endl
              << "- [Write The Input File] ~ ";
    std::cin >> file;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl << std::endl;
    agendaService_.MeetingCreateByFile(userName_, file);
}

void AgendaUI::MeetingPrintToFile(void) {
    std::string file;
    std::cout << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl
              << "--------------------------- [ Write Meeting To File ]--------------------------" << std::endl << std::endl
              << "- [Write The Output File] ~ [File Path And Name]                              -" << std::endl
              << "- [Write The Output File] ~ ";
    std::cin >> file;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl << std::endl;
    if (agendaService_.MeetingPrintToFile(userName_, file)) {
        std::cout << "--------------------------------- [ Succeed ] ---------------------------------" << std::endl
                  << "- [ Write Meeting To File ] ~ Meetings Write To File Succeed !!!              -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    } else {
        std::cout << "---------------------------------- [ Error ] ----------------------------------" << std::endl
                  << "- [ Write Meeting To File ] ~ Meetings Write To File Fail !!!                 -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    }
}

void AgendaUI::userUpdatePassword(void) {
    std::string oldp, newp;
    std::cout << std::endl;
    std::cout << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl
              << "-                                                                             -" << std::endl
              << "------------------------------ [Update Password] ------------------------------" << std::endl
              << "- [Update] ~ [Password]   [new Password]                                      -" << std::endl
              << "- [Update] ~ ";
    std::cin >> oldp >> newp;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    if (agendaService_.userUpdatePassword(userName_, oldp, newp)) {
        userPassword_ = newp;
        std::cout << std::endl;
        std::cout << "--------------------------------- [ Succeed ] ---------------------------------" << std::endl
                  << "- [Update Password] ~ Update Password Succeed !!!                             -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "---------------------------------- [ Error ] ----------------------------------" << std::endl
                  << "- [Update Password] ~ Update Password Fail.                                   -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    }
}

void AgendaUI::userUpdateEmail(void) {
    std::string password, email;
    std::cout << std::endl;
    std::cout << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl
              << "-                                                                             -" << std::endl
              << "-------------------------------- [Update Email] -------------------------------" << std::endl
              << "- [Update] ~ [Password]   [Email]                                             -" << std::endl
              << "- [Update] ~ ";
    std::cin >> password >> email;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    if (agendaService_.userUpdateEmail(userName_, password, email)) {
        std::cout << std::endl;
        std::cout << "--------------------------------- [ Succeed ] ---------------------------------" << std::endl
                  << "- [Update Email] ~ Update Email Succeed !!!                                   -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "---------------------------------- [ Error ] ----------------------------------" << std::endl
                  << "- [Update Email] ~ Update Email Fail.                                         -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    }
}

void AgendaUI::userUpdatePhone(void) {
    std::string password, phone;
    std::cout << std::endl;
    std::cout << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl
              << "-                                                                             -" << std::endl
              << "-------------------------------- [Update Phone] -------------------------------" << std::endl
              << "- [Update] ~ [Password]   [Phone]                                             -" << std::endl
              << "- [Update] ~ ";
    std::cin >> password >> phone;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    if (agendaService_.userUpdatePhone(userName_, password, phone)) {
        std::cout << std::endl;
        std::cout << "--------------------------------- [ Succeed ] ---------------------------------" << std::endl
                  << "- [Update Phone] ~ Update Phone Succeed !!!                                   -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "---------------------------------- [ Error ] ----------------------------------" << std::endl
                  << "- [Update Phone] ~ Update Phone Fail.                                         -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    }
}

void AgendaUI::meetingUpdateStartDate(void) {
    std::string title, newt;
    std::cout << std::endl << "---------------- [ All Of The Meetings You Created Are Below ] ----------------" << std::endl;
    listAllSponsorMeetings();
    std::cout << std::endl;
    std::cout << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl
              << "- Please input your time like this form : yyyy-mm-dd/hh:mm                    -" << std::endl
              << "------------------------- [Update Meeting Start Time] -------------------------" << std::endl
              << "- [Update] ~ [Title]   [New Start Time]                                       -" << std::endl
              << "- [Update] ~ ";
    std::cin >> title >> newt;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    if (agendaService_.meetingUpdateStartDate(userName_, title, newt)) {
        std::cout << std::endl;
        std::cout << "--------------------------------- [ Succeed ] ---------------------------------" << std::endl
                  << "- [Update Time] ~ Update Start Time Succeed !!!                               -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "---------------------------------- [ Error ] ----------------------------------" << std::endl
                  << "- [Update Time] ~ Update Start Time Fail.                                     -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    }
}

void AgendaUI::meetingUpdateEndDate(void) {
    std::string title, newt;
    std::cout << std::endl << "---------------- [ All Of The Meetings You Created Are Below ] ----------------" << std::endl;
    listAllSponsorMeetings();
    std::cout << std::endl;
    std::cout << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl
              << "- Please input your time like this form : yyyy-mm-dd/hh:mm                    -" << std::endl
              << "-------------------------- [Update Meeting End Time] --------------------------" << std::endl
              << "- [Update] ~ [Title]   [New End Time]                                         -" << std::endl
              << "- [Update] ~ ";
    std::cin >> title >> newt;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    if (agendaService_.meetingUpdateEndDate(userName_, title, newt)) {
        std::cout << std::endl;
        std::cout << "--------------------------------- [ Succeed ] ---------------------------------" << std::endl
                  << "- [Update Time] ~ Update End Time Succeed !!!                                 -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "---------------------------------- [ Error ] ----------------------------------" << std::endl
                  << "- [Update Time] ~ Update End Time Fail.                                       -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    }
}

void AgendaUI::meetingUpdateTitle(void) {
    std::string title, newt;
    std::cout << std::endl << "---------------- [ All Of The Meetings You Created Are Below ] ----------------" << std::endl;
    listAllSponsorMeetings();
    std::cout << std::endl;
    std::cout << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl
              << "-                                                                             -" << std::endl
              << "---------------------------- [Update Meeting Title] ---------------------------" << std::endl
              << "- [Update] ~ [Title]   [New Title]                                            -" << std::endl
              << "- [Update] ~ ";
    std::cin >> title >> newt;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    if (agendaService_.meetingUpdateTitle(userName_, title, newt)) {
        std::cout << std::endl;
        std::cout << "--------------------------------- [ Succeed ] ---------------------------------" << std::endl
                  << "- [Update Title] ~ Update Title Succeed !!!                                   -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "---------------------------------- [ Error ] ----------------------------------" << std::endl
                  << "- [Update Title] ~ Update Title Fail.                                         -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    }
}

void AgendaUI::meetingUpdateParticipator(void) {
    std::string title, newn;
    std::cout << std::endl << "---------------- [ All Of The Meetings You Created Are Below ] ----------------" << std::endl;
    listAllSponsorMeetings();
    std::cout << std::endl;
    std::cout << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl
              << "-                                                                             -" << std::endl
              << "------------------------ [Update Meeting Participator] ------------------------" << std::endl
              << "- [Update] ~ [Title]   [New Participator Name]                                -" << std::endl
              << "- [Update] ~ ";
    std::cin >> title >> newn;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    if (agendaService_.meetingUpdateParticipator(userName_, title, newn)) {
        std::cout << std::endl;
        std::cout << "--------------------------------- [ Succeed ] ---------------------------------" << std::endl
                  << "- [Update Participator] ~ Update Participator Succeed !!!                     -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "---------------------------------- [ Error ] ----------------------------------" << std::endl
                  << "- [Update Participator] ~ Update Participator Fail.                           -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    }
}

//////  /* new */  /////////////////////

void Welcome_picture();
void Goodbye_picture();

AgendaUI::AgendaUI() {}

void AgendaUI::OperationLoop(void) {
    startAgenda();
    std::string out;
    while (executeOperation(getOperation())) {
            std::cout << std::endl;
            std::cout << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl
                      << "- [Please input any keys to continue] ~ ";
            std::getchar();
            while (std::getchar() != '\n') continue;
            std::cout << "-------------------------------------------------------------------------------" << std::endl;
    }
}

void get_small(std::string & one) {
    for (int i = 0; i < one.size(); ++i) {
        one[i] = std::tolower(one[i]);
    }
}

void AgendaUI::startAgenda(void) {
    agendaService_.startAgenda();
    Welcome_picture(); // not completed;
    std::cout << std::endl;
    std::cout << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl
              << "- [Please input any keys to continue] ~ ";
    while (std::getchar() != '\n') continue;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
}

std::string AgendaUI::getOperation() {
    std::string result;
    if (userName_ == NONE) {
        std::cout << std::endl << std::endl;
        std::cout << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl
                  << "-                                                                             -" << std::endl
                  << "----------------------------------- [Action] ----------------------------------" << std::endl
                  << "- ['l']  ~~ Log in Agenda by user name and password.                          -" << std::endl
                  << "- ['r']  ~~ Register an Agenda account.                                       -" << std::endl
                  << "- ['q']  ~~ Quit Agenda.                                                      -" << std::endl
                  << "- ['rf'] ~~ Register many User from a file.    (new2)                         -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
        std::cout << "- [Agenda] : ~$ ";
    } else {
        std::cout << std::endl << std::endl;
        std::cout << "----------------------------------- [Action] ----------------------------------" << std::endl
                  << "- ['o']   ~~ Log out Agenda.                                                  -" << std::endl
                  << "- ['up']  ~~ Update your password.             (new1)                         -" << std::endl
                  << "- ['ue']  ~~ Update your email.                (new1)                         -" << std::endl
                  << "- ['uph'] ~~ Update your phone.                (new1)                         -" << std::endl
                  << "- ['dc']  ~~ Delete Agenda account.                                           -" << std::endl
                  << "- ['lu']  ~~ List all Agenda users.                                           -" << std::endl
                  << "- ['cm']  ~~ Create a meeting.                                                -" << std::endl
                  << "- ['cmf'] ~~ Create all the meetings from a file.      (new2)                 -" << std::endl
                  << "- ['la']  ~~ List all meetings.                                               -" << std::endl
                  << "- ['las'] ~~ List all sponsor meetings.                                       -" << std::endl
                  << "- ['lap'] ~~ List all participate meetings.                                   -" << std::endl
                  << "- ['pmf'] ~~ Print all of your meetings to a file.     (new2)                 -" << std::endl
                  << "- ['puf'] ~~ Print all of users to a file      (new2)                         -" << std::endl
                  << "- ['ump'] ~~ Update meeting participator.      (new1)                         -" << std::endl
                  << "- ['ums'] ~~ Update meeting start time.        (new1)                         -" << std::endl
                  << "- ['ume'] ~~ Update meeting end time.          (new1)                         -" << std::endl
                  << "- ['umt'] ~~ Update meeting title              (new1)                         -" << std::endl
                  << "- ['qm']  ~~ Query meeting by title.                                          -" << std::endl
                  << "- ['qt']  ~~ Query meeting by time interval.                                  -" << std::endl
                  << "- ['dm']  ~~ Delete meeting by title.                                         -" << std::endl
                  << "- ['da']  ~~ Delete all meetings.                                             -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
        std::cout << "- [Agenda] & " << userName_ << " : # ";
    }
    std::cin >> result;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    get_small(result);
    return result;
}

bool AgendaUI::executeOperation(std::string op) {
    if (userName_ == NONE) {
        if (op == "l") userLogIn();
        else if (op == "r") userRegister();
        else if (op == "q") { quitAgenda(); return false; }
        else if (op == "rf") userRegisterByFile();
        else { std::cout << std::endl << std::endl;
               std::cout << "--------------------------------- [Action Fail] -------------------------------" << std::endl
                         << "-Sorry ! The Action is not completed! Please try again!                       -" << std::endl
                         << "-------------------------------------------------------------------------------" << std::endl;
             }
    } else {
        if (op == "o") userLogOut();
        else if (op == "up") userUpdatePassword();
        else if (op == "ue") userUpdateEmail();
        else if (op == "uph") userUpdatePhone();
        else if (op == "dc") deleteUser();
        else if (op == "lu") listAllUsers();
        else if (op == "cm") createMeeting();
        else if (op == "cmf") MeetingCreateByFile();
        else if (op == "la") listAllMeetings();
        else if (op == "las") listAllSponsorMeetings();
        else if (op == "lap") listAllParticipateMeetings();
        else if (op == "pmf") MeetingPrintToFile();
        else if (op == "puf") userPrintToFile();
        else if (op == "ump") meetingUpdateParticipator();
        else if (op == "ums") meetingUpdateStartDate();
        else if (op == "ume") meetingUpdateEndDate();
        else if (op == "umt") meetingUpdateTitle();
        else if (op == "qm") queryMeetingByTitle();
        else if (op == "qt") queryMeetingByTimeInterval();
        else if (op == "dm") deleteMeetingByTitle();
        else if (op == "da") deleteAllMeetings();
        else { std::cout << std::endl << std::endl;
               std::cout << "--------------------------------- [Action Fail] -------------------------------" << std::endl
                         << "-Sorry ! The Action is not completed! Please try again!                       -" << std::endl
                         << "-------------------------------------------------------------------------------" << std::endl;
             }
    }
    return true;
}

void AgendaUI::userLogIn(void) {
    std::cout << std::endl << std::endl;
    std::cout << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl
              << "-                                                                             -" << std::endl
              << "----------------------------------- [lOG IN] ----------------------------------" << std::endl
              << "- [Log in] ~ [User Name]   [Password]                                         -" << std::endl;
    std::cout << "- [Log in] ~ ";
    std::cin >> userName_ >> userPassword_;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    if (agendaService_.userLogIn(userName_, userPassword_)) {
        std::cout << std::endl << "--------------------------------- [ Succeed ] ---------------------------------" << std::endl;
        std::cout << "- [Log in] ~ Succeed!!!                                                       -" << std::endl;
    } else {
        userName_ = userPassword_ = NONE;
	    std::cout << std::endl << "---------------------------------- [ Error ] ----------------------------------" << std::endl;
        std::cout << "- [Error]  ~ Log in fail!!!                                                   -" << std::endl;
    }
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
}

void AgendaUI::userRegister(void) {
    std::cout << std::endl << std::endl;
    std::cout << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl
              << "-                                                                             -" << std::endl
              << "---------------------------------- [Register] ---------------------------------" << std::endl
              << "- [Register] ~ [User Name]   [Password]   [Email]   [phone]                   -" << std::endl
              << "- [Register] ~ ";
    std::string Email, Phone;
    std::cin >> userName_ >> userPassword_ >> Email >> Phone;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    if (agendaService_.userRegister(userName_, userPassword_, Email, Phone)) {
        std::cout << std::endl << "--------------------------------- [ Succeed ] ---------------------------------" << std::endl;
        std::cout << "-                      [Register] ~ Succeed!!!                                -" << std::endl;
        std::cout << "-------------------------------------------------------------------------------" << std::endl;
    } else {
        std::cout << std::endl << "---------------------------------- [ Error ] ----------------------------------" << std::endl;
        std::cout << "- [Register] ~ Register Fail.   Maybe someone had registered by the name!     -" << std::endl;
        std::cout << "-------------------------------------------------------------------------------" << std::endl;
        userName_ = userPassword_ = NONE;
    }
}

void AgendaUI::quitAgenda(void) {
    agendaService_.quitAgenda();
    Goodbye_picture();
}

void AgendaUI::userLogOut(void) {
    userName_ = userPassword_ = NONE;
    std::cout << std::endl << std::endl;
    std::cout << "-------------------------------- [User Log Out] -------------------------------" << std::endl
              << "- User Log Out Succeed!!! Thanks for your use.                                -" << std::endl
              << "-------------------------------------------------------------------------------" << std::endl;
}

void AgendaUI::deleteUser(void) {
    std::string Password;
    std::cout << std::endl << std::endl;
    std::cout << "--------------------------- [ Delete Agenda Account ] -------------------------" << std::endl
              << "-  [Delete] ~ [Password]                                                      -" << std::endl
              << "-  [Delete] ~ ";
    std::cin >> Password;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl << std::endl;
    if (agendaService_.deleteUser(userName_, Password)) {
        std::cout << "--------------------------- [ Delete Agenda Account ] -------------------------" << std::endl
                  << "- Delete Agenda Account Succeed!!! Thanks for your use.                       -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
        userName_ = userPassword_ = NONE;
    } else {
        std::cout << "--------------------------- [ Delete Agenda Account ] -------------------------" << std::endl
                  << "- Delete Agenda Account Fail!!! Please try again.                             -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    }
}

void AgendaUI::listAllUsers(void) {
    std::list<User> users = agendaService_.listAllUsers();
    std::cout << std::endl;
    std::cout << std::endl << "---------------------------------- [ Agenda ] ---------------------------------"
              << std::endl << "-                                                                             -";
    std::cout << std::endl << "------------------------------ [ List All Users ] -----------------------------"
              << std::endl << "-     [Name]                        [Email]                       [Phone]     -"
              << std::endl << "-                                                                             -" << std::endl;
    std::list<User>::iterator it = users.begin();
    int a = it->getName().size(), b = it->getEmail().size(), c = it->getEmail().size();
    for (it = users.begin(); it != users.end(); ++it) {
        std::cout << "-     " << std::setw(30) << std::left << it->getName() << std::setw(30) << it->getEmail();
        std::cout << std::setw(12) << it->getPhone() << "-" << std::endl;
    }
    std::cout << "-                                                                             -" << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
}

void AgendaUI::createMeeting(void) {
    std::cout << std::endl;
    std::cout << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl
              << "-                                                                             -" << std::endl
              << "------------------------------ [ Create Meeting ] -----------------------------" << std::endl
              << "- Please input your time like this form : yyyy-mm-dd/hh:mm                    -" << std::endl
              << "-------------------------------------------------------------------------------" << std::endl
              << "- [Create Meeting] ~ [Title]   [Participator]   [Start Time]   [End Time]     -" << std::endl;
    std::cout << "- [Create Meeting] ~ ";
    std::string T, P, S, E;
    std::cin >> T >> P >> S >> E;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl << std::endl;
    if (agendaService_.createMeeting(userName_, T, P, S, E)) {
        std::cout << "------------------------------ [ Create Meeting ] -----------------------------" << std::endl
                  << "-                          [Meeting] Created Succeed!!!                       -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    } else {
        std::cout << "------------------------------ [ Create Meeting ] -----------------------------" << std::endl
                  << "-                     Created Fail!!!     Please try again.                   -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    }
}

void AgendaUI::listAllMeetings(void) {
    printMeetings(agendaService_.listAllMeetings(userName_));
}

void AgendaUI::listAllSponsorMeetings(void) {
    printMeetings(agendaService_.listAllSponsorMeetings(userName_));
}

void AgendaUI::listAllParticipateMeetings(void) {
   printMeetings(agendaService_.listAllParticipateMeetings(userName_));
}

void AgendaUI::queryMeetingByTitle(void) {
    std::string Title;
    std::cout << std::endl << std::endl;
    std::cout << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl
              << "-                                                                             -" << std::endl
              << "------------------------------ [ Query Meeting ] ------------------------------" << std::endl
              << "- [Query Meeting By Title] ~ [Title]                                          -" << std::endl
              << "- [Query Meeting By Title] ~ ";
    std::cin >> Title;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    printMeetings(agendaService_.meetingQuery(userName_, Title));
}

void AgendaUI::queryMeetingByTimeInterval(void) {
    std::string sDate, eDate;
    std::cout << std::endl << std::endl;
    std::cout << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl
              << "-                                                                             -" << std::endl
              << "------------------------------ [ Query Meeting ] ------------------------------" << std::endl
              << "- Please input your time like this form : yyyy-mm-dd/hh:mm                    -" << std::endl
              << "-------------------------------------------------------------------------------" << std::endl
              << "- [Query Meeting By Time] ~ [Start Time]  [End Time]                          -" << std::endl
              << "- [Query Meeting By Time] ~ ";
    std::cin >> sDate >> eDate;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    printMeetings(agendaService_.meetingQuery(userName_, sDate, eDate));
}

void AgendaUI::deleteMeetingByTitle(void) {
    std::string title;
    std::cout << std::endl << std::endl;
    std::cout << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl
              << "-                                                                             -" << std::endl
              << "------------------------- [ Delete Meeting By Title ] -------------------------" << std::endl
              << "- [Delete Meeting] ~ [Title]                                                  -" << std::endl
              << "- [Delete Meeting] ~ ";
    std::cin >> title;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    std::cout << std::endl << std::endl;
    if (agendaService_.deleteMeeting(userName_, title)) {
        std::cout << "------------------------- [ Delete Meeting By Title ] -------------------------" << std::endl
                  << "-                  [Delete Meeting] Meeting Delete Succeed!!!                 -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    } else {
        std::cout << "------------------------- [ Delete Meeting By Title ] -------------------------" << std::endl
                  << "-                                                                             -" << std::endl
                  << "-                    [Delete Meeting] Meeting Delete Fail!!!                  -" << std::endl
                  << "-               [Delete Meeting] You haven't created such a meeting.          -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    }
}

void AgendaUI::deleteAllMeetings(void) {
    std::cout << std::endl << std::endl;
    if (agendaService_.deleteAllMeetings(userName_)) {
        std::cout << "------------------------------ [ Delete Meeting ] -----------------------------" << std::endl
                  << "-                       All of your meetings deleted Succeed!!!               -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    } else {
        std::cout << "------------------------------ [ Delete Meeting ] -----------------------------" << std::endl
                  << "-                     All of your meetings deleted Fail!!!                    -" << std::endl
                  << "-                      You haven't created any meetings.                      -" << std::endl
                  << "-------------------------------------------------------------------------------" << std::endl;
    }
}

void AgendaUI::printMeetings(std::list<Meeting> meetings) {
    std::cout << std::endl << std::endl;
    std::cout << "---------------------------------- [ Agenda ] ---------------------------------" << std::endl
              << "-                                                                             -" << std::endl
              << "------------------------------ [ List  Meetings ] -----------------------------" << std::endl
              << "-[Ttile]      [Sponsor]     [Participator]  [Start Time]      [End Time]      -" << std::endl
              << "-                                                                             -" << std::endl;
    std::list<Meeting>::iterator it;
    if (meetings.size() == 0) {
              std::cout << "-[None]       [None]        [None]          [None]            [None]          -" << std::endl;
    }
    for (it = meetings.begin(); it != meetings.end(); ++it) {
        std::cout << "-" << std::setw(13) << std::left << it->getTitle()
                  << std::setw(14) << it->getSponsor() << std::setw(16) << it->getParticipator()
                  << std::setw(18) << Date::dateToString(it->getStartDate())
                  << std::setw(16) << Date::dateToString(it->getEndDate()) << "-" << std::endl;
    }
    std::cout << "-                                                                             -" << std::endl
              << "-------------------------------------------------------------------------------" << std::endl;
}

void Welcome_picture() {
    std::cout << std::endl << std::endl;
    std::cout << "----------------------------- [Welcome To Agenda] -----------------------------" << std::endl
              << "-                                           |                                 -" << std::endl
              << "-:::::::-'--'--::::::: ~~| ,              \\ _ /                               -" << std::endl
              << "-:::::::::::::::::::::: ,|^-._/|     -==   ( ) ==-                            -" << std::endl
              << "-::::::::::::^^:::::::.' |  / ||\\         /   \\                               -" << std::endl
              << "-::::::::::^^:::::::.'   | /  ||`\\          |                                 -" << std::endl
              << "-::::::::::::::::::/ `-. |/._ ||  \\                                           -" << std::endl
              << "-:::::::::::::::: |      ||   ||   \\                                          -" << std::endl
              << "-~^-^^^=^_^^^ =^ \\^^^^^^^,^^^^,^^^^^/^^'' ^=^'^                               -" << std::endl
              << "-~^^-^''^^-=^'^ ^ -________________,^'^=^'^_^'=^'^                            -" << std::endl
              << "-------------------------------------------------------------------------------" << std::endl;
}

void Goodbye_picture() {
    std::cout << std::endl << std::endl;
    std::cout << "------------------------------ [Goodbye Agenda] -------------------------------" << std::endl
              << "-                                           |                                 -" << std::endl
              << "-:::::::-'--'--::::::: ~~| ,              \\ _ /                               -" << std::endl
              << "-:::::::::::::::::::::: ,|^-._/|     -==   ( ) ==-                            -" << std::endl
              << "-::::::::::::^^:::::::.' |  / ||\\         /   \\                               -" << std::endl
              << "-::::::::::^^:::::::.'   | /  ||`\\          |                                 -" << std::endl
              << "-::::::::::::::::::/ `-. |/._ ||  \\                                           -" << std::endl
              << "-:::::::::::::::: |      ||   ||   \\                                          -" << std::endl
              << "-~^-^^^=^_^^^ =^ \\^^^^^^^,^^^^,^^^^^/^^'' ^=^'^                               -" << std::endl
              << "-~^^-^''^^-=^'^ ^ -________________,^'^=^'^_^'=^'^                            -" << std::endl
              << "-------------------------------------------------------------------------------" << std::endl;
}

