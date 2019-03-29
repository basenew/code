#pragma once
#include "data.h"
#include <iostream>

using namespace std;

class Prescription:public Data
{
public:
	Prescription():Data("prescription"), _user_id(0), _doctor_id(0), _from_time(0){};

	inline const VarStr& no(){return _prescription_no;};
	inline int user_id(){return _user_id;};
	inline int doctor_id(){return _doctor_id;};
	inline int from_time(){return _from_time;};
	inline const VarStr& doctor_name(){return _doctor_name;};
	inline const VarStr& diagnosis(){return _diagnosis;};
	inline const VarStr& auxiliary_diagnosis(){return _auxiliary_diagnosis;};
	inline const VarStr& prescription(){return _prescription;};
	inline const VarStr& allergy_history(){return _allergy_history;};
	
	inline void user_id(int user_id){_user_id = user_id;};
	inline void doctor_id(int doctor_id){_doctor_id = doctor_id;};
	inline void from_time(int from_time){_from_time = from_time;};
	inline void no(const string& no){_prescription_no = no;};
	inline void doctor_name(const string&doctor_name){_doctor_name = doctor_name;};
	inline void diagnosis(const string& diagnosis){_diagnosis = diagnosis;};
	inline void auxiliary_diagnosis(const string& auxiliary_diagnosis){_auxiliary_diagnosis = auxiliary_diagnosis;};
	inline void prescription(const string&){_prescription;};
	inline void allergy_history(const string& allergy_history){_allergy_history = allergy_history;};
private:
	VarStr _prescription_no;
	int _user_id;
	int _doctor_id;
	VarStr _doctor_name;
	int _from_time;
	VarStr _diagnosis;
	VarStr _auxiliary_diagnosis;
	VarStr _prescription;
	VarStr _allergy_history;
};
