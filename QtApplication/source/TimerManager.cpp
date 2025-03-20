#include "../headers/TimerManager.h"

TimerManager::TimerManager(QObject *parent) : QObject(parent), m_elapsedTime(0) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this]() {
        m_elapsedTime++;
        emit elapsedTimeChanged();
    });
}

TimerManager::~TimerManager() {
    // Cleanup code if necessary
}

void TimerManager::startTimer() {
    timer->start(1000); // Timer ticks every second
}

void TimerManager::stopTimer() {
    timer->stop();
}

int TimerManager::elapsedTime() const {
    return m_elapsedTime;
}
