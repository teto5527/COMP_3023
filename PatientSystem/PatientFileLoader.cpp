#include "PatientFileLoader.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Patient.h"
#include "Vitals.h"

using namespace std;

tm stringToTm(const string& dateString) {
    tm birthday = { 0 };
    istringstream ss(dateString);
    ss >> get_time(&birthday, "%d-%m-%Y");
    return birthday;
}

vector<Patient*> PatientFileLoader::loadPatientFile(const string& file)
{
    vector<Patient*> patients{};
    ifstream inFile(file);
    string line;

    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            istringstream ss(line);
            string uid, dateString, fullName, diseaseString, vitalsString;
            getline(ss, uid, '|');
            getline(ss, dateString, '|');
            getline(ss, fullName, '|');
            getline(ss, diseaseString, '|');
            getline(ss, vitalsString, '|');
            tm birthday = stringToTm(dateString);

            size_t commaPos = fullName.find(",");
            string lastName = fullName.substr(0, commaPos);
            string firstName = fullName.substr(commaPos + 1);

            Patient *p = new Patient(firstName, lastName, birthday);

            // Split diseaseString by semicolon and add each disease to the patient
            //istringstream diseaseStream(diseaseString);
            //string disease;
            //while (getline(diseaseStream, disease, ';')) {
            //    p->addDiagnosis(disease);
            //}


            patients.push_back(p);

            // need delete p
            delete p;
        }
    }
    else {
		cerr << "Unable to open file: " << file << endl;
	}



    inFile.close();
    return patients;
}