#ifndef RECOVERYROOM_H
#define RECOVERYROOM_H

#include <list>

class Appointment;

class RecoveryRoom {
private:
    std::list<Appointment*> recoveryList;

public:
    RecoveryRoom();

    void addToRecovery(Appointment* appointment);

    std::list<Appointment*> getRecoveryList() const;
};

#endif