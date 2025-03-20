#ifndef TIMERMANAGER_H
#define TIMERMANAGER_H

#include <QObject>
#include <QTimer>

/**
 * @class TimerManager
 * @brief Manages a timer and emits signals at regular intervals.
 *
 * TimerManager handles starting and stopping a QTimer and emits signals
 * when the timer is started or stopped. It also emits a 'tick' signal
 * at regular one-second intervals whenever the timer is active.
 */
class TimerManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool running READ isRunning NOTIFY runningChanged)

public:
    /**
     * @brief Constructor for TimerManager.
     * @param parent The parent QObject, default is nullptr.
     */
    explicit TimerManager(QObject *parent = nullptr);

    /**
     * @brief Destructor for TimerManager.
     */
    ~TimerManager();

    /**
     * @brief Starts the timer if it is not already active.
     */
    Q_INVOKABLE void startTimer();

    /**
     * @brief Stops the timer if it is currently active.
     */
    Q_INVOKABLE void stopTimer();

    /**
     * @brief Checks if the timer is currently running.
     * @return True if the timer is active, false otherwise.
     */
    bool isRunning() const;

signals:
    /**
     * @brief Signal emitted when the running state of the timer changes.
     * @param isRunning The new running state of the timer.
     */
    void runningChanged(bool isRunning);

    /**
     * @brief Signal emitted every second when the timer is active.
     */
    void tick();

private:
    QTimer *m_timer;  ///< The QTimer object managed by this class.

    /**
     * @brief Triggers the "tick" signal after each 1 second
     */
    void handleTimeout();
};

#endif // TIMERMANAGER_H
