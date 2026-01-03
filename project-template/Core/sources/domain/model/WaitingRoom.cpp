#include "../../../headers/domain/model/WaitingRoom.h"
#include "../../../headers/domain/model/Appointment.h"
#include "../../../headers/domain/model/SNSUser.h"

WaitingRoom::WaitingRoom() {
}

void WaitingRoom::addClient(Appointment* appointment) {
    waitingList.push_back(appointment);
}

void WaitingRoom::removeClient(Appointment* appointment) {
    waitingList.remove(appointment);
}

std::list<Appointment*> WaitingRoom::getWaitingList() const {
    return waitingList;
}

bool WaitingRoom::hasUser(std::string snsNumber) const {
    for (auto app : waitingList) {
        if (app->getUser()->getSNSNumber() == snsNumber) {
            return true;
        }
    }
    return false;
}