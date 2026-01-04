#include "../headers/Server.h"
#include <iostream>
#include "../headers/VaccineRouter.h"
#include "../headers/VaccineTypeRouter.h"
#include "../headers/SNSUserRouter.h"
#include "../headers/AppointmentRouter.h"
#include "../headers/VaccinationCenterRouter.h"

void Server::run() {
    std::cout << "Starting PVMS Server..." << std::endl;

    VaccineRouter vaccineRouter;
    vaccineRouter.configure(this->svr);

    VaccineTypeRouter typeRouter;
    typeRouter.configure(this->svr);

    SNSUserRouter userRouter;
    userRouter.configure(this->svr);

    AppointmentRouter appointmentRouter;
    appointmentRouter.configure(this->svr);

    VaccinationCenterRouter centerRouter;
    centerRouter.configure(this->svr);

    std::cout << "Server listening on http://localhost:8080" << std::endl;
    this->svr.listen("0.0.0.0", 8080);
}