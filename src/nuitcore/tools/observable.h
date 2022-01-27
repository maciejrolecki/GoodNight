#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include "observer.h"
/*src = https://refactoring.guru/fr/design-patterns/observer/cpp/example */

/**
 * @brief Class to be observed. Transferes a signal when required to notify of changes.
 * 
 */
class Observable
{
public:
/**
 * @brief Attaches Observers if there are any.
 * 
 * @param observer The watcher that will receive notifications.
 */
    virtual void Attach(Observer *observer) = 0;
    /**
     * @brief Removes the said watcher.
     * 
     * @param observer 
     */
    virtual void Detach(Observer *observer) = 0;
    /**
     * @brief Alerts the observer about recent changes.
     * 
     */
    virtual void Notify() = 0;
    /**
     * @brief Destroy the Observable object
     * 
     */
    virtual ~Observable(){};
};
#endif // OBSERVABLE_H
