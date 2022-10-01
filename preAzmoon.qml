import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    title: MyHandler.getAzmmonUserName(MyHandler.getTmpindex()) + "  آزمون : "

    Button {
        id: button
        x: 188
        y: 142
        width: 225
        height: 48
        text: qsTr("شروع آزمون")

        Connections {
            target: button
            onClicked: {
                stackView.push("DaneshjooAzmoon.qml")
                MyHandler.checkAzmoon()
            }
        }
    }

    Button {
        id: button1
        x: 188
        y: 204
        width: 225
        height: 48
        text: qsTr("انصراف")

        Connections {
            target: button1
            onClicked: {

                    stackView.pop()

            }
        }
    }
}
