#include "USBManager.h"
#include <libusb.h>

USBManager::USBManager(QObject *parent) : QObject(parent) {
    libusb_init(NULL);
}

USBManager::~USBManager() {
    libusb_exit(NULL);
}

QList<USBDevice> USBManager::listUSBDevices() {
    QList<USBDevice> devices;
    libusb_device **list;
    ssize_t count = libusb_get_device_list(NULL, &list);

    for (ssize_t i = 0; i < count; i++) {
        libusb_device *device = list[i];
        libusb_device_descriptor desc;
        libusb_get_device_descriptor(device, &desc);

        USBDevice usbDevice;
        usbDevice.vendor = QString::number(desc.idVendor);
        usbDevice.model = QString::number(desc.idProduct);
        usbDevice.location = QString("Bus %1 Device %2").arg(libusb_get_bus_number(device)).arg(libusb_get_device_address(device));

        devices.append(usbDevice);
    }

    libusb_free_device_list(list, 1);
    return devices;
}
