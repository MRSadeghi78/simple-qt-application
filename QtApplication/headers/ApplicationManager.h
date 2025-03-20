#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include <QObject>

class ApplicationManager : public QObject {
    Q_OBJECT

public:
    explicit ApplicationManager(QObject *parent = nullptr);
    Q_INVOKABLE void exitApplication();

};

#endif // APPLICATIONMANAGER_H
