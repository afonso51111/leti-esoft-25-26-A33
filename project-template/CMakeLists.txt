cmake_minimum_required(VERSION 3.20)
project(project-template)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        Core
        Core/headers
        RestApi/headers
        RestApi/thirdparty
)

add_subdirectory(Core)
add_subdirectory(CoreTests)
add_subdirectory(ConsoleApp)

add_executable(project-template
        main.cpp

        Core/sources/domain/model/Company.cpp

        Core/sources/domain/model/EmployeeStore.cpp
        Core/sources/domain/model/VaccineTypeStore.cpp
        Core/sources/domain/model/VaccineStore.cpp
        Core/sources/domain/model/VaccinationCenterStore.cpp
        Core/sources/domain/model/SNSUserStore.cpp
        Core/sources/domain/model/AppointmentStore.cpp

        Core/sources/domain/model/Employee.cpp
        Core/sources/domain/model/Nurse.cpp
        Core/sources/domain/model/Receptionist.cpp
        Core/sources/domain/model/VaccineType.cpp
        Core/sources/domain/model/Vaccine.cpp
        Core/sources/domain/model/SNSUser.cpp
        Core/sources/domain/model/Appointment.cpp

        Core/sources/domain/model/VaccinationCenter.cpp
        Core/sources/domain/model/HealthcareCenter.cpp
        Core/sources/domain/model/CommunityMassVaccinationCenter.cpp
        Core/sources/domain/model/WaitingRoom.cpp
        Core/sources/domain/model/RecoveryRoom.cpp

        Core/sources/controllers/restapi/VaccineController.cpp
        Core/sources/controllers/restapi/VaccineTypeController.cpp
        Core/sources/controllers/restapi/SNSUserController.cpp
        Core/sources/controllers/restapi/AppointmentController.cpp

        RestApi/sources/Server.cpp
        RestApi/sources/VaccineRouter.cpp
        RestApi/sources/VaccineTypeRouter.cpp
        RestApi/sources/SNSUserRouter.cpp
        RestApi/sources/AppointmentRouter.cpp

)

target_link_libraries(project-template Core ws2_32)