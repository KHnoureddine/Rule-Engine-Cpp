#ifndef RULE_H_
#define RULE_H_

#include <stdlib.h>
#include <string>

#include "Action.h"

using namespace std;

class Rule {
public:
string name;
string description;
int priority;
vector <Condition> ruleConditions;
vector <Action> ruleActions;


 Rule();
 Rule(string name,string description, int priority,vector <Condition> ruleConditions,vector <Action> ruleActions);
 ~Rule();

 int evaluate(Fact fact);

};

#endif /* RULE_H_ */
