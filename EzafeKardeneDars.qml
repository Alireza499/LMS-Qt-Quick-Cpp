import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    title: qsTr("پیام")

    Connections {
        target: MyHandler
        onDaneshjooadded: {

            text1.text = "آزمون با موفقیت اضافه شد"


            MyHandler.calculateDarsOfUser()

           if (stackView.depth > 1) {
               stackView.pop()
           }
           if (stackView.depth > 1) {
               stackView.pop()
           }
           if (stackView.depth > 1) {
               stackView.pop()
           }
           if (stackView.depth > 1) {
               stackView.pop()
           }
           if (stackView.depth > 1) {
               stackView.pop()
           }
           if (stackView.depth > 1) {
               stackView.pop()
           }
           stackView.push("AsliDaneshjoo.qml")

        }
        onError: {
            textArea.text = ""
            text1.text = "خطا"
        }
    }



    Label {
        id: label
        x: 99
        y: 52
        width: 403
        height: 99

        text: "آیا از اضافه کردن این درس اطمینان دارید؟"
        font.pointSize: 14
    }

    Button {
        id: button
        x: 268
        y: 338
        text: qsTr("بازگشت")

        Connections {
            target: button
            onClicked: {
                if (stackView.depth > 2) {
                    stackView.pop()
                }
                if (stackView.depth > 2) {
                    stackView.pop()
                }
                if (stackView.depth > 2) {
                    stackView.pop()
                }
                if (stackView.depth > 2) {
                    stackView.pop()
                }
                if (stackView.depth > 2) {
                    stackView.pop()
                }
                if (stackView.depth > 2) {
                    stackView.pop()
                }
            }
        }
    }

    Button {
        id: button1
        x: 268
        y: 273
        text: qsTr("تایید")
        Connections {
            target: button1
            onClicked: MyHandler.addDaneshjooForDars()
        }
    }

    Text {
        id: text1
        x: 289
        y: 171
        font.pixelSize: 12
    }
}
