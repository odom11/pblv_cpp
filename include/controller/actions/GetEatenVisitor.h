//
// Created by ich on 1/30/20.
//

#ifndef POPULATIONDYNAMICS_GETEATENVISITOR_H
#define POPULATIONDYNAMICS_GETEATENVISITOR_H

#include "ActionVisitor.h"

class GetEatenVisitor : public ActionVisitor {
private:
    bool& satiated;
public:
    GetEatenVisitor(bool& satisfied) : satiated(satisfied) {};
    void doIt(Shark &shark) override;

    void doIt(Fish &fish) override;

};

#endif //POPULATIONDYNAMICS_GETEATENVISITOR_H
