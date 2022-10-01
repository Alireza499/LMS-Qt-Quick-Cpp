import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick 2.9
import QtQuick.Layouts 1.3


Page {

    width: 600
    height: 400

    title: "درس مورد نظر خود را انتخاب کنید"

    ScrollView
    {

        y: 50
        width: parent.width
        height: 300

    Column{
        x: 100
        y: 50

        width: 400
        height: 300
        Repeater {

            model: MyHandler.getKolDarshaSize()

                Button
                {

                    width: parent.width
                    height: 65//parent.height /MyHandler.getKolDarshaSize()

                    text: MyHandler.getKolDarshaName(index)

                    onClicked: {

                        MyHandler.goToDarsSavekolDarsIndex(index)
                        stackView.push("EzafeKardeneDars.qml")

                     }

                }

            }
        }
    }



    Label {
        id: label1
        x: 418
        y: 24
        width: 117
        height: 17
        text: "لیست درس ها"
        horizontalAlignment: Text.AlignRight
        font.pointSize: 12
    }
    Text {
        id: text1
        x: 151
        y: 188
        width: 299
        height: 24
        text: qsTr("هیچ درسی در سیتسم موجود نیست")
        font.pixelSize: 19
        visible: MyHandler.getKolDarshaSize() > 0 ? false : true
    }

    Button {
        id: button
        x: 266
        y: 343
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

            }
        }
    }

}
