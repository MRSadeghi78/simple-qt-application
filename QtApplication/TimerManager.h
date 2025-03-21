#ifndef TIMERMANAGER_H
#define TIMERMANAGER_H

#include <QObject>
#include <QTimer>

class TimerManager : public QObject {
    Q_OBJECT  // Make sure this macro is present and correctly placed
    Q_PROPERTY(int elapsedTime READ elapsedTime NOTIFY elapsedTimeChanged)
    Q_PROPERTY(bool running READ isRunning NOTIFY runningChanged)

public:
    explicit TimerManager(QObject *parent = nullptr);
    virtual ~TimerManager();  // Ensure virtual destructor is declared if needed

    Q_INVOKABLE void startTimer();
    Q_INVOKABLE void stopTimer();
    int elapsedTime() const;
    bool isRunning() const;

signals:
    void elapsedTimeChanged();  // Signal must be declared in this section
    void runningChanged(bool isRunning);

private:
    QTimer* timer;
    int m_elapsedTime;
};

#endif // TIMERMANAGER_H
