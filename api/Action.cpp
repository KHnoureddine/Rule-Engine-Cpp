#include"Action.h"

Action::Action(string actionName, string actionRole,int    actionFollowing){
    this->actionName= actionName;
    this->actionRole= actionRole;
    this->actionFollowing= actionFollowing;
}
Action::Action(){
}
Action::~Action(){
}
void Action::addAction(Action action){
	this->then.push_back(action);
}
int Action::execute(Fact facts){
	int executeReturn = 0;
	cout<<actionName<<"  "<<actionRole<<endl;
	executeReturn =actionFollowing;
	return executeReturn;

}



