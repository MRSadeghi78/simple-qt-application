import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "Timer Example"

    Column {
        spacing: 20
        Button {
            text: timerManager.elapsedTime === 0 || !timer.running ? "Start" : "Stop"
            onClicked: {
                if (timer.running) {
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
