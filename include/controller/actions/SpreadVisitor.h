//
// Created by ich on 1/28/20.
//

#ifndef POPULATIONDYNAMICS_SPREADVISITOR_H
#define POPULATIONDYNAMICS_SPREADVISITOR_H

#include "ActionVisitor.h"

class SpreadVisitor : public ActionVisitor {
public:
    void doIt(Shark& shark) override;
    void doIt(Fish& fish) override;
};

#endif //POPULATIONDYNAMICS_SPREADVISITOR_H
