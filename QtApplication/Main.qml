import QtQuick 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text {
        text: "Hello from QML"
        anchors.centerIn: parent
    }
}
