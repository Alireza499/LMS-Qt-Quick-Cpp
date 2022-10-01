import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.3

ApplicationWindow {
    width: 300
    height: 300
    visible: true
    Connections {
        target: MyHandler
        onTimesUp: {

        }
    }

    property double startTime: 0

    ColumnLayout {
        anchors.fill: parent

        Text {
            id: time
            font.pixelSize: 30
            text: "The date is: " + new Date().toLocaleTimeString(Qt.locale("de_DE"))//MyHandler.isTimeUp(new Date().getTime(),startTime)? "زمان شما به پایان رسید":new Date().getTime() - startTime.toString("hh:ss")
            Layout.alignment: Qt.AlignCenter
        }
        Text {
            id: time1
            font.pixelSize: 30
            text: new Date().getTime() - startTime.toString("hh:ss")
            Layout.alignment: Qt.AlignCenter
        }

        Button {
            text: "Click me!"
            Layout.alignment: Qt.AlignCenter

            onClicked: {
                if(MyHandler.isTimeUp(new Date().getTime(),startTime)){
                    time.text = "زمان شما به پایان رسید"
                    //startTime = new Date().getTime()
                }
            }
        }
    }
}
