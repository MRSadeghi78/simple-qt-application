#ifndef USBMANAGER_H
#define USBMANAGER_H

#include <QObject>
#include <QList>
#include <QString>

class USBDevice {
public:
    QString vendor;
    QString model;
    QString location;
};

class USBManager : public QObject {
    Q_OBJECT
public:
    explicit USBManager(QObject *parent = nullptr);
    virtual ~USBManager();
    
    Q_INVOKABLE QList<USBDevice> listUSBDevices();
};

#endif // USBMANAGER_H
