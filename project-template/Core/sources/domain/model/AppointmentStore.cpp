#include "../../../headers/domain/model/AppointmentStore.h"

AppointmentStore::AppointmentStore() {}

AppointmentStore::~AppointmentStore() {
    for (auto app : listAppointments) {
        delete app;
    }
    listAppointments.clear();
}

bool AppointmentStore::createAppointment(SNSUser* user, std::string centerName, std::string vaccineType, std::string date) {

    Appointment* newApp = new Appointment(user, centerName, vaccineType, date);
    saveAppointment(newApp);
    return true;
}

void AppointmentStore::saveAppointment(Appointment* appointment) {
    listAppointments.push_back(appointment);
}

std::vector<Appointment*> AppointmentStore::getList() const {
    return listAppointments;
}