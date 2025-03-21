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

        // Button to start or stop the timer based on its current state
        Button {
            text: timerManager.running ? "Stop" : "Start"
            onClicked: {
                if (timerManager.running) {
                    timerManager.stopTimer();
                } else {
                    timerManager.startTimer();
                }
            }
        }

        // Display the elapsed time in a read-only text field
        RowLayout {
            Label {
                text: "Elapsed Time:"
                Layout.alignment: Qt.AlignRight
                Layout.margins: {right: 5}
            }

            TextField {
                readOnly: true
                id: elapsedTime
                text: timerManager.elapsedTime
            }
        }

        // Button to exit the application and send a shutdown request to the server
        Button {
            text: "Exit Application"
            onClicked: {
                networkManager.sendShutdownRequest();
                appManager.exitApplication();
            }
        }

        // Button to list USB devices and display them below
        Button {
            text: "List USB Devices"
            onClicked: {
                deviceText.text = usbManager.listUSBDevices();
            }
        }

        // Text element to display the list of USB devices
        Text {
            id: deviceText
            text: ""
        }

        // Button to clean up and exit the application
        Button {
            text: "Cleanup and Exit"
            onClicked: {
                networkManager.sendCleanupRequest();
                appManager.eraseProject();
            }
        }
    }
}
