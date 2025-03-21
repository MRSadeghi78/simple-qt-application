#ifndef TIMERMANAGER_H
#define TIMERMANAGER_H

#include <QObject>
#include <QTimer>

/**
 * @class TimerManager
 * @brief Manages time-related functionalities within the application.
 *
 * TimerManager provides functionalities to start and stop a timer and 
 * to query its status and elapsed time. It uses QTimer to handle timing operations
 * and emits signals for elapsed time updates and timer state changes.
 */
class TimerManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(int elapsedTime READ elapsedTime NOTIFY elapsedTimeChanged)
    Q_PROPERTY(bool running READ isRunning NOTIFY runningChanged)

public:
    /**
     * @brief Constructor for TimerManager.
     * @param parent Optional parent object.
     */
    explicit TimerManager(QObject *parent = nullptr);

    /**
     * @brief Destructor for TimerManager.
     */
    virtual ~TimerManager();

    /**
     * @brief Starts the timer.
     * 
     * Starts the internal QTimer if it is not already running. Emits the runningChanged signal.
     */
    Q_INVOKABLE void startTimer();

    /**
     * @brief Stops the timer.
     *
     * Stops the internal QTimer if it is currently running. Emits the runningChanged signal.
     */
    Q_INVOKABLE void stopTimer();

    /**
     * @brief Retrieves the elapsed time since the timer was started.
     * @return Elapsed time in seconds.
     */
    int elapsedTime() const;

    /**
     * @brief Checks if the timer is currently running.
     * @return True if the timer is running, otherwise false.
     */
    bool isRunning() const;

signals:
    /**
     * @brief Signal emitted when the elapsed time is updated.
     */
    void elapsedTimeChanged();

    /**
     * @brief Signal emitted when the timer's running state changes.
     * @param isRunning True if the timer is now running, false if stopped.
     */
    void runningChanged(bool isRunning);

private:
    QTimer* timer; ///< Pointer to the QTimer object handling the timing operations.
    int m_elapsedTime; ///< Tracks the elapsed time in seconds.
};

#endif // TIMERMANAGER_H
