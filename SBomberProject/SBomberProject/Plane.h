#pragma once

#include "DynamicObject.h"
//class Visitor;
#include "Visitor.h"

class Plane : public DynamicObject {
public:

    void Draw() const override;

    inline void ChangePlaneY(double dy) { yDirection += dy; }
    void __fastcall Accept(Visitor& v);

private:

};

