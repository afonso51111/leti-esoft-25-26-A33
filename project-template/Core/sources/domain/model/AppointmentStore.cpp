#include "../../../headers/domain/model/AppointmentStore.h"

AppointmentStore::AppointmentStore() {}

AppointmentStore::~AppointmentStore() {
    for (auto app : listAppointments) {
        delete app;
    }
    listAppointments.clear();
}

void AppointmentStore::saveAppointment(Appointment* appointment) {
    listAppointments.push_back(appointment);
}

std::vector<Appointment*> AppointmentStore::getAll() const {
    return listAppointments;
}