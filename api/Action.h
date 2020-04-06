#ifndef ACTION_H_
#define ACTION_H_

#include"Condition.h"

class Action
{
public:
 string actionName;
 string actionRole;
 vector <Action> then;

  Action();
 ~Action();
  Action(string actionName, string actionRole);
  void addAction(Action action);
  void execute(Fact fact);

};
#endif /* ACTION_H_ */
