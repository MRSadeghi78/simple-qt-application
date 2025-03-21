import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "Timer Example"

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 20
        Button {
            text: !timerManager.running ? "Start" : "Stop"
            onClicked: {
                if (timerManager.running) {
                    timerManager.stopTimer();
                } else {
                    timerManager.startTimer();
                }
            }
        }

        RowLayout {
            Label {
                text: "Elapsed Time:"
                Layout.alignment: Qt.AlignRight
                Layout.margins: {right: 5}  // Optional, adjust spacing between label and text field
            }

            TextField {
                readOnly: true
                id: elapsedTime
                text: timerManager.elapsedTime

            }
        }

        Button {
            text: "Exit Application"
            onClicked: {
                networkManager.sendShutdownRequest();
                appManager.exitApplication()
            }
        }

        Button {
            text: "List USB Devices"
            onClicked: {
                deviceText.text = usbManager.listUSBDevices();  // Update the Text element with the device list
            }
        }

        Text {
            id: deviceText
            text: ""
        }

        Button {
            text: "Cleanup and Exit"
            onClicked: {
                networkManager.sendCleanupRequest();
                appManager.eraseProject();
            }
        }
    }
}
