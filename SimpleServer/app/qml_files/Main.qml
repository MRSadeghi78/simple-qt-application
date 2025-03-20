import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "Timer Example"

    Timer {
    id: timerManager
}

    Column {
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

        Label {
            text: "Elapsed Time: " + timerManager.elapsedTime
        }
    }
}
