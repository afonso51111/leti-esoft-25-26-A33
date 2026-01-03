#ifndef WAITINGROOM_H
#define WAITINGROOM_H

#include <list>
#include "Appointment.h"

class WaitingRoom {
private:
    std::list<Appointment*> waitingList;

public:
    WaitingRoom() = default;

    void addClient(Appointment* appointment) {
        waitingList.push_back(appointment);
    }

    void removeClient(Appointment* appointment) {
        waitingList.remove(appointment);
    }

    std::list<Appointment*> getWaitingList() const {
        return waitingList;
    }

    bool hasUser(std::string snsNumber) const {
        for (auto app : waitingList) {
            if (app->getUser()->getSNSNumber() == snsNumber) {
                return true;
            }
        }
        return false;
    }
};

#endif