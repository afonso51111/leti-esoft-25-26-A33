#ifndef WAITINGROOM_H
#define WAITINGROOM_H

#include <list>
#include <string>

class Appointment;

class WaitingRoom {
private:
    std::list<Appointment*> waitingList;

public:
    WaitingRoom();

    void addClient(Appointment* appointment);

    void removeClient(Appointment* appointment);

    std::list<Appointment*> getWaitingList() const;

    bool hasUser(std::string snsNumber) const;
};

#endif