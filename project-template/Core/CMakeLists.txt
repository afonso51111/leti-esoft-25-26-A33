project(Core)

add_library(Core
        headers/domain/shared/Result.h
        sources/domain/shared/Result.cpp
        headers/domain/shared/StringUtils.h
        sources/domain/shared/StringUtils.cpp

        headers/domain/model/Company.h

        headers/domain/model/Employee.h
        headers/domain/model/Nurse.h
        headers/domain/model/Receptionist.h
        headers/domain/model/EmployeeStore.h

        headers/domain/model/VaccineType.h
        headers/domain/model/VaccineTypeStore.h


        headers/domain/model/VaccineStore.h
        headers/domain/model/Vaccine.h

        headers/domain/model/VaccinationCenter.h
        headers/domain/model/HealthcareCenter.h
        headers/domain/model/CommunityMassVaccinationCenter.h
        headers/domain/model/VaccinationCenterStore.h

        headers/domain/model/SNSUser.h
        headers/domain/model/SNSUserStore.h

        headers/domain/model/Appointment.h
        headers/domain/model/WaitingRoom.h
        headers/domain/model/RecoveryRoom.h
        headers/domain/model/AppointmentStore.h

        sources/domain/model/VaccineType.cpp
        sources/domain/model/VaccineTypeStore.cpp

        sources/domain/model/VaccineStore.cpp
        sources/domain/model/Vaccine.cpp
        sources/domain/model/Company.cpp

        sources/domain/model/Employee.cpp
        sources/domain/model/Nurse.cpp
        sources/domain/model/Receptionist.cpp
        sources/domain/model/EmployeeStore.cpp

        sources/domain/model/VaccinationCenter.cpp
        sources/domain/model/HealthcareCenter.cpp
        sources/domain/model/CommunityMassVaccinationCenter.cpp
        sources/domain/model/VaccinationCenterStore.cpp

        sources/domain/model/SNSUser.cpp
        sources/domain/model/SNSUserStore.cpp

        sources/domain/model/Appointment.cpp
        sources/domain/model/WaitingRoom.cpp
        sources/domain/model/RecoveryRoom.cpp
        sources/domain/model/AppointmentStore.cpp

)