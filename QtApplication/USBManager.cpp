#include "USBManager.h"
#include <libusb.h>

USBManager::USBManager(QObject *parent) : QObject(parent) {
    libusb_init(NULL);
}

USBManager::~USBManager() {
    libusb_exit(NULL);
}

QString USBManager::listUSBDevices() {
    QString result;
    libusb_device **list;
    ssize_t count = libusb_get_device_list(NULL, &list);

    for (ssize_t i = 0; i < count; i++) {
        libusb_device *device = list[i];
        libusb_device_descriptor desc;
        libusb_get_device_descriptor(device, &desc);

        QString vendor = QString::number(desc.idVendor, 16).toUpper();  // Display vendor ID in hexadecimal
        QString model = QString::number(desc.idProduct, 16).toUpper();  // Display model ID in hexadecimal
        QString location = QString("Bus %1 Device %2").arg(libusb_get_bus_number(device)).arg(libusb_get_device_address(device));

        result += QString("Vendor: %1, Model: %2, Location: %3\n").arg(vendor, model, location);
    }

    libusb_free_device_list(list, 1);  // Free the device list after processing
    return result.trimmed();  // Remove the last newline character
}
