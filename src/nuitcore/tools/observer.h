#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include "../color.hpp"

/*src = https://refactoring.guru/fr/design-patterns/observer/cpp/example */
/**
 * @brief Class that observes. Recieves a signal to apply any changes.
 * 
 */
class Observer
{
public:
/**
 * @brief Updates whatever is concerned with this.
 * 
 */
    virtual void Update() = 0;
    /**
     * @brief Destroy the Observer object
     * 
     */
    virtual ~Observer(){};
};
#endif // OBSERVER_H
