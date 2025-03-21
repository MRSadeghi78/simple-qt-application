#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include <QObject>

class ApplicationManager : public QObject {
    Q_OBJECT

public:
    explicit ApplicationManager(QObject *parent = nullptr);
    virtual ~ApplicationManager();
    
    Q_INVOKABLE void exitApplication();
    Q_INVOKABLE void eraseProject();
};

#endif // APPLICATIONMANAGER_H
