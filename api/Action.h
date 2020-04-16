#ifndef ACTION_H_
#define ACTION_H_

#include"Condition.h"

class Action
{
public:
 string actionName;
 string actionRole;
 int    actionFollowing;
 vector <Action> then;

  Action();
 ~Action();
  Action(string actionName, string actionRole,int    actionFollowing);
  void addAction(Action action);
  int execute(Fact fact);

};
#endif /* ACTION_H_ */
