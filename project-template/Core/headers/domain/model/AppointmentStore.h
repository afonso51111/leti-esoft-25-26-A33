#ifndef APPOINTMENTSTORE_H
#define APPOINTMENTSTORE_H

#include <vector>
#include "Appointment.h"
#include "SNSUser.h"

class AppointmentStore {
private:
    std::vector<Appointment*> listAppointments;

public:
    AppointmentStore();
    virtual ~AppointmentStore();

    bool createAppointment(SNSUser* user, std::string centerName, std::string vaccineType, std::string date);

    void saveAppointment(Appointment* appointment);

    std::vector<Appointment*> getList() const;
};

#endif // APPOINTMENTSTORE_H