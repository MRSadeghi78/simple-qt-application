#include "TimerManager.h"

TimerManager::TimerManager(QObject *parent) : QObject(parent), m_elapsedTime(0) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this]() {
        m_elapsedTime++;
        emit elapsedTimeChanged();
    });
    timer->setInterval(1000);
}

TimerManager::~TimerManager() {
    // Cleanup code if necessary
}

void TimerManager::startTimer() {
    if (!timer->isActive()) {
        timer->start();
        emit runningChanged(true);
    }
}

void TimerManager::stopTimer() {
    if (timer->isActive()) {
        timer->stop();
        emit runningChanged(false);
    }
}

bool TimerManager::isRunning() const {
    return timer->isActive();
}

int TimerManager::elapsedTime() const {
    return m_elapsedTime;
}
