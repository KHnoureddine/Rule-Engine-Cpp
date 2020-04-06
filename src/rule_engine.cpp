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
	RulesTree *Ucare = new RulesTree();
//	cout<< Ucare->isEmpty()<< endl;

	Action action_Spo2;
	Action action_Spo2_0("Spo2","it's OK");
	action_Spo2.addAction(action_Spo2_0);
	Action action_Spo2_1("Spo2","hyperoxie");
	action_Spo2.addAction(action_Spo2_1);
	Action action_Spo2_2("Spo2","hypoxie");
	action_Spo2.addAction(action_Spo2_2);

	Condition condition_Spo2;
	Condition condition_Spo2_1("Spo2","greater",100);
	condition_Spo2.addCondition(condition_Spo2_1);
	Condition condition_Spo2_2("Spo2","less",95);
	condition_Spo2.addCondition(condition_Spo2_2);

	Rule spo2("Spo2","Spo2",3,condition_Spo2.when, action_Spo2.then);



	Action action_HR;
	Action action_HR_0("HR","it's OK");
	action_HR.addAction(action_HR_0);
	Action action_HR_1("HR","tachycardio");
	action_HR.addAction(action_HR_1);
	Action action_HR_2("HR","bradycardio");
	action_HR.addAction(action_HR_2);
	Action action_HR_3("HR","arret cardiaque");
	action_HR.addAction(action_HR_3);

	Condition condition_HR;
	Condition condition_HR_1("HR","greater",194);
	condition_HR.addCondition(condition_HR_1);
	Condition condition_HR_2("HR","less",50);
	condition_HR.addCondition(condition_HR_2);
	Condition condition_HR_3("HR","equal",0);
	condition_HR.addCondition(condition_HR_3);

	Rule HR("HR","HR",2,condition_HR.when, action_HR.then);



	Action action_R;
	Action action_R_0("R","charge +");
	action_R.addAction(action_R_0);
	Action action_R_1("R","charge ++");
	action_R.addAction(action_R_1);
	Action action_R_2("R","charge normal");
	action_R.addAction(action_R_2);

	Condition condition_R;
	Condition condition_R_1("R","greater",23);
	condition_R.addCondition(condition_R_1);
	Condition condition_R_2("R","less",20);
	condition_R.addCondition(condition_R_2);

	Rule R("R","R",1,condition_R.when, action_R.then);


	Ucare->registeRule(HR);
	Ucare->registeRule(spo2);
	Ucare->registeRule(R);


//   cout<< Ucare->isEmpty()<< endl;
//   cout<< Ucare->exists("spo2")<< endl;
//   cout<<Ucare->rules[0].name<< endl;
//   cout<<Ucare->rules[0].ruleConditions[1].conditionOp << endl;
//   cout<<Ucare->rules[0].ruleConditions[0].conditionValidator << endl;
//   cout<<Ucare->rules[0].ruleActions[1].actionRole << endl;
//   cout<<Ucare->rules[0].ruleActions[0].actionRole << endl;
//
//   cout<< Ucare->exists("HR")<< endl;
//   cout<<Ucare->rules[1].name<< endl;
//   cout<<Ucare->rules[1].ruleConditions[1].conditionOp << endl;
//   cout<<Ucare->rules[1].ruleConditions[0].conditionValidator << endl;
//   cout<<Ucare->rules[1].ruleActions[1].actionRole << endl;
//   cout<<Ucare->rules[1].ruleActions[0].actionRole << endl;




	Fact fact;
	Fact fact_1("R",19);
	Fact fact_2("HR",0);
	Fact fact_3("Spo2",90);
	fact.addFact(fact_1);
	fact.addFact(fact_2);
	fact.addFact(fact_3);

//	cout<<fact.facts[0].factName  << endl;
//	cout<<fact.facts[1].factValue << endl;
//	cout<<fact.facts[2].factName  << endl;
//
//	cout<< Ucare->rules[0].evaluate(fact.facts[0])<<endl;
//	cout<< Ucare->rules[0].evaluate(fact.facts[1])<<endl;
//	cout<< Ucare->rules[0].evaluate(fact.facts[2])<<endl;

	RulesEngine example;
	example.fire(*Ucare, fact);







	return 0;
}

