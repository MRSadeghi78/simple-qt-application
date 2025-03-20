#ifndef TIMERMANAGER_H
#define TIMERMANAGER_H

#include <QObject>
#include <QTimer>

class TimerManager : public QObject {
    Q_OBJECT  // Make sure this macro is present and correctly placed
public:
    explicit TimerManager(QObject *parent = nullptr);
    virtual ~TimerManager() = 0;  // Ensure virtual destructor is declared if needed

    Q_INVOKABLE void startTimer();
    Q_INVOKABLE void stopTimer();
    int elapsedTime() const;

signals:
    void elapsedTimeChanged();  // Signal must be declared in this section

private:
    QTimer* timer;
    int m_elapsedTime;
};

#endif // TIMERMANAGER_H
