#ifndef APPOINTMENTSTORE_H
#define APPOINTMENTSTORE_H

#include <vector>
#include "Appointment.h"

class AppointmentStore {
private:
    std::vector<Appointment*> listAppointments;

public:
    AppointmentStore();
    ~AppointmentStore();

    void saveAppointment(Appointment* appointment);
    std::vector<Appointment*> getAll() const;
};

#endif