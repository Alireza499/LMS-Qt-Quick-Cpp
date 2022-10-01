import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    maximumHeight: height
        maximumWidth: width

        minimumHeight: height
        minimumWidth: width
    title: qsTr("Stack")

    header: ToolBar {
        contentHeight: toolButton.implicitHeight

        ToolButton {
            id: toolButton
            text:  "\u2630"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: {

                    drawer.open()

            }
        }

        Label {
            text: stackView.currentItem.title
            anchors.centerIn: parent
        }
    }

    Drawer {
        id: drawer
        width: window.width * 0.66
        height: window.height

        Column {
            anchors.fill: parent

            ItemDelegate {
                text: qsTr("ثبت نام")
                width: parent.width
                onClicked: {
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
                    stackView.push("SignUp.ui.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("خارج شدن")
                width: parent.width
                onClicked: {
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

                    stackView.push("HomeForm.ui.qml")
                    drawer.close()
                }
            }
        }
    }

    StackView {
        id: stackView
        initialItem: "HomeForm.ui.qml"
        anchors.fill: parent
    }
}
