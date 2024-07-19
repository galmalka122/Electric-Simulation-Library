//
// Created by gal on 7/19/24.
//

#ifndef ELECTRIC_CIRCUT_H
#define ELECTRIC_CIRCUT_H

#include "electric_types.h"

namespace electric{
    class Circut
    {
    public:
        ComponentID AddComponent(ComponentPtr component);
        void Connect(const ComponentTerminal& ct1, const ComponentTerminal& ct2);
        void simulate(Time timeStep, Time duration);

    private:
        ComponentList components;
        std::vector<ComponentList> connections;
    };
}

#endif // ELECTRIC_CIRCUT_H
