// PatientSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <string>

#include "PatientManagementSystem.h"
#include "PatientFileLoader.h"
#include "Patient.h"

using namespace std;

int main()
{
	//auto pms = std::make_unique<PatientManagementSystem>();

	//pms->init();
	//pms->run();
	auto pfl = std::make_unique<PatientFileLoader>();
	auto patients = pfl->loadPatientFile("patients.txt");
	for (Patient* p : patients) {
		cout << *p << endl;
	}
	return 0;
}
