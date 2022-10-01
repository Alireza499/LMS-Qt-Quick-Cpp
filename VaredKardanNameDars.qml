import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    title: qsTr("درس جدید")

    Connections {
        target: MyHandler
        onDarsadded: {
            textArea.text = ""
            text1.text = "درس با موفقیت اضافه شد"

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
            stackView.push("AsliOstad.qml")

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
        text: qsTr("نام درس جدید ر اضافه کنید")
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
        x: 269
        y: 291
        text: qsTr("تایید")

        Connections {
            target: button
            onClicked: MyHandler.addDars(textArea.text)
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
        x: 269
        y: 345
        text: qsTr("بازگشت")

        Connections {
            target: button1
            onClicked: {

                    stackView.pop()


            }
        }
    }
}
