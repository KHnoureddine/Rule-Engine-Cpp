#include"Action.h"

Action::Action(string actionName, string actionRole){
    this->actionName= actionName;
    this->actionRole= actionRole;
}
Action::Action(){
}
Action::~Action(){
}
void Action::addAction(Action action){
	this->then.push_back(action);
}
void Action::execute(Fact facts){
	cout<<actionName<<"  "<<actionRole<<endl;

}



