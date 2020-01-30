//
// Created by ich on 1/30/20.
//

#ifndef POPULATIONDYNAMICS_FEEDVISITOR_H
#define POPULATIONDYNAMICS_FEEDVISITOR_H

#include "ActionVisitor.h"

class FeedVisitor : public ActionVisitor {
public:
    void doIt(Shark &shark) override;

    void doIt(Fish &fish) override;
};

#endif //POPULATIONDYNAMICS_FEEDVISITOR_H
