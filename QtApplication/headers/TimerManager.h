#ifndef TIMERMANAGER_H
#define TIMERMANAGER_H

#include <QObject>
#include <QTimer>

class TimerManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(int elapsedTime READ elapsedTime NOTIFY elapsedTimeChanged)

public:
    explicit TimerManager(QObject *parent = nullptr);

    Q_INVOKABLE void startTimer();
    Q_INVOKABLE void stopTimer();
    int elapsedTime() const;

signals:
    void elapsedTimeChanged();

private:
    QTimer* timer;
    int m_elapsedTime;
};

#endif // TIMERMANAGER_H
