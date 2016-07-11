#ifndef AGENDASERVICE_H
#define AGENDASERVICE_H

#include "Storage.h"
#include <list>
#include <string>

class AgendaService {
 public:
  AgendaService();
  ~AgendaService();

  /* new */
  bool userRegisterByFile(std::string file);
  bool userPrintToFile(std::string file);
  bool MeetingCreateByFile(std::string username, std::string file);
  bool MeetingPrintToFile(const std::string & userName, std::string file);
  bool userUpdatePassword(std::string userName, std::string password, std::string newpassword);
  bool userUpdateEmail(std::string userName, std::string password, std::string newEmail);
  bool userUpdatePhone(std::string userName, std::string password, std::string newPhone);
  bool meetingUpdateStartDate(std::string userName, std::string title, std::string newStartDate);
  bool meetingUpdateEndDate(std::string userName, std::string title, std::string newEndDate);
  bool meetingUpdateTitle(std::string userName, std::string title, std::string newTitle);
  bool meetingUpdateParticipator(std::string userName, std::string title, std::string newParticipator);
  /* new */

  bool userLogIn(std::string userName, std::string password);
  bool userRegister(std::string userName, std::string password,
                    std::string email, std::string phone);
  bool deleteUser(std::string userName, std::string password);
	// a user can only delete itself
  std::list<User> listAllUsers(void);

  bool createMeeting(std::string userName, std::string title,
                     std::string participator,
                     std::string startDate, std::string endDate);
  std::list<Meeting> meetingQuery(std::string userName, std::string title);
  std::list<Meeting> meetingQuery(std::string userName, std::string startDate,
                                  std::string endDate);
  std::list<Meeting> listAllMeetings(std::string userName);
  std::list<Meeting> listAllSponsorMeetings(std::string userName);
  std::list<Meeting> listAllParticipateMeetings(std::string userName);
  bool deleteMeeting(std::string userName, std::string title);
  bool deleteAllMeetings(std::string userName);

  void startAgenda(void);
  void quitAgenda(void);

 private:
  Storage *storage_;
};

#endif
