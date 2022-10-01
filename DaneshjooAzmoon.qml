import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQml 2.12

Page {
    width: 600
    height: 400

    title: qsTr("آزمون")

    Connections {
        target: MyHandler
        onEmptyExam: {
            label.text = "آزمونی وجود ندارد بعدا امتحان کنید"
            radioButton.visible = false
            radioButton1.visible = false
            radioButton2.visible = false
            radioButton3.visible = false

        }
        onFirstSoual: {
            label.text = MyHandler.getMatnSoual()
            radioButton.text = MyHandler.getG1()
            radioButton1.text = MyHandler.getG2()
            radioButton2.text = MyHandler.getG3()
            radioButton3.text = MyHandler.getG4()
            radioButton.visible = true
            radioButton1.visible = true
            radioButton2.visible = true
            radioButton3.visible = true
            button2.visible = false
            button.visible = false
        }
        onNextsoualD: {
            label.text = MyHandler.getMatnSoual()
            radioButton.text = MyHandler.getG1()
            radioButton1.text = MyHandler.getG2()
            radioButton2.text = MyHandler.getG3()
            radioButton3.text = MyHandler.getG4()
            radioButton.visible = true
            radioButton1.visible = true
            radioButton2.visible = true
            radioButton3.visible = true
            radioButton.checked = false
            radioButton1.checked = false
            radioButton2.checked = false
            radioButton3.checked = false

            button2.visible = true
        }
        onPresoualD: {
            label.text = MyHandler.getMatnSoual()
            radioButton.text = MyHandler.getG1()
            radioButton1.text = MyHandler.getG2()
            radioButton2.text = MyHandler.getG3()
            radioButton3.text = MyHandler.getG4()
            radioButton.visible = true
            radioButton1.visible = true
            radioButton2.visible = true
            radioButton3.visible = true
            radioButton.checked = false
            radioButton1.checked = false
            radioButton2.checked = false
            radioButton3.checked = false

            button1.visible = true
        }
        onEtmamSoualat: {
            button1.visible = false
            button.visible = true
        }
        onEtmamSoualatAzChap:{
            button2.visible = false
        }
    }



    Label {
        id: label
        x: 75
        y: 33
        width: 460
        height: 66
        text: qsTr("Label")
        horizontalAlignment: Text.AlignRight

        Connections {
            target: label

        }
    }

    RadioButton {
        id: radioButton
        LayoutMirroring.enabled: true
        anchors.left: parent.left
        x: 411
        y: 105
        visible: true
        text: qsTr("Radio Button")
    }

    RadioButton {
        id: radioButton1
        anchors.left: parent.left
        LayoutMirroring.enabled: true
        x: 411
        y: 149
        text: qsTr("Radio Button")
    }

    RadioButton {
        id: radioButton2
        LayoutMirroring.enabled: true
        anchors.left: parent.left
        x: 411
        y: 193
        text: qsTr("Radio Button")
    }
    RadioButton {
        id: radioButton3
        LayoutMirroring.enabled: true
        anchors.left: parent.left
        x: 411
        y: 237
        text: qsTr("Radio Button")
    }



    Button {
        id: button
        x: 240
        y: 322
        visible: true
        text: qsTr("ارسال آزمون و پایان")
        flat: false

        Connections {
            target: button
            onClicked: {

                MyHandler.taeedVaPyanAzmoonD(Date().toString(),radioButton.checked,radioButton1.checked,radioButton2.checked,radioButton3.checked);
                stackView.push("Karname.qml")

            }
            //void nextSoualD(bool Goz1,bool Goz2,bool Goz3,bool Goz4);
            //void TaeedVaPyanAzmoonD(QString Time);
           // Q_INVOKABLE QString getMatnSoual();
        }
    }

    Button {
        id: button1
        x: 432
        y: 322
        text: qsTr("سوال بعدی")
        Connections {
            target: button1
            onClicked: MyHandler.nextSoualD(radioButton.checked,radioButton1.checked,radioButton2.checked,radioButton3.checked)
        }
    }

    Button {
        id: button2
        x: 75
        y: 322
        text: qsTr("سوال قبلی")
        Connections {
            target: button2
            onClicked: MyHandler.preSoualD()
        }
    }

}
