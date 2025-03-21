#ifndef USBMANAGER_H
#define USBMANAGER_H

#include <QObject>
#include <QString>

/**
 * @class USBManager
 * @brief Manages interactions with USB devices.
 *
 * USBManager provides functionality to list all connected USB devices,
 * retrieving details such as vendor ID, product ID, and device location.
 * This class serves as an interface between the Qt application and the system's USB ports.
 */
class USBManager : public QObject {
    Q_OBJECT
public:
    /**
     * @brief Constructs a USBManager object.
     * @param parent The parent QObject, default is nullptr.
     * Initializes the USBManager, setting up necessary configurations for USB operations.
     */
    explicit USBManager(QObject *parent = nullptr);

    /**
     * @brief Destructor for USBManager.
     * Cleans up resources used by the USBManager.
     */
    virtual ~USBManager();

    /**
     * @brief Lists all connected USB devices with detailed information.
     * 
     * Fetches and formats a string containing detailed information about each connected USB device,
     * including vendor ID, product ID, and the physical bus location of the device.
     * 
     * @return QString containing formatted details of all connected USB devices.
     */
    Q_INVOKABLE QString listUSBDevices();
};

#endif // USBMANAGER_H
