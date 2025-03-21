#include "USBManager.h"
#include <libusb.h>

/**
 * @brief Constructs the USBManager object.
 * Initializes the libusb library which is required for USB operations.
 * 
 * @param parent The parent QObject, default is nullptr.
 */
USBManager::USBManager(QObject *parent) : QObject(parent) {
    libusb_init(NULL); // Initialize the libusb library
}

/**
 * @brief Destructor for the USBManager.
 * Cleans up by exiting the libusb library to free up resources.
 */
USBManager::~USBManager() {
    libusb_exit(NULL); // Finalize the libusb library
}

/**
 * @brief Lists all connected USB devices and their details.
 * 
 * This method queries all USB devices connected to the system and formats their
 * vendor ID, product ID, and bus location into a human-readable string.
 * 
 * @return QString containing a line-by-line description of each USB device.
 */
QString USBManager::listUSBDevices() {
    QString result; // String to hold the result
    libusb_device **list; // Pointer to the list of found devices
    ssize_t count = libusb_get_device_list(NULL, &list); // Get the list of devices

    for (ssize_t i = 0; i < count; i++) {
        libusb_device *device = list[i]; // Pointer to the device
        libusb_device_descriptor desc; // Device descriptor
        libusb_get_device_descriptor(device, &desc); // Get the device descriptor

        // Convert vendor and product IDs to hexadecimal strings
        QString vendor = QString::number(desc.idVendor, 16).toUpper();
        QString model = QString::number(desc.idProduct, 16).toUpper();
        // Format the location string
        QString location = QString("Bus %1 Device %2").arg(libusb_get_bus_number(device))
                                                     .arg(libusb_get_device_address(device));

        // Append device information to result string
        result += QString("Vendor: %1, Model: %2, Location: %3\n").arg(vendor, model, location);
    }

    libusb_free_device_list(list, 1); // Free the device list
    return result.trimmed(); // Trim the trailing newline character and return the result
}
