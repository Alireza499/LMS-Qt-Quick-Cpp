import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick 2.9
import QtQuick.Layouts 1.3


Page {
    width: 600
    height: 400


    title: MyHandler.getUserName() + " صفحه اصلی دانشجو:"

    Connections {
        target: MyHandler
        //onRightPassDanesjoo: label.text = MyHandler.getUserName()
        //onRightPassOstad: label.text = MyHandler.getUserName()

    }


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

            model: MyHandler.getDarsOfuserSize()

                Button
                {

                    width: parent.width
                    height: 65 //parent.height /MyHandler.getDarsOfuserSize()

                    text: MyHandler.getDarsOfuserName(index)

                    onClicked: {

                        MyHandler.goToAzmoonhaSaveDarsIndex(index)
                        stackView.push("AzmoonHaDaneshjoo.qml")

                     }

                }

            }
        }
    }

    Button {
        id: button
        x: 192
        y: 352
        width: 217
        height: 48
        text: qsTr("جستجو و اضافه کردن درس جدید")

        Connections {
            target: button
            onClicked: stackView.push("TamamDarsHaDaneshjoo.qml")
        }
    }

    Label {
        id: label1
        x: 418
        y: 24
        width: 117
        height: 17
        text: "لیست درس های کاربر"
        horizontalAlignment: Text.AlignRight
        font.pointSize: 12
    }

    Text {
        id: text1
        x: 187
        y: 188
        width: 227
        height: 24
        text: qsTr("هنوز درسی اضافه نکرده اید.")
        font.pixelSize: 19
        visible: MyHandler.getDarsOfuserSize() > 0 ? false : true
    }


    }

