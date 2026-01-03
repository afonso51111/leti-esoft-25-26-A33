#include "../../../headers/domain/model/RecoveryRoom.h"
#include "../../../headers/domain/model/Appointment.h"

RecoveryRoom::RecoveryRoom() {
}

void RecoveryRoom::addToRecovery(Appointment* appointment) {
    recoveryList.push_back(appointment);
}

std::list<Appointment*> RecoveryRoom::getRecoveryList() const {
    return recoveryList;
}