import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick 2.9
import QtQuick.Layouts 1.3


Page {
    width: 600
    height: 900

    title:  " کارنامه آزمون: "

    ScrollView
    {
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
        ScrollBar.horizontal.interactive: true
        ScrollBar.vertical.interactive: true


    Column{

        clip: true
        width: 600
        height: 200
        Repeater {

            model: MyHandler.getKarnameOfAzmoonDaneshjooSize()
            anchors.left: parent.left
            anchors.right: parent.right
            RowLayout{
                Label
                {

                    width: parent.width


                    text: MyHandler.getSoualOfAzmoon(index)


                }
                Label
                {

                    width: parent.width


                    text:MyHandler.getKarnameOfAzmoonDaneshjooJavab(index)


                }
            }

        }
    }

    Label
    {
        x: 16
        y: 765

        width: parent.width


        text:"نمره دانشجو :" + MyHandler.getKarnameOfAzmoonDaneshjooNomreKol() + " / " +MyHandler.getKarnameOfAzmoonDaneshjooNomreDaneshjoo()  + " = " + MyHandler.getKarnameOfAzmoonDaneshjooNomreDarsad() + " %"
        horizontalAlignment: Text.AlignLeft


    }



    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}
}
##^##*/
