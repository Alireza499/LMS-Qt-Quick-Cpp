import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick 2.9
import QtQuick.Layouts 1.3


Page {
    width: 600
    height: 400

    title:  MyHandler.getDarsOfuserName(MyHandler.getTmpindex()) + " صفحه آزمون های درس: "

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

            model: MyHandler.getAzmoonOfDarsSize()

                Button
                {

                    width: parent.width
                    height: 65//parent.height /MyHandler.getAzmoonOfDarsSize()

                    text: MyHandler.getAzmoonOfDarsName(index)

                    onClicked: {

                        MyHandler.goToAzmoonSaveAzmoonIndex(index)
                        MyHandler.searchforTakenAzmoon()?stackView.push("Karname.qml"):stackView.push("preAzmoon.qml")

                     }

                }

            }
        }
    }

  /*  Button {
        id: button
        x: 192
        y: 352
        width: 217
        height: 48
        text: qsTr("اضافه کردن آزمون جدید")

        Connections {
            target: button
            onClicked: stackView.push("VaredKardanNameAzmoon.qml")
        }
   }  */

    Label {
        id: label1
        x: 418
        y: 24
        width: 117
        height: 17
        text: "لیست آزمون های درس"
        horizontalAlignment: Text.AlignRight
        font.pointSize: 12
    }
    Text {
        id: text1
        x: 147
        y: 187
        width: 306
        height: 26
        text: qsTr("هنوز آزمونی برای این درس ایجاد نشده")
        font.pixelSize: 19
        visible: MyHandler.getAzmoonOfDarsSize() > 0 ? false : true
    }

    Button {
        id: button
        x: 268
        y: 342
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
