#include "TimerManager.h"
#include <QTimer>

/**
 * @brief Constructs a TimerManager object.
 *
 * Initializes a QTimer, connects its timeout signal to a slot that increments the elapsed time,
 * and sets the timer interval to 1000 milliseconds (1 second).
 *
 * @param parent The parent QObject, which defaults to nullptr.
 */
TimerManager::TimerManager(QObject *parent)
    : QObject(parent), m_elapsedTime(0) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this]() {
        m_elapsedTime++;
        emit elapsedTimeChanged();
    });
    timer->setInterval(1000); // Set the timer to tick every second.
}

/**
 * @brief Destructor for the TimerManager.
 *
 * Stops the timer upon object destruction to clean up resources properly.
 */
TimerManager::~TimerManager() {
    timer->stop(); // Ensure the timer is stopped to avoid running after object is deleted.
}

/**
 * @brief Starts the timer if it is not already active.
 *
 * Upon starting the timer, it emits a signal indicating that the timer is running.
 */
void TimerManager::startTimer() {
    if (!timer->isActive()) {
        timer->start();
        emit runningChanged(true); // Notify listeners that the timer has started.
    }
}

/**
 * @brief Stops the timer if it is currently active.
 *
 * Upon stopping the timer, it emits a signal indicating that the timer is not running.
 */
void TimerManager::stopTimer() {
    if (timer->isActive()) {
        timer->stop();
        emit runningChanged(false); // Notify listeners that the timer has stopped.
    }
}

/**
 * @brief Checks if the timer is currently running.
 *
 * @return True if the timer is active, false otherwise.
 */
bool TimerManager::isRunning() const {
    return timer->isActive();
}

/**
 * @brief Retrieves the current elapsed time since the timer was started.
 *
 * @return The elapsed time in seconds.
 */
int TimerManager::elapsedTime() const {
    return m_elapsedTime;
}
