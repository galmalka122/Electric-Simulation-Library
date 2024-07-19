//
// Created by gal on 7/19/24.
//

#ifndef ELECTRIC_TYPES_H
#define ELECTRIC_TYPES_H

#include <cstddef>
#include <memory>
#include <vector>

namespace electric {

    // Type aliases for improved readability
    using ComponentID = std::size_t;
    using TerminalID = std::size_t;
    using Voltage = double;
    using Current = double;
    using Time = double;

    using ComponentTerminal = std::pair<ComponentID, TerminalID>;

    namespace component
    {
        class Component
        {
        public:
            virtual ~Component() = default;
            virtual void update(Time timeStep) = 0;
            [[nodiscard]] virtual TerminalID getNumTerminals() const = 0;
            [[nodiscard]] virtual Voltage getVoltage(TerminalID terminal) const = 0;
            virtual void setVoltage(TerminalID terminal, Voltage voltage) = 0;
            [[nodiscard]] virtual Current getCurrent(TerminalID terminal) const = 0;
            [[nodiscard]] virtual Current getCurrentFlow(TerminalID fromTerminal, TerminalID toTerminal) const = 0;
        };
    }

    using ComponentPtr = std::unique_ptr<component::Component>;
    using ComponentList = std::vector<ComponentPtr>;
    using ConnectionList = std::vector<ComponentTerminal>;

    struct Connection
    {
        ComponentTerminal ct1;
        ComponentTerminal ct2;
    };

}

#endif //ELECTRIC_TYPES_H
