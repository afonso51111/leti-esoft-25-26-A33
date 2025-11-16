# Supplementary Specification (FURPS+)

## Functionality

_Specifies functionalities that:  
&nbsp; &nbsp; (i) are common across several US/UC;  
&nbsp; &nbsp; (ii) are not related to US/UC, namely: Audit, Reporting and Security._

- The system must maintain a log of all user actions to track who performed which operations.
- The system must generate reports on vaccinations, vaccination centers, and doses administered.
- The system must enforce role-based access control so that only authorized roles can access sensitive data.


## Usability

_Evaluates the user interface. It has several subcategories,
among them: error prevention; interface aesthetics and design; help and
documentation; consistency and standards._

- The interface must be intuitive and consistent for SNS users, receptionists, nurses, and administrators.
- The system must prevent invalid data entry.
- The system must provide context-sensitive help and guidance in all forms related to scheduling and vaccination.


## Reliability

_Refers to the integrity, compliance and interoperability of the software. The requirements to be considered are: frequency and severity of failure, possibility of recovery, possibility of prediction, accuracy, average time between failures._

- The system must reliably record all vaccination events.
- In case of system failure, no vaccination data should be lost.
- Vaccination certificates and historical records must accurately reflect the user’s vaccination status.


## Performance

_Evaluates the performance requirements of the software, namely: response time, start-up time, recovery time, memory consumption, CPU usage, load capacity and application availability._

- The system must support at least 10,000 simultaneous appointment bookings during mass vaccination campaigns.
- Loading user lists and vaccination center data should take no more than 2 seconds.
- The system must remain available 24/7 during pandemic vaccination campaigns.


## Supportability

_The supportability requirements gathers several characteristics, such as:
testability, adaptability, maintainability, compatibility,
configurability, installability, scalability and more._

- The system must allow easy addition or removal of vaccine types.
- The system must be compatible with multiple devices.
- System configuration updates must be easy to perform and maintain.


## +

### Design Constraints

_Specifies or constraints the system design process. Examples may include: programming languages, software process, mandatory standards/patterns, use of development tools, class library, etc._

- The system must be developed using languages and frameworks consistent with corporate and public health standards.
- The interface must follow DGS usability and accessibility guidelines.

### Implementation Constraints

_Specifies or constraints the code or construction of a system such
such as: mandatory standards/patterns, implementation languages,
database integrity, resource limits, operating system._

- The database must ensure data integrity and consistency.
- The system must be compatible with Windows and Linux servers.

### Interface Constraints

_Specifies or constraints the features inherent to the interaction of the
system being developed with other external systems._

- The system must allow future integration with external health systems.

### Physical Constraints

_Specifies a limitation or physical requirement regarding the hardware used to house the system, as for example: material, shape, size or weight._

- No specific hardware restrictions beyond the infrastructure available in healthcare centers and vaccination facilities.


