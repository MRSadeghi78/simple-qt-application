#ifndef USBMANAGER_H
#define USBMANAGER_H

#include <QObject>
#include <QList>
#include <QString>

class USBManager : public QObject {
    Q_OBJECT
public:
    explicit USBManager(QObject *parent = nullptr);
    virtual ~USBManager();
    
    Q_INVOKABLE QString listUSBDevices();
};

#endif // USBMANAGER_H
