import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    title: qsTr("")

    Label {
        id: label
        x: 99
        y: 64
        width: 403
        height: 99
        color: "#48a20c"
        text: "آزمون مورد نظر با موفقیت اضافه شد."
        font.pointSize: 16
    }

    Button {
        id: button
        x: 266
        y: 259
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
}
