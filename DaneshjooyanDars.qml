import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick 2.9
import QtQuick.Layouts 1.3


Page {
    width: 600
    height: 400

    title:   " دانشجویان: "

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

            model: MyHandler.getDaneshjooOfDarsSize()

                Button
                {

                    width: parent.width
                    height: 65//parent.height/MyHandler.getDaneshjooOfDarsSize()+20

                    text: MyHandler.getDaneshjooOfDarsName(index)

                    onClicked:{

                        MyHandler.goToKarnameSaveDaneshjooIndex(index)
                        stackView.push("Karname.qml")
                     }

                }

            }
        }
    }

    Text {
        id: text1
        x: 110
        y: 186
        width: 380
        height: 28
        text: qsTr("هنوز دانشجویی به این درس اضافه نشده است.")
        font.pixelSize: 19
        visible: MyHandler.getDaneshjooOfDarsSize() > 0 ? false : true
    }

    Button {
        id: button
        x: 265
        y: 344
        text: qsTr("بازگشت")

        Connections {
            target: button
            onClicked: {

                    stackView.pop()


            }
        }
    }



}
