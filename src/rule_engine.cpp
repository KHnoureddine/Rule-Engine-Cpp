//============================================================================
// Name        : rule_engine.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdlib.h>
#include <iostream>
#include <string>
#include "../api/RulesEngine.h"

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	RulesTree *UcareLevel_1 = new RulesTree();

	Action action_Spo2;
	Action action_Spo2_0("Spo2","it's OK",3);
	action_Spo2.addAction(action_Spo2_0);
	Action action_Spo2_1("Spo2","hyperoxie",0);
	action_Spo2.addAction(action_Spo2_1);
	Action action_Spo2_2("Spo2","hypoxie",0);
	action_Spo2.addAction(action_Spo2_2);

	Condition condition_Spo2;
	Condition condition_Spo2_1("Spo2","greater",100);
	condition_Spo2.addCondition(condition_Spo2_1);
	Condition condition_Spo2_2("Spo2","less",95);
	condition_Spo2.addCondition(condition_Spo2_2);

	Rule spo2("Spo2","Spo2",2,condition_Spo2.when, action_Spo2.then);

	Action action_HR;
	Action action_HR_0("HR","it's OK",2);
	action_HR.addAction(action_HR_0);
	Action action_HR_1("HR","tachycardio",0);
	action_HR.addAction(action_HR_1);
	Action action_HR_2("HR","bradycardio",0);
	action_HR.addAction(action_HR_2);
	Action action_HR_3("HR","arret cardiaque",0);
	action_HR.addAction(action_HR_3);

	Condition condition_HR;
	Condition condition_HR_1("HR","greater",194);
	condition_HR.addCondition(condition_HR_1);
	Condition condition_HR_2("HR","less",50);
	condition_HR.addCondition(condition_HR_2);
	Condition condition_HR_3("HR","equal",0);
	condition_HR.addCondition(condition_HR_3);

	Rule HR("HR","HR",1,condition_HR.when, action_HR.then);

	Action action_R;
	Action action_R_0("R","charge élevé",1);
	action_R.addAction(action_R_0);
	Action action_R_1("R","charge trés élevé",3);
	action_R.addAction(action_R_1);
	Action action_R_2("R","charge normal",1);
	action_R.addAction(action_R_2);

	Condition condition_R;
	Condition condition_R_1("R","greater",23);
	condition_R.addCondition(condition_R_1);
	Condition condition_R_2("R","less",20);
	condition_R.addCondition(condition_R_2);

	Rule R("R","R",0,condition_R.when, action_R.then);

	Action action_ACCL;
	Action action_ACCL_0("ACCL","chute libre + active",0);
	action_ACCL.addAction(action_ACCL_0);
	Action action_ACCL_1("ACCL","pas de chute libre",0);
	action_ACCL.addAction(action_ACCL_1);
	Action action_ACCL_2("ACCL","chute libre - active",0);
	action_ACCL.addAction(action_ACCL_2);

	Condition condition_ACCL;
	Condition condition_ACCL_1("ACCL","greater",1);
	condition_ACCL.addCondition(condition_ACCL_1);
	Condition condition_ACCL_2("ACCL","less",1);
	condition_ACCL.addCondition(condition_ACCL_2);

	Rule ACCL("ACCL","ACCL",3,condition_ACCL.when, action_ACCL.then);

	UcareLevel_1->registeRule(HR);
	UcareLevel_1->registeRule(spo2);
	UcareLevel_1->registeRule(ACCL);
	UcareLevel_1->registeRule(R);

    Fact fact;
	Fact fact_1("R",13);
	Fact fact_2("Spo2",96);
	Fact fact_3("ACCL",0);
	Fact fact_4("HR",80);

	fact.addFact(fact_1);
	fact.addFact(fact_2);
	fact.addFact(fact_3);
	fact.addFact(fact_4);

	RulesEngine *example=new RulesEngine();
	example->fire(*UcareLevel_1, fact);

	UcareLevel_1->clearAll();
	delete(UcareLevel_1);
	delete(example);


	return 0;
}

