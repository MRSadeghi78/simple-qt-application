#include "../headers/TimerManager.h"

/**
 * Constructs the TimerManager object and initializes the internal QTimer.
 * Connects the QTimer's timeout signal to the appropriate slot for handling.
 *
 * @param parent The parent QObject, default is nullptr.
 */
TimerManager::TimerManager(QObject *parent)
    : QObject(parent), m_timer(new QTimer(this)) {
    connect(m_timer, &QTimer::timeout, this, &TimerManager::handleTimeout);
    m_timer->setInterval(1000); // Configure the timer to tick every second
}

/**
 * Destructor for the TimerManager class. Ensures the timer is stopped
 * before the object is destroyed.
 */
TimerManager::~TimerManager() {
    m_timer->stop();
}

/**
 * Starts the timer if it is not already running. Also emits the runningChanged
 * signal to indicate that the timer has started.
 */
void TimerManager::startTimer() {
    if (!m_timer->isActive()) {
        m_timer->start();
        emit runningChanged(true);
    }
}

/**
 * Stops the timer if it is currently running. Emits the runningChanged signal
 * to indicate that the timer has stopped.
 */
void TimerManager::stopTimer() {
    if (m_timer->isActive()) {
        m_timer->stop();
        emit runningChanged(false);
    }
}

/**
 * Returns whether the timer is currently active.
 *
 * @return True if the timer is active, otherwise false.
 */
bool TimerManager::isRunning() const {
    return m_timer->isActive();
}

/**
 * Slot that handles the QTimer's timeout event. This method is called
 * every time the QTimer emits the timeout signal (every second when active).
 * It emits the 'tick' signal to indicate a timer tick has occurred.
 */
void TimerManager::handleTimeout() {
    emit tick();  // Emit tick signal on each timeout
}
