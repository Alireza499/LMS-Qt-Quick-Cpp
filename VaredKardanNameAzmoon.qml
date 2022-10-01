import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    title: qsTr("آزمون جدید")

    Connections {
        target: MyHandler
        onAzmoonadded: {
            textArea.text = ""
            text1.text = "آزمون با موفقیت اضافه شد"

            MyHandler.calculateAzmoonOfDars()

            stackView.push("OstadAzmoon.ui.qml")
        }
        onError: {
            textArea.text = ""
            text1.text = "خطا"
        }
    }

    Label {
        id: label
        x: 124
        y: 20
        width: 353
        height: 88
        text: qsTr("نام آزمون جدید ر اضافه کنید")
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 16
    }

    TextArea {
        id: textArea
        x: 241
        y: 178
        horizontalAlignment: Text.AlignHCenter
        placeholderText: qsTr("اینجا وارد کنید")
    }

    Button {
        id: button
        x: 225
        y: 284
        text: qsTr("تایید و وارد کردن سوالات")

        Connections {
            target: button
            onClicked: MyHandler.addAzmoon(textArea.text)
        }
    }

    Text {
        id: text1
        x: 290
        y: 271
        text: qsTr("")
        font.pixelSize: 12
    }

    Button {
        id: button1
        x: 225
        y: 338
        width: 152
        height: 48
        text: qsTr("بازگشت")

        Connections {
            target: button1
            onClicked: {

                    stackView.pop()


            }
        }
    }
}
