import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick 2.9
import QtQuick.Layouts 1.3


Page {
    width: 600
    height: 400
    id :pageP

    title:  " کارنامه آزمون: "
    ScrollView
    {
        width: 585
        height: 272
       // anchors.fill: parent

        clip : true



        Column{
            x: 8
            y: 14


        width: 585
        height: 272


        Repeater {

            model: MyHandler.getKarnameOfAzmoonDaneshjooSize()
            anchors.left: parent.left
            anchors.right: parent.right
            RowLayout{
                anchors.horizontalCenter: parent.horizontalCenter
                Label
                {

                    width: parent.width
                    LayoutMirroring.enabled: true
                    anchors.left: parent.left

                    text: MyHandler.getSoualOfAzmoon(index)


                }
                Label
                {

                    width: parent.width
                    LayoutMirroring.enabled: true
                    anchors.right: parent.right

                    text:MyHandler.getKarnameOfAzmoonDaneshjooJavab(index)
                    color: "#0960bb"

                }
            }

        }
    }
    }
    Label
    {

        x: pageP.width /2 - 65
        y: 370

        //width: parent.width


        text:"نمره دانشجو :" + MyHandler.getKarnameOfAzmoonDaneshjooNomreKol() + " / " +MyHandler.getKarnameOfAzmoonDaneshjooNomreDaneshjoo()  + " = " + MyHandler.getKarnameOfAzmoonDaneshjooNomreDarsad() + " %"
        horizontalAlignment: Text.AlignLeft


    }




    Text {
        id: text1
        x: 121
        y: 197
        width: 359
        height: 32
        text: qsTr("دانشجو هنوز در این آزمون شرکت نکرده است")
        font.pixelSize: 19
        visible: MyHandler.getKarnameOfAzmoonDaneshjooSize() > 0 ? false : true
    }

    Button {
        id: button
        x: 519
        y: 342
        text: qsTr("بازگشت")

        Connections {
            target: button
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



            }
        }
    }

}


