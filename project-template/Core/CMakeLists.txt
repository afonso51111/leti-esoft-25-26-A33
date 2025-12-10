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
)